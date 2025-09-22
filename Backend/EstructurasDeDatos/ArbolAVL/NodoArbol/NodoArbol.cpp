//
// Created by rafael-cayax on 16/9/25.
//
#include "NodoArbol.h"

NodoArbol::NodoArbol(Libro *libro)  {
    this->libro = libro;
    this->izquierda = nullptr;
    this->derecha = nullptr;
}

void NodoArbol::setDerecha(NodoArbol *der) {
    this->derecha = der;
}

void NodoArbol::setIzquierda(NodoArbol *izq) {
    this->izquierda = izq;
}