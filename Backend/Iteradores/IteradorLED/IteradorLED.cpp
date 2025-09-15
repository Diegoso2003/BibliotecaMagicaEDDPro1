//
// Created by rafael-cayax on 20/8/25.
//

#ifndef PRACTICA1EDD_ITERADORLED_CPP
#define PRACTICA1EDD_ITERADORLED_CPP
#include "IteradorLED.h"
#include "../../EstructurasDeDatos/ListaSimple/NodoSimple.h"

template<typename T>
IteradorLED<T>::IteradorLED(NodoSimple<T> *actual) {
    this->actual = actual;
}

template<typename T>
T *IteradorLED<T>::getActual() {
    NodoSimple<T> *nodo = actual;
    actual = actual->getSiguiente();
    return nodo->getElemento();
}


#endif