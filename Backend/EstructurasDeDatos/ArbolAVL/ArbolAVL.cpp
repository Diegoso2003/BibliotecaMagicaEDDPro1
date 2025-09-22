//
// Created by rafael-cayax on 15/9/25.
//
#include "ArbolAVL.h"
#include "../../Libro/Libro.h"

#include "../../Excepciones/ElementoDuplicadoException.h"

void ArbolAVL::eliminarArbol(NodoArbol *actual) {
    if (actual != nullptr) {
        eliminarArbol(actual->getIzquierda());
        eliminarArbol(actual->getDerecha());
        Libro *libro = actual->getLibro();
        delete libro;
        delete actual;
    }
}

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

void ArbolAVL::agregarNuevoNodo(NodoArbol *&nodo,Libro *&nuevoLibro, bool &cambioAlturaArbol) {
    if (nodo != nullptr) {
        if (agregarSubArbolIzquierdo(nodo, nuevoLibro)) {
            agregarNuevoNodo(nodo->getIzquierda(), nuevoLibro, cambioAlturaArbol);
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
                        cambioAlturaArbol = false;
                }
            }
        } else if (agregarSubArbolDerecho(nodo, nuevoLibro)) {
            agregarNuevoNodo(nodo->getDerecha(), nuevoLibro, cambioAlturaArbol);
            if (cambioAlturaArbol) {
                switch (nodo->getFe()) {
                    case -1:
                        nodo->setFe(0);
                        cambioAlturaArbol = false;
                        break;
                    case 0:
                        nodo->setFe(1);
                        break;
                    default:
                        reorganizarArbolDerecho(nodo);
                        cambioAlturaArbol = false;
                }
            }
        } else {
            throw ElementoDuplicadoException("libro con isbn duplicado");
        }
    } else {
        nodo = new NodoArbol(nuevoLibro);
        cambioAlturaArbol = true;
    }
}

ArbolAVL::ArbolAVL() :  raiz(nullptr) {}

ArbolAVL::~ArbolAVL() {
    eliminarArbol(raiz);
}

void ArbolAVL::agregarLibro(Libro *libro) {
    bool cambioAlturaArbol = false;
    agregarNuevoNodo(raiz, libro, cambioAlturaArbol);
    elementos++;
}
