//
// Created by rafael-cayax on 14/9/25.
//

#include "Libro.h"

#include "../Auxiliar/Auxiliar.h"

void Libro::ordenarPorISBN() {
    ordenISBN = true;
    ordenTitulo = false;
}

void Libro::ordenarTitulo() {
    ordenISBN = false;
    ordenTitulo = true;
}

bool Libro::operator==(const Libro &other) const {
    if (ordenISBN) {
        return isbnSinGuiones == other.isbnSinGuiones;
    }
    if (ordenTitulo) {
        return titulo == other.titulo;
    }
    return false;
}

bool Libro::operator!=(const Libro &other) const {
    return !(*this == other);
}

bool Libro::operator<(const Libro &other) const {
    if (ordenISBN) {
        return isbnSinGuiones < other.isbnSinGuiones;
    }
    if (ordenTitulo) {
        return titulo < other.titulo;
    }
    return false;
}

bool Libro::operator>(const Libro &other) const {
    return other < *this;
}

bool Libro::operator>=(const Libro &other) const {
    return *this > other || *this == other;
}

bool Libro::operator<=(const Libro &other) const {
    return *this < other || *this == other;
}

void Libro::setIsbn(const std::string &nuevoIsbn) {
    this->isbn = nuevoIsbn;
    this->isbnSinGuiones = Auxiliar::obtenerISBNSinGuion(isbn);
}
