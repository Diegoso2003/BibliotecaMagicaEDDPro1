//
// Created by rafael-cayax on 22/9/25.
//

#include "ArbolBFecha.h"

#include "../../Libro/Libro.h"
#include "../ListaSimple/ListaSimpleEnlazada.h"

NodoArbolB * ArbolBFecha::agregarElemento(NodoArbolB *nodo, Libro *&nuevoLibro) {
    if (nodo->getNumeroHijos() == 0) {
        nodo->agregarClave(nuevoLibro);
        return nodo;
    }
    ListaSimpleEnlazada **libros = nodo->getClaves();
    NodoArbolB **hijos = nodo->getHijos();
    int i;
    for (i = 0; i < maxHijosNodo; i++) {
        if (libros[i] == nullptr || nuevoLibro->getAño() < libros[i]->getPrimero()->getAño()) {
            break;
        }
    }
    hijos[i] = agregarElemento(hijos[i], nuevoLibro);
    //metodo para verificar que no se ha excedido el limite de tamaño
    return nodo;
}

ArbolBFecha::ArbolBFecha() {
    raiz = new NodoArbolB(ordenArbol);
}

ArbolBFecha::~ArbolBFecha() {
    delete raiz;
}

void ArbolBFecha::agregarLibro(Libro *nuevoLibro) {
    raiz = agregarElemento(raiz, nuevoLibro);
    //metodo para verificar que no se ha excedido el limite de tamaño
}

Libro ** ArbolBFecha::librosPorAño(int año) {
    return nullptr;
}
