//
// Created by rafael-cayax on 30/9/25.
//

#include "NodoArbolTitulo.h"

#include "../../../Libro/Libro.h"
#include "../../ListaOrdenada/ListaOrdenada.h"

NodoArbolTitulo::NodoArbolTitulo(Libro *libro) {
    libros = new ListaOrdenada();
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

void NodoArbolTitulo::setLibros(ListaOrdenada *libros) {
    this->libros = libros;
}

void NodoArbolTitulo::obtenerDotLibro(std::string &dot) {
    bool esHoja = esNodoHoja();
    Libro *libro = this->getLibro();
    dot += R"( [label=" )";
    dot += esHoja ? "" : "<f0> |";
    dot += "Titulo:" + libro->getTitulo() + R"(\n)";
    dot += "Cantidad: " + std::to_string(this->getCantidad());
    dot += esHoja ? "" : "| <f1>";
    dot += R"("];)"; dot += "\n";
}
