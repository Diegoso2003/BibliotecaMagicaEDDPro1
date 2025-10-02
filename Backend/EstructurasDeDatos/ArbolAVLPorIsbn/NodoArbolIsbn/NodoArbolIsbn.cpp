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

void NodoArbolIsbn::obtenerDotLibro(std::string &dot) {
    dot += R"( [label="ISBN: )" + libro->getIsbn() + R"(\n)";
    dot += R"(Titulo: )" + libro->getTitulo() + R"(\n)";
    dot += "Autor: " + libro->getAutor() + R"(\n)";
    dot += "Genero: " + libro->getGenero() + R"(\n)";
    dot += "Año Publicacion: " + std::to_string(libro->getAño()) + R"(\n)";
    dot += "Cantidad: " + std::to_string(libro->getCantidad()) + R"(\n)";
    dot += R"("];)"; dot += "\n";
}
