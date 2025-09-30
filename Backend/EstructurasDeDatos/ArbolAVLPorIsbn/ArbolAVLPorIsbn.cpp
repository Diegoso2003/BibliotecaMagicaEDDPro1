//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLPorIsbn.h"

#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../../Libro/Libro.h"
#include "../ArbolAVL/NodoArbolIsbn/NodoArbolIsbn.h"

bool ArbolAVLPorIsbn::agregarSubArbolIzquierdo(NodoArbol *&actual,Libro *&libro) {
    return libro->getSinGuiones() < actual->getLibro()->getSinGuiones();
}

NodoArbol * ArbolAVLPorIsbn::crearNuevoNodo(Libro *libro) {
    return new NodoArbolIsbn(libro);
}

void ArbolAVLPorIsbn::tratarLibroDuplicado(NodoArbol *nodo, Libro *&libro) {
    auto *nodoIsbn = dynamic_cast<NodoArbolIsbn *>(nodo);
    duplicado = !nodoIsbn->getLibro()->esLibroIgual(libro);
}

std::string ArbolAVLPorIsbn::obtenerDotArbol() {
    CreadorTextoDot creador;
    if (estaVacia()) throw EntradaUsuarioException("Arbol vacio, ingresar datos para crear grafica");
    return creador.obtenerDotPorIsbn(raiz);
}

bool ArbolAVLPorIsbn::agregarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) {
    return libro->getSinGuiones() > actual->getLibro()->getSinGuiones();
}
