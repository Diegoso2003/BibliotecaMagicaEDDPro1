//
// Created by rafael-cayax on 14/9/25.
//

#include "Libro.h"

#include "../Auxiliar/Auxiliar.h"

bool Libro::esLibroIgual(Libro *libro) {
    return libro != nullptr &&
           this->titulo == libro->titulo &&
           this->año == libro->año &&
           this->autor == libro->autor &&
           this->genero == libro->genero;
}

void Libro::setIsbn(const std::string &nuevoIsbn) {
    this->isbn = nuevoIsbn;
    this->isbnSinGuiones = Auxiliar::obtenerISBNSinGuion(isbn);
}
