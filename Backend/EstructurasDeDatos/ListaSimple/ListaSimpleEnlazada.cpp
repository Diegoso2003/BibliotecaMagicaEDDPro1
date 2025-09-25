//
// Created by rafael-cayax on 17/8/25.
//
#include "ListaSimpleEnlazada.h"
#include <iostream>

#include "../../Libro/Libro.h"

ListaSimpleEnlazada::ListaSimpleEnlazada() {
    this->tamaño = 0;
    this->primero = nullptr;
}

ListaSimpleEnlazada::~ListaSimpleEnlazada() {
    delete primero;
}

bool ListaSimpleEnlazada::estaVacia() const {
    return tamaño == 0;
}

void ListaSimpleEnlazada::agregar(Libro *libro) {
    auto *nuevo = new NodoSimple(libro);
    if (estaVacia()) {
        primero = nuevo;
        tamaño++;
        return;
    }
    NodoSimple *aux = primero;
    while (aux->getSiguiente() != nullptr &&
           aux->getSiguiente()->getLibro()->getSinGuiones() < libro->getSinGuiones()) {
        aux = aux->getSiguiente();
    }
    tamaño++;
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

Libro *ListaSimpleEnlazada::eliminar(const std::string &isbn) {
    if (estaVacia()) return nullptr;
    Libro* libro = nullptr;
    if (primero->getLibro()->getSinGuiones() == isbn) {
        primero = obtenerLibro(primero, libro);
        tamaño--;
        return libro;
    }
    NodoSimple *aux = primero;
    while (aux->getSiguiente() != nullptr &&
        aux->getSiguiente()->getLibro()->getSinGuiones() < isbn) {
        aux = aux->getSiguiente();
    }
    if (aux->getSiguiente() == nullptr) return nullptr;
    if (aux->getSiguiente()->getLibro()->getSinGuiones() == isbn) {
        aux->setSiguiente(obtenerLibro(aux->getSiguiente(), libro));
        tamaño--;
        return libro;
    }
    return nullptr;
}

NodoSimple *ListaSimpleEnlazada::obtenerLibro(NodoSimple *nodo, Libro *&libro) {
    libro = nodo->getLibro();
    NodoSimple *aux = nodo->getSiguiente();
    delete nodo;
    return aux;
}

int ListaSimpleEnlazada::getTamaño() const {
    return tamaño;
}
