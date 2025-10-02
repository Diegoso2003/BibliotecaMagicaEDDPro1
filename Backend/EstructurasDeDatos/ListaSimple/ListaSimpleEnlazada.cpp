//
// Created by rafael-cayax on 17/8/25.
//
#include "ListaSimpleEnlazada.h"
#include <iostream>

#include "../../Iteradores/IteradorListaSimple.h"
#include "../../Libro/Libro.h"

ListaSimpleEnlazada::ListaSimpleEnlazada() {
    this->tamaño = 0;
    this->primero = nullptr;
    this->primero = nullptr;
}

ListaSimpleEnlazada::~ListaSimpleEnlazada() {
    if (this->eliminarNodos) {
        delete primero;
    }
}

ListaSimpleEnlazada::ListaSimpleEnlazada(ListaSimpleEnlazada *copia) {
    eliminarNodos = false;
    primero = copia->primero;
    ultimo = copia->ultimo;
    tamaño = copia->tamaño;
}

bool ListaSimpleEnlazada::estaVacia() const {
    return tamaño == 0;
}

void ListaSimpleEnlazada::agregar(Libro *libro) {
    auto *nuevo = new NodoSimple(libro);
    if (estaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
        tamaño++;
        return;
    }
    NodoSimple *aux = primero;
    while (aux->getSiguiente() != nullptr &&
           aux->getSiguiente()->getLibro()->getSinGuiones() < libro->getSinGuiones()) {
        aux = aux->getSiguiente();
    }
    actualizarPosicionUltimo();
    tamaño++;
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

void ListaSimpleEnlazada::agregarLista(ListaSimpleEnlazada *copia) {
    ultimo->setSiguiente(copia->primero);
    ultimo = copia->ultimo;
    tamaño += copia->tamaño;
}

Libro *ListaSimpleEnlazada::eliminar(const std::string &isbn) {
    Libro* libro = nullptr;
    primero = eliminarNodo(isbn, libro, primero);
    if (libro != nullptr) tamaño--;
    return libro;
}


void ListaSimpleEnlazada::actualizarPosicionUltimo() {
    while (ultimo->getSiguiente() != nullptr) {
        ultimo = ultimo->getSiguiente();
    }
}

NodoSimple *ListaSimpleEnlazada::eliminarNodo(const std::string &isbn, Libro *&libro, NodoSimple *nodo) {
    if (nodo == nullptr) return nullptr;
    if (isbn == nodo->getLibro()->getSinGuiones()) {
        libro = nodo->getLibro();
        NodoSimple *aux = nodo->getSiguiente();
        nodo->setSiguiente(nullptr);
        delete nodo;
        return aux;
    }
    nodo->setSiguiente(eliminarNodo(isbn, libro, nodo->getSiguiente()));
    if (nodo->getSiguiente() == nullptr) ultimo = nodo;
    return nodo;
}

int ListaSimpleEnlazada::getTamaño() const {
    return tamaño;
}

IteradorListaSimple ListaSimpleEnlazada::getIterator() {
    return IteradorListaSimple(primero);
}
