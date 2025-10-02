//
// Created by rafael-cayax on 22/9/25.
//

#include "ArbolBFecha.h"


#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Libro/Libro.h"
#include "../ListaSimple/ListaSimpleEnlazada.h"

void ArbolBFecha::agregarElemento(NodoArbolB *nodo, Libro *&nuevoLibro) {
    if (nodo->esNodoHoja()) {
        nodo->agregarClave(nuevoLibro);
        return;
    }
    ListaSimpleEnlazada **libros = nodo->getClaves();
    NodoArbolB **hijos = nodo->getHijos();
    for (int i = 0; i <= nodo->getNumeroLibros(); i++) {
        if (libros[i] != nullptr && nuevoLibro->getAño() == libros[i]->getPrimero()->getAño()) {
            libros[i]->agregar(nuevoLibro);
            break;
        }
        if (libros[i] == nullptr || nuevoLibro->getAño() < libros[i]->getPrimero()->getAño()) {
            agregarElemento(hijos[i], nuevoLibro);
            if (hijos[i]->getNumeroLibros() > maxElemNodo) {
                nodo->dividirNodoHijo(i);
            }
            break;
        }
    }
}

void ArbolBFecha::DividirRaiz() {
    auto *nuevo = new NodoArbolB(ordenArbol);
    NodoArbolB **hijos = nuevo->getHijos();
    ListaSimpleEnlazada **claves = nuevo->getClaves();
    hijos[0] = this->raiz;
    hijos[1] = this->raiz->getNuevoDer();
    claves[0] = this->raiz->getMedio();
    raiz = nuevo;
    raiz->setEsHoja(false);
    raiz->setNumeroLibros(1);
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
        DividirRaiz();
    }
}

Libro **ArbolBFecha::librosPorAño(int año) {
    return nullptr;
}

std::string ArbolBFecha::obtenerDotArbol() {
    CreadorTextoDot creador;
    return creador.obtenerDotPorAño(raiz);
}

bool ArbolBFecha::estaVacia() {
    return raiz->getNumeroLibros() == 0;
}
