//
// Created by rafael-cayax on 22/9/25.
//

#include "ArbolBFecha.h"

#include <iostream>

#include "../../Libro/Libro.h"
#include "../ListaSimple/ListaSimpleEnlazada.h"

void ArbolBFecha::agregarElemento(NodoArbolB *nodo, Libro *&nuevoLibro) {
    if (nodo->esNodoHoja()) {
        nodo->agregarClave(nuevoLibro);
        std::cout << "libro agregado: " + nuevoLibro->getIsbn() << std::endl;
        return;
    }
    ListaSimpleEnlazada **libros = nodo->getClaves();
    NodoArbolB **hijos = nodo->getHijos();
    int i;
    for (i = 0; i < maxHijosNodo; i++) {
        if (libros[i] != nullptr && nuevoLibro->getAño() == libros[i]->getPrimero()->getAño()) {
            libros[i]->agregar(nuevoLibro);
            return;
        }
        if (libros[i] == nullptr || nuevoLibro->getAño() < libros[i]->getPrimero()->getAño()) {
            break;
        }
    }
    agregarElemento(hijos[i], nuevoLibro);
    verificarDesborde(nodo, false, i);
}

void ArbolBFecha::verificarDesborde(NodoArbolB *nodo, bool esRaiz, int posicion) {
    if (esRaiz) {
        auto* nuevo = new NodoArbolB(ordenArbol);
        NodoArbolB **hijos = nuevo->getHijos();
        ListaSimpleEnlazada **claves = nuevo->getClaves();
        hijos[0] = this->raiz;
        hijos[1] = this->raiz->getNuevoDer();
        claves[0]= this->raiz->getMedio();
        raiz = nuevo;
        raiz->setNumeroHijos(2);
        raiz->setNumeroLibros(1);
        std::cout << "desborde raiz hecho"<< std::endl;
        return;
    }
    NodoArbolB *hijo = nodo->getHijos()[posicion];
    if (hijo->getNumeroLibros() > maxElemNodo) {
        nodo->agregarClaveDelHijo(hijo->getMedio(), hijo->getNuevoDer(), posicion);
    }
}

ArbolBFecha::ArbolBFecha() {
    raiz = new NodoArbolB(ordenArbol);
}

ArbolBFecha::~ArbolBFecha() {
    delete raiz;
}

void ArbolBFecha::agregarLibro(Libro *nuevoLibro) {
    agregarElemento(raiz, nuevoLibro);
    if (raiz->getNumeroLibros() > maxElemNodo) {
        verificarDesborde(raiz, true);
    }
}

Libro ** ArbolBFecha::librosPorAño(int año) {
    return nullptr;
}
