//
// Created by rafael-cayax on 17/8/25.
//
#ifndef NODO_DOBLE_CPP
#define NODO_DOBLE_CPP

#include "NodoSimple.h"

template<typename T>
NodoSimple<T>::NodoSimple(T* elemento) {
    this->elemento = elemento;
    this->siguiente = nullptr;
}

template<typename T>
void NodoSimple<T>::setSiguiente(NodoSimple<T> *siguiente) {
    this->siguiente = siguiente;
}

template<typename T>
NodoSimple<T> *NodoSimple<T>::getSiguiente() {
    return this->siguiente;
}

template<typename T>
T* NodoSimple<T>::getElemento() {
    return this->elemento;
}

#endif
