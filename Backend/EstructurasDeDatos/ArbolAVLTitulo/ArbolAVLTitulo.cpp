//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLTitulo.h"

#include "../../Libro/Libro.h"

bool ArbolAVLTitulo::agregarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) {
    return libro->getTitulo() >= actual->getLibro()->getTitulo();
}

bool ArbolAVLTitulo::agregarSubArbolIzquierdo(NodoArbol *&actual, Libro *&libro) {
    return libro->getTitulo() < actual->getLibro()->getTitulo();
}
