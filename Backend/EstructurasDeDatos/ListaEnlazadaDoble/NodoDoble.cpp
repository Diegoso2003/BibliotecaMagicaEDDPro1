//
// Created by rafael-cayax on 17/8/25.
//
#ifndef NODO_DOBLE_CPP
#define NODO_DOBLE_CPP

#include "NodoDoble.h"

template<typename T>
NodoDoble<T>::NodoDoble(T* elemento) {
    this->elemento = elemento;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

template<typename T>
void NodoDoble<T>::setAnterior(NodoDoble<T> *anterior) {
    this->anterior = anterior;
}

template<typename T>
void NodoDoble<T>::setSiguiente(NodoDoble<T> *siguiente) {
    this->siguiente = siguiente;
}

template<typename T>
NodoDoble<T> *NodoDoble<T>::getAnterior() {
    return this->anterior;
}

template<typename T>
NodoDoble<T> *NodoDoble<T>::getSiguiente() {
    return this->siguiente;
}

template<typename T>
T* NodoDoble<T>::getElemento() {
    return this->elemento;
}

#endif
