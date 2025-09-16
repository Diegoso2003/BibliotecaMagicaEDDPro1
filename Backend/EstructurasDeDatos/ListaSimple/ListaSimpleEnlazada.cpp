//
// Created by rafael-cayax on 17/8/25.
//
#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_CPP
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_CPP
#include "ListaSimpleEnlazada.h"
#include <iostream>

template<typename T>
ListaSimpleEnlazada<T>::ListaSimpleEnlazada() {
    this->tamaño = 0;
    this->primero = nullptr;
}

template<typename T>
ListaSimpleEnlazada<T>::~ListaSimpleEnlazada() {
    if (!estaVacia()) {
        NodoSimple<T>* pivote = nullptr;
        do {
            pivote = primero->getSiguiente();
            T* elemento = primero->getElemento();
            if (elemento != nullptr) {
                delete primero;
            }
            primero = pivote;
        }while (pivote != nullptr);
    }
}

template<typename T>
bool ListaSimpleEnlazada<T>::estaVacia() const {
    return tamaño == 0;
}

template<typename T>
void ListaSimpleEnlazada<T>::agregar(T *elemento) {
    NodoSimple<T>* nuevoNodo = new NodoSimple<T>(elemento);
    if (estaVacia()) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        ultimo->setSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    tamaño++;
}

template<typename T>
NodoSimple<T> *ListaSimpleEnlazada<T>::obtenerDesdePrimero(int posicion) {
    NodoSimple<T>* pivote = primero;
    for (int i = 1; i < posicion; i++) {
        pivote = pivote->getSiguiente();
    }
    return pivote;
}

template<typename T>
NodoSimple<T> *ListaSimpleEnlazada<T>::obtenerNodo(int posicion) {
    if (!estaVacia() && posicion > 0 && posicion <= tamaño) {
        NodoSimple<T> *nodo = obtenerDesdePrimero(posicion);
        return nodo;
    }
    std::cout << "indice fuera de rango" << std::endl;
    return nullptr;
}

template<typename T>
T *ListaSimpleEnlazada<T>::obtener(int posicion) {
    NodoSimple<T>* nodo = obtenerNodo(posicion);
    return nodo == nullptr ? nullptr : nodo->getElemento();
}

template<typename T>
T *ListaSimpleEnlazada<T>::eliminar(int posicion) {
    NodoSimple<T>* nodo = obtenerNodo(posicion);
    if (nodo != nullptr) {
        NodoSimple<T>* anterior = obtenerNodo(posicion - 1);
        NodoSimple<T>* siguiente = nodo->getSiguiente();
        if (posicion == 1) {
            primero = siguiente;
        }
        if (posicion == tamaño) {
            ultimo = anterior;
        }
        if (anterior != nullptr) {
            anterior->setSiguiente(siguiente);
        }
        T* elemento = nodo->getElemento();
        delete nodo;
        nodo = nullptr;
        tamaño--;
        return elemento;
    }
    return nullptr;
}

template<typename T>
int ListaSimpleEnlazada<T>::getTamaño() const {
    return tamaño;
}

template<typename T>
IteradorLED<T> *ListaSimpleEnlazada<T>::getIterador() {
    return new IteradorLED<T>(primero);
}
#endif