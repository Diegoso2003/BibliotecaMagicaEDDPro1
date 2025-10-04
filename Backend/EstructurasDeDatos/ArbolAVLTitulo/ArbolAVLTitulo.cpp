//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLTitulo.h"

#include "../../Auxiliar/Auxiliar.h"
#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../../Libro/Libro.h"
#include "../ListaOrdenada/ListaOrdenada.h"
#include "../ListaSimpleSinOrdenar/ListaSimpleSinOrdenar.h"
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

void ArbolAVLTitulo::agregarOrdenAlfabetico(NodoArbolTitulo *nodo, ListaSimpleSinOrdenar *lista) {
    if (nodo == nullptr) return;
    agregarOrdenAlfabetico(dynamic_cast<NodoArbolTitulo *>(nodo->getIzquierda()), lista);
    lista->copiarLista(nodo->getLibros());
    agregarOrdenAlfabetico(dynamic_cast<NodoArbolTitulo *>(nodo->getDerecha()), lista);
}

ListaOrdenada * ArbolAVLTitulo::buscarLibrosPorTitulo(std::string &titulo) {
    if (titulo.empty()) throw EntradaUsuarioException("Ingrese un titulo valido");
    if (estaVacia()) throw EntradaUsuarioException("Ingrese datos para realizar busqueda");
    Libro libro;
    Auxiliar::eliminarEspaciosIntermedio(titulo);
    libro.setTitulo(titulo);
    auto *nodoTitulo = dynamic_cast<NodoArbolTitulo *>(buscarNodo(raiz, &libro));
    if (nodoTitulo == nullptr) return nullptr;
    return nodoTitulo->getLibros();
}

ListaSimpleSinOrdenar *ArbolAVLTitulo::listarLibrosEnOrden() {
    auto *lista = new ListaSimpleSinOrdenar();
    agregarOrdenAlfabetico(dynamic_cast<NodoArbolTitulo *>(raiz), lista);
    return lista;
}
