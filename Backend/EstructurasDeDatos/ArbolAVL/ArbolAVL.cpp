//
// Created by rafael-cayax on 15/9/25.
//
#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_CPP
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_CPP
#include "ArbolAVL.h"

#include "../../Excepciones/ElementoDuplicadoException.h"

template<typename T>
void ArbolAVL<T>::reorganizarArbolDerecho(NodoArbol<T> *&nodo) {
    NodoArbol<T>* nodo1 = nodo->getDerecha();
    NodoArbol<T>* nodo2 = nullptr;
    if (nodo1->getFe() >= 0) {
        nodo->setDerecha(nodo1->getIzquierda());
        nodo1->setIzquierda(nodo);
        nodo->setFe(0);
        nodo = nodo1;
    } else {
        nodo2 = nodo1->getIzquierda();
        nodo->setDerecha(nodo2->getIzquierda());
        nodo2->setIzquierda(nodo);
        nodo1->setIzquierda(nodo2->getDerecha());
        nodo2->setDerecha(nodo1);
        if (nodo2->getFe() == 1) {
            nodo->setFe(-1);
        } else {
            nodo->setFe(0);
        }
        if (nodo2->getFe() == -1) {
            nodo1->setFe(1);
        } else {
            nodo1->setFe(0);
        }
        nodo = nodo2;
    }
}

template<typename T>
void ArbolAVL<T>::reorganizarArbolIzquierdo(NodoArbol<T> *&nodo) {
    NodoArbol<T>* nodo1 = nodo->getIzquierda();
    NodoArbol<T>* nodo2 = nullptr;
    if (nodo1->getFe() <= 0) {
        nodo->setIzquierda(nodo1->getDerecha());
        nodo1->setDerecha(nodo);
        nodo->setFe(0);
        nodo = nodo1;
    } else {
        nodo2 = nodo1->getDerecha();
        nodo->setIzquierda(nodo2->getDerecha());
        nodo2->setDerecha(nodo);
        nodo1->setDerecha(nodo2->getIzquierda());
        nodo2->setIzquierda(nodo1);
        if (nodo2->getFe() == -1) {
            nodo->setFe(1);
        } else {
            nodo->setFe(0);
        }
        if (nodo2->getFe() == 1) {
            nodo1->setFe(-1);
        } else {
            nodo1->setFe(0);
        }
        nodo = nodo2;
    }
}

template<typename T>
void ArbolAVL<T>::agregarNuevoNodo(NodoArbol<T> *&nodo,T *&nuevoElemento, bool &cambioAlturaArbol) {
    if (nodo != nullptr) {
        if (*nuevoElemento < *nodo->getElemento()) {
            agregarNuevoNodo(nodo->getIzquierda(), nuevoElemento, cambioAlturaArbol);
            if (cambioAlturaArbol) {
                switch (nodo->getFe()) {
                    case 1:
                        nodo->setFe(0);
                        cambioAlturaArbol = false;
                        break;
                    case 0:
                        nodo->setFe(-1);
                        break;
                    default:
                        reorganizarArbolIzquierdo(nodo);
                        nodo->setFe(0);
                        cambioAlturaArbol = false;
                }
            }
        } else if (*nuevoElemento > *nodo->getElemento()) {
            agregarNuevoNodo(nodo->getDerecha(), nuevoElemento, cambioAlturaArbol);
            if (cambioAlturaArbol) {
                switch (nodo->getFe()) {
                    case -1:
                        nodo->setFe(0);
                        break;
                    case 0:
                        nodo->setFe(1);
                        break;
                    default:
                        reorganizarArbolDerecho(nodo);
                        nodo->setFe(0);
                        cambioAlturaArbol = false;
                }
            }
        } else {
            throw ElementoDuplicadoException("libro con isbn duplicado");
        }
    } else {
        nodo = new NodoArbol<T>(nuevoElemento);
        cambioAlturaArbol = true;
    }
}

template<typename T>
ArbolAVL<T>::ArbolAVL(bool duplicados) : duplicados(duplicados), raiz(nullptr) {
}

template<typename T>
void ArbolAVL<T>::agregarElemento(T *elemento) {
    if (this->estaVacia()) {
        auto* nuevoNodo = new NodoArbol<T>(elemento);
        raiz = nuevoNodo;
        elementos++;
        return;
    }
    bool cambioAlturaArbol = false;
    agregarNuevoNodo(raiz, elemento, cambioAlturaArbol);
    elementos++;
}
#endif
