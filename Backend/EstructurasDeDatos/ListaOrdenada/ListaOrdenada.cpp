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

    if (libro->getSinGuiones() < primero->getLibro()->getSinGuiones()) {
        primero->setAnterior(nuevo);
        nuevo->setSiguiente(primero);
        primero = nuevo;
        tamaño++;
        return;
    }

    if (libro->getSinGuiones() > ultimo->getLibro()->getSinGuiones()) {
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

Libro *ListaOrdenada::eliminar(const std::string &isbn) {
    Libro *libro = nullptr;
    return libro;
}

Libro * ListaOrdenada::getPrimero() {
    return !estaVacia() ? primero->getLibro(): nullptr;
}

/**NodoSimple *ListaOrdenada::eliminarNodo(const std::string &isbn, Libro *&libro, NodoSimple *nodo) {
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
}**/

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