//
// Created by rafael-cayax on 16/9/25.
//
#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_CPP
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_CPP
#include "NodoArbol.h"

template<typename T>
NodoArbol<T>::NodoArbol(T *elemento)  {
    this->elemento = elemento;
    this->izquierda = nullptr;
    this->derecha = nullptr;
}

template<typename T>
void NodoArbol<T>::setDerecha(NodoArbol<T> *der) {
    this->derecha = der;
}

template<typename T>
void NodoArbol<T>::setIzquierda(NodoArbol<T> *izq) {
    this->izquierda = izq;
}

#endif