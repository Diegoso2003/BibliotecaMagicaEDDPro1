//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLTitulo.h"

#include "../../Auxiliar/Auxiliar.h"
#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../../Libro/Libro.h"
#include "NodoArbolTitulo/NodoArbolTitulo.h"

bool ArbolAVLTitulo::visitarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) {
    return Auxiliar::textoMinuscula(libro->getTitulo())
    > Auxiliar::textoMinuscula(actual->getLibro()->getTitulo());
}

bool ArbolAVLTitulo::visitarSubArbolIzquierdo(NodoArbol *&actual, Libro *&libro) {
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

ListaSimpleEnlazada * ArbolAVLTitulo::getLibrosPorTitulo(const std::string &titulo) {
    if (titulo.empty()) throw EntradaUsuarioException("Ingrese un titulo valido");
    Libro libro;
    libro.setTitulo(titulo);
    auto *nodoTitulo = dynamic_cast<NodoArbolTitulo *>(buscarNodo(raiz, &libro));
    if (nodoTitulo == nullptr) return nullptr;
    return nodoTitulo->getLibros();
}
