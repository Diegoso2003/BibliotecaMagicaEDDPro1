//
// Created by rafael-cayax on 17/8/25.
//
#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_CPP
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_CPP
#include "ListaDobleEnlazada.h"
#include <iostream>

template<typename T>
ListaDobleEnlazada<T>::ListaDobleEnlazada() {
    this->tamaño = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
}

template<typename T>
ListaDobleEnlazada<T>::~ListaDobleEnlazada() {
    if (!estaVacia()) {
        NodoDoble<T>* pivote = nullptr;
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
bool ListaDobleEnlazada<T>::estaVacia() const {
    return tamaño == 0;
}

template<typename T>
void ListaDobleEnlazada<T>::agregar(T *elemento) {
    NodoDoble<T>* nuevoNodo = new NodoDoble<T>(elemento);
    if (estaVacia()) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        ultimo->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(ultimo);
        ultimo = nuevoNodo;
    }
    tamaño++;
}

template<typename T>
NodoDoble<T> *ListaDobleEnlazada<T>::obtenerDesdePrimero(int posicion) {
    NodoDoble<T>* pivote = primero;
    for (int i = 1; i < posicion; i++) {
        pivote = pivote->getSiguiente();
    }
    return pivote;
}

template<typename T>
NodoDoble<T> *ListaDobleEnlazada<T>::obtenerDesdeUltimo(int posicion) {
    NodoDoble<T>* pivote = ultimo;
    for (int i = tamaño; i > posicion; i--) {
        pivote = pivote->getAnterior();
    }
    return pivote;
}

template<typename T>
NodoDoble<T> *ListaDobleEnlazada<T>::obtenerNodo(int posicion) {
    if (!estaVacia() && posicion > 0 && posicion <= tamaño) {
        int mitadTamaño = tamaño / 2;
        NodoDoble<T> *nodo = posicion > mitadTamaño ? obtenerDesdeUltimo(posicion) :
        obtenerDesdePrimero(posicion);
        return nodo;
    }
    std::cout << "indice fuera de rango" << std::endl;
    return nullptr;
}

template<typename T>
T *ListaDobleEnlazada<T>::obtener(int posicion) {
    NodoDoble<T>* nodo = obtenerNodo(posicion);
    return nodo == nullptr ? nullptr : nodo->getElemento();
}

template<typename T>
T *ListaDobleEnlazada<T>::eliminar(int posicion) {
    NodoDoble<T>* nodo = obtenerNodo(posicion);
    if (nodo != nullptr) {
        NodoDoble<T>* anterior = nodo->getAnterior();
        NodoDoble<T>* siguiente = nodo->getSiguiente();
        if (posicion == 1) {
            primero = siguiente;
        }
        if (posicion == tamaño) {
            ultimo = anterior;
        }
        if (anterior != nullptr) {
            anterior->setSiguiente(siguiente);
        }
        if (siguiente != nullptr) {
            siguiente->setAnterior(anterior);
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
int ListaDobleEnlazada<T>::getTamaño() const {
    return tamaño;
}

template<typename T>
IteradorLED<T> *ListaDobleEnlazada<T>::getIterador() {
    return new IteradorLED<T>(primero);
}

template<typename T>
void ListaDobleEnlazada<T>::agregarPrimero(T *elemento) {
    NodoDoble<T> *nodo = new NodoDoble<T>(elemento);
    if (!estaVacia()) {
        primero -> setAnterior(nodo);
        nodo->setSiguiente(primero);
    }
    primero = nodo;
}


#endif