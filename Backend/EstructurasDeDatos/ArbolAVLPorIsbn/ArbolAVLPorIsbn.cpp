//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLPorIsbn.h"

#include "../../AnalizadorLinea/AnalizadorLinea.h"
#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../../Libro/Libro.h"
#include "../ArbolAVL/NodoArbolIsbn/NodoArbolIsbn.h"

bool ArbolAVLPorIsbn::visitarSubArbolIzquierdo(NodoArbol *&actual,Libro *&libro) {
    return libro->getSinGuiones() < actual->getLibro()->getSinGuiones();
}

NodoArbol * ArbolAVLPorIsbn::crearNuevoNodo(Libro *libro) {
    return new NodoArbolIsbn(libro);
}

void ArbolAVLPorIsbn::tratarLibroDuplicado(NodoArbol *nodo, Libro *&libro) {
    auto *nodoIsbn = dynamic_cast<NodoArbolIsbn *>(nodo);
    duplicado = !nodoIsbn->getLibro()->esLibroIgual(libro);
    if (!duplicado) nodoIsbn->getLibro()->aumentarCantidad();
    agregarDemasArboles = false;
}

std::string ArbolAVLPorIsbn::obtenerDotArbol() {
    CreadorTextoDot creador;
    if (estaVacia()) throw EntradaUsuarioException("Arbol vacio, ingresar datos para crear grafica");
    return creador.obtenerDotPorIsbn(raiz);
}

Libro * ArbolAVLPorIsbn::buscarLibro(std::string isbn) {
    AnalizadorLinea::validarIsbn(isbn);
    auto *libro = new Libro();
    libro->setIsbn(isbn);
    NodoArbol *nodo = buscarNodo(raiz, libro);
    if (nodo == nullptr) return nullptr;
    return nodo->getLibro();
}

bool ArbolAVLPorIsbn::visitarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) {
    return libro->getSinGuiones() > actual->getLibro()->getSinGuiones();
}
