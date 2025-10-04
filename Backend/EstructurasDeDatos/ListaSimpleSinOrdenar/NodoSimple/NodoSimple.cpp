//
// Created by rafael-cayax on 17/8/25.
//
#include "NodoSimple.h"
NodoSimple::NodoSimple(Libro* libro) {
    this->libro = libro;
    this->siguiente = nullptr;
}

NodoSimple::~NodoSimple() {
    delete siguiente;
}

void NodoSimple::setSiguiente(NodoSimple *siguiente) {
    this->siguiente = siguiente;
}

NodoSimple *NodoSimple::getSiguiente() {
    return this->siguiente;
}

Libro* NodoSimple::getLibro() {
    return this->libro;
}