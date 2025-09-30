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
