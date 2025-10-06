//
// Created by rafael-cayax on 17/8/25.
//
#include "ListaOrdenada.h"

#include "../../Iteradores/IteradorListaSimple.h"
#include "../../Libro/Libro.h"
#include "NodoDoble/NodoDoble.h"

ListaOrdenada::ListaOrdenada() {
    this->tamaño = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ListaOrdenada::~ListaOrdenada() {
    delete primero;
}

bool ListaOrdenada::estaVacia() const {
    return tamaño == 0;
}

void ListaOrdenada::agregar(Libro *libro) {
    auto *nuevo = new NodoDoble(libro);
    if (estaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
        tamaño++;
        return;
    }

    if (libro->getSinGuiones() <= primero->getLibro()->getSinGuiones()) {
        primero->setAnterior(nuevo);
        nuevo->setSiguiente(primero);
        primero = nuevo;
        tamaño++;
        return;
    }

    if (libro->getSinGuiones() >= ultimo->getLibro()->getSinGuiones()) {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
        tamaño++;
        return;
    }
    if (debeBuscarAlPrincipio(libro->getSinGuiones())) {
        buscarDesdePrincipio(nuevo);
    } else {
        buscarDesdeFinal(nuevo);
    }
    tamaño++;
}

void ListaOrdenada::eliminar(const std::string &isbn) {
    if (primero->getLibro()->getSinGuiones() == isbn) {
        NodoSimple *aux = primero;
        primero = primero->getSiguiente();
        aux->setSiguiente(nullptr);
        delete aux;
        tamaño--;
        return;
    }

    if (ultimo->getLibro()->getSinGuiones() == isbn) {
        NodoSimple *aux = ultimo;
        ultimo = ultimo->getAnterior();
        ultimo->setSiguiente(nullptr);
        delete aux;
        tamaño--;
        return;
    }
    NodoDoble *posicion = nullptr;
    if (debeBuscarAlPrincipio(isbn)) {
        posicion = eliminarDesdePrincipio(isbn);
    } else {
        posicion = eliminarDesdeFinal(isbn);
    }
    posicion->getSiguiente()->setAnterior(posicion->getAnterior());
    posicion->getAnterior()->setSiguiente(posicion->getSiguiente());
    posicion->setSiguiente(nullptr);
    delete posicion;
    tamaño--;
}

Libro * ListaOrdenada::getPrimero() {
    return !estaVacia() ? primero->getLibro(): nullptr;
}

int ListaOrdenada::getTamaño() const {
    return tamaño;
}

IteradorListaSimple ListaOrdenada::getIterator() {
    return IteradorListaSimple(primero);
}

bool ListaOrdenada::debeBuscarAlPrincipio(const std::string& nuevoDato) {
    int distAPrimero = std::abs(nuevoDato.compare(primero->getLibro()->getSinGuiones()));
    int distAUltimo = std::abs(nuevoDato.compare(ultimo->getLibro()->getSinGuiones()));
    return distAPrimero <= distAUltimo;
}

void ListaOrdenada::buscarDesdePrincipio(NodoDoble *nuevo) {
    NodoDoble* actual = primero;
    const std::string &dato = nuevo->getLibro()->getSinGuiones();
    while (dato > actual->getLibro()->getSinGuiones()) {
        actual = actual->getSiguiente();
    }
    nuevo->setSiguiente(actual);
    nuevo->setAnterior(actual->getAnterior());
    actual->getAnterior()->setSiguiente(nuevo);
    actual->setAnterior(nuevo);
}

void ListaOrdenada::buscarDesdeFinal(NodoDoble *nuevo) {
    NodoDoble* actual = ultimo;
    const std::string &dato = nuevo->getLibro()->getSinGuiones();
    while (dato < actual->getLibro()->getSinGuiones()) {
        actual = actual->getAnterior();
    }
    nuevo->setSiguiente(actual->getSiguiente());
    nuevo->setAnterior(actual);
    actual->getSiguiente()->setAnterior(nuevo);
    actual->setSiguiente(nuevo);
}

NodoDoble* ListaOrdenada::eliminarDesdePrincipio(const std::string &isbn) {
    NodoDoble *actual = primero;
    while (isbn != actual->getLibro()->getSinGuiones()) {
        actual = actual->getSiguiente();
    }
    return actual;
}

NodoDoble * ListaOrdenada::eliminarDesdeFinal(const std::string &isbn) {
    NodoDoble *actual = ultimo;
    while (isbn != actual->getLibro()->getSinGuiones()) {
        actual = actual->getAnterior();
    }
    return actual;
}