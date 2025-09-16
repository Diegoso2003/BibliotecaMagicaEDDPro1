//
// Created by rafael-cayax on 20/8/25.
//

#ifndef PRACTICA1EDD_ITERADORLED_CPP
#define PRACTICA1EDD_ITERADORLED_CPP
#include "IteradorLED.h"
#include "../../EstructurasDeDatos/ListaSimple/NodoSimple/NodoSimple.h"

template<typename T>
IteradorLED<T>::IteradorLED(NodoSimple<T> *actual) {
    this->actual = actual;
}

template<typename T>
bool IteradorLED<T>::haySiguiente() {
    actual = actual->getSiguiente();
    return actual != nullptr;
}

template<typename T>
T *IteradorLED<T>::getActual() {
    return actual != nullptr ? actual->getElemento(): nullptr;
}


#endif