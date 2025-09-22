//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLPorIsbn.h"

#include "../../Libro/Libro.h"

bool ArbolAVLPorIsbn::agregarSubArbolIzquierdo(NodoArbol *&actual,Libro *&libro) {
    return libro->getSinGuiones() < actual->getLibro()->getSinGuiones();
}

bool ArbolAVLPorIsbn::agregarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) {
    return libro->getSinGuiones() > actual->getLibro()->getSinGuiones();
}
