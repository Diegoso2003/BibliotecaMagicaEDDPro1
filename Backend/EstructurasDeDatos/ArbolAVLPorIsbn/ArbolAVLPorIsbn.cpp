//
// Created by rafael-cayax on 19/9/25.
//

#include "ArbolAVLPorIsbn.h"

#include "../../AnalizadorLinea/AnalizadorLinea.h"
#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../../Libro/Libro.h"
#include "NodoArbolIsbn/NodoArbolIsbn.h"

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

void ArbolAVLPorIsbn::cambiarInformacion(NodoArbol *eliminar, NodoArbol *reemplazo) {
    auto *nodoEliminar = dynamic_cast<NodoArbolIsbn *>(eliminar);
    auto *nodoReemplazo = dynamic_cast<NodoArbolIsbn *>(reemplazo);
    Libro *libroAux = nodoEliminar->getLibro();
    nodoEliminar->setLibro(nodoReemplazo->getLibro());
    nodoReemplazo->setLibro(libroAux);
}

bool ArbolAVLPorIsbn::eliminarNodo(NodoArbol *nodo, Libro *libro) {
    auto nodoIsbn = dynamic_cast<NodoArbolIsbn *>(nodo);
    nodoIsbn->setLibro(nullptr);
    return true;
}

Libro * ArbolAVLPorIsbn::buscarLibro(const std::string &isbn) {
    if (estaVacia()) throw EntradaUsuarioException("Ingrese datos para realizar busqueda");
    AnalizadorLinea::validarIsbn(isbn);
    Libro libro;
    libro.setIsbn(isbn);
    NodoArbol *nodo = buscarNodo(raiz, &libro);
    if (nodo == nullptr) return nullptr;
    return nodo->getLibro();
}

bool ArbolAVLPorIsbn::visitarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) {
    return libro->getSinGuiones() > actual->getLibro()->getSinGuiones();
}
