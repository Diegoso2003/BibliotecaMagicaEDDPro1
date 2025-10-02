//
// Created by rafael-cayax on 30/9/25.
//

#include "NodoArbolTitulo.h"

#include "../../../Libro/Libro.h"
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

void NodoArbolTitulo::obtenerDotLibro(std::string &dot) {
    Libro *libro = this->getLibro();
    dot += R"( [label="Titulo: )" + libro->getTitulo() + R"(\n)";
    dot += "Cantidad: " + std::to_string(this->getCantidad()) + R"(\n)";
    dot += R"("];)"; dot += "\n";
}
