//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLTitulo.h"

#include "../../Auxiliar/Auxiliar.h"
#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../../Libro/Libro.h"
#include "../ArbolAVL/NodoArbolTitulo/NodoArbolTitulo.h"

bool ArbolAVLTitulo::agregarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) {
    return Auxiliar::textoMinuscula(libro->getTitulo())
    > Auxiliar::textoMinuscula(actual->getLibro()->getTitulo());
}

bool ArbolAVLTitulo::agregarSubArbolIzquierdo(NodoArbol *&actual, Libro *&libro) {
    return Auxiliar::textoMinuscula(libro->getTitulo()) <
        Auxiliar::textoMinuscula(actual->getLibro()->getTitulo());
}

NodoArbol * ArbolAVLTitulo::crearNuevoNodo(Libro *libro) {
    return new NodoArbolTitulo(libro);
}

void ArbolAVLTitulo::tratarLibroDuplicado(NodoArbol *nodo, Libro *&libro) {
    auto *nodoTitulo = dynamic_cast<NodoArbolTitulo *>(nodo);
    nodoTitulo->agregarLibro(libro);
}

std::string ArbolAVLTitulo::obtenerDotArbol() {
    CreadorTextoDot creador;
    if (estaVacia()) throw EntradaUsuarioException("Arbol vacio, ingresar datos para crear grafica");
    return creador.obtenerDotPorTitulo(raiz);
}
