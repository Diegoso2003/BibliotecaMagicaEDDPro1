//
// Created by rafael-cayax on 30/9/25.
//

#include "NodoArbolIsbn.h"
#include "../../../Libro/Libro.h"

NodoArbolIsbn::NodoArbolIsbn(Libro *libro) {
    this->libro = libro;
}

NodoArbolIsbn::~NodoArbolIsbn() {
    delete izquierda;
    delete derecha;
    delete libro;
}

Libro * NodoArbolIsbn::getLibro() const {
    return libro;
}

void NodoArbolIsbn::setLibro(Libro *libro) {
    this->libro = libro;
}

void NodoArbolIsbn::obtenerDotLibro(std::string &dot) {
    bool esHoja = esNodoHoja();
    dot += R"( [label=")";
    dot += esHoja ? "" : "<f0> |";
    dot += "ISBN:" + libro->getIsbn() + R"(\n)";
    dot += "Copias: " + std::to_string(libro->getCantidad());
    dot += esHoja ? "" : "| <f1>";
    dot += R"("];)"; dot += "\n";
}
