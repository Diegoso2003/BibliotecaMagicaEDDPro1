//
// Created by rafael-cayax on 15/9/25.
//
#include "ArbolAVL.h"
#include "../../Libro/Libro.h"

#include "../../Excepciones/ElementoDuplicadoException.h"

void ArbolAVL::reorganizarArbolDerecho(NodoArbol *&nodo) {
    NodoArbol* nodo1 = nodo->getDerecha();
    NodoArbol* nodo2 = nullptr;
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
    nodo->setFe(0);
}

void ArbolAVL::reorganizarArbolIzquierdo(NodoArbol *&nodo) {
    NodoArbol* nodo1 = nodo->getIzquierda();
    NodoArbol* nodo2 = nullptr;
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
    nodo->setFe(0);
}

NodoArbol* ArbolAVL::agregarNuevoNodo(NodoArbol *nodo,Libro *&nuevoLibro, bool &verificarFeSubArbol) {
    if (nodo != nullptr) {
        if (agregarSubArbolIzquierdo(nodo, nuevoLibro)) {
            nodo->setIzquierda(agregarNuevoNodo(nodo->getIzquierda(), nuevoLibro, verificarFeSubArbol));
            if (verificarFeSubArbol) {
                switch (nodo->getFe()) {
                    case 1:
                        nodo->setFe(0);
                        verificarFeSubArbol = false;
                        break;
                    case 0:
                        nodo->setFe(-1);
                        break;
                    default:
                        reorganizarArbolIzquierdo(nodo);
                        verificarFeSubArbol = false;
                }
            }
        } else if (agregarSubArbolDerecho(nodo, nuevoLibro)) {
            nodo->setDerecha(agregarNuevoNodo(nodo->getDerecha(), nuevoLibro, verificarFeSubArbol));
            if (verificarFeSubArbol) {
                switch (nodo->getFe()) {
                    case -1:
                        nodo->setFe(0);
                        verificarFeSubArbol = false;
                        break;
                    case 0:
                        nodo->setFe(1);
                        break;
                    default:
                        reorganizarArbolDerecho(nodo);
                        verificarFeSubArbol = false;
                }
            }
        } else {
            tratarLibroDuplicado(nodo, nuevoLibro);
        }
    } else {
        nodo = crearNuevoNodo(nuevoLibro);
        verificarFeSubArbol = true;
        elementos++;
    }
    return nodo;
}

ArbolAVL::ArbolAVL() :  raiz(nullptr) {}

ArbolAVL::~ArbolAVL() {
    delete raiz;
}

void ArbolAVL::agregarLibro(Libro *libro) {
    bool cambioAlturaArbol = false;
    duplicado = false;
    agregarDemasArboles = true;
    raiz = agregarNuevoNodo(raiz, libro, cambioAlturaArbol);
    if (duplicado) throw ElementoDuplicadoException("libro con isbn duplicado");
}
