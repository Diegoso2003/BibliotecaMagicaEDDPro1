//
// Created by rafael-cayax on 16/9/25.
//
#include "NodoArbol.h"

bool NodoArbol::esNodoHoja() {
    return derecha == nullptr && izquierda == nullptr;
}

void NodoArbol::setDerecha(NodoArbol *der) {
    this->derecha = der;
}

void NodoArbol::setIzquierda(NodoArbol *izq) {
    this->izquierda = izq;
}

int NodoArbol::getFe() {
    int alturaDerecha = derecha == nullptr ? 0 : derecha->getAltura();
    int alturaIzquierda = izquierda == nullptr ? 0 : izquierda->getAltura();
    return alturaDerecha - alturaIzquierda;
}

int NodoArbol::getAltura() {
    return altura;
}

void NodoArbol::recalcularAltura() {
    int alturaDerecha = derecha == nullptr ? 0 : derecha->getAltura();
    int alturaIzquierda = izquierda == nullptr ? 0 : izquierda->getAltura();
    altura = std::max(alturaDerecha, alturaIzquierda) + 1;
}