//
// Created by rafael-cayax on 15/9/25.
//
#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_CPP
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_CPP
#include "ArbolAVL.h"

#include "../../Excepciones/ElementoDuplicadoException.h"

template<typename T>
void ArbolAVL<T>::agregarNuevoNodo(NodoArbol<T> *&nodo, NodoArbol<T> *&nuevoNodo) {
    if (*nuevoNodo->getElemento() > *nodo->getElemento()) {
        if (nodo->getDerecha() == nullptr) {
            nodo->setDerecha(nuevoNodo);
            return;
        }
        agregarNuevoNodo(nodo->getDerecha(), nuevoNodo);
        return;
    }
    if (nodo->getIzquierda() == nullptr) {
        nodo->setIzquierda(nuevoNodo);
        return;
    }
    agregarNuevoNodo(nodo->getIzquierda(), nuevoNodo);
}

template<typename T>
ArbolAVL<T>::ArbolAVL(bool duplicados) : duplicados(duplicados), raiz(nullptr) {
}

template<typename T>
void ArbolAVL<T>::agregarElemento(T *elemento) {
    auto* nuevoNodo = new NodoArbol<T>(elemento);
    if (this->estaVacia()) {
        raiz = nuevoNodo;
        elementos++;
        return;
    }
    agregarNuevoNodo(raiz, nuevoNodo);
    elementos++;
}
#endif
