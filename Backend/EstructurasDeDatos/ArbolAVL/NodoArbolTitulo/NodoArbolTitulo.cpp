//
// Created by rafael-cayax on 30/9/25.
//

#include "NodoArbolTitulo.h"

#include "../../ListaSimple/ListaSimpleEnlazada.h"

NodoArbolTitulo::NodoArbolTitulo(Libro *libro) {
    libros = new ListaSimpleEnlazada();
    libros->agregar(libro);
}

NodoArbolTitulo::~NodoArbolTitulo() {
    delete izquierda;
    delete derecha;
    delete libros;
}

Libro * NodoArbolTitulo::getLibro() const {
    return libros->getPrimero();
}

int NodoArbolTitulo::getCantidad() {
    return libros->getTamaño();
}

void NodoArbolTitulo::agregarLibro(Libro *libro) {
    libros->agregar(libro);
}
