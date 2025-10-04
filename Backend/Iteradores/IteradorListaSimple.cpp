//
// Created by rafael-cayax on 30/9/25.
//

#include "IteradorListaSimple.h"

#include "../EstructurasDeDatos/ListaSimpleSinOrdenar/NodoSimple/NodoSimple.h"

IteradorListaSimple::IteradorListaSimple(NodoSimple *nodo) {
    auxiliar = nodo;
    actual = nullptr;
}

bool IteradorListaSimple::haySiguiente() {
    if (actual == nullptr) {
        actual = auxiliar;
        auxiliar = nullptr;
    } else {
        actual = actual->getSiguiente();
    }
    return actual != nullptr;
}

Libro * IteradorListaSimple::getActual() {
    return actual->getLibro();
}
