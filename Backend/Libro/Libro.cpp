//
// Created by rafael-cayax on 14/9/25.
//

#include "Libro.h"

#include "../Auxiliar/Auxiliar.h"

void Libro::setIsbn(const std::string &nuevoIsbn) {
    this->isbn = nuevoIsbn;
    this->isbnSinGuiones = Auxiliar::obtenerISBNSinGuion(isbn);
}
