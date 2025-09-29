//
// Created by rafael-cayax on 28/9/25.
//

#include "ArbolBGenero.h"

#include "../../Auxiliar/Auxiliar.h"
#include "../../Libro/Libro.h"
#include "NodoArbolBMasHoja/NodoArbolBMasHoja.h"
#include "NodoArbolBMasInterno/NodoArbolBMasInterno.h"

void ArbolBGenero::agregarElemento(NodoArbolBMas *nodo, Libro *&nuevoLibro) {
    if (nodo->esNodoHoja()) {
        auto *nodoHoja = dynamic_cast<NodoArbolBMasHoja*>(nodo);
        nodoHoja->agregarElemento(nuevoLibro);
        return;
    }
    auto *nodoInterno = dynamic_cast<NodoArbolBMasInterno*>(nodo);
    NodoArbolBMas **hijos = nodoInterno->getHijos();
    std::string **claves = nodoInterno->getClaves();
    for (int i = 0; i <= nodoInterno->getNumeroClaves(); i++) {
        if (claves[i] == nullptr || Auxiliar::textoMinuscula(nuevoLibro->getGenero())
            < *claves[i]) {
            agregarElemento(hijos[i], nuevoLibro);
            if (hijos[i]->getNumeroClaves() > maxElementos) {
                nodoInterno->dividirNodoHijo(i);
            }
            break;
        }
    }
}

void ArbolBGenero::dividirRaiz() {
    auto *nuevo = new NodoArbolBMasInterno(ordenArbol);
    NodoArbolBMas **hijos = nuevo->getHijos();
    std::string **claves = nuevo->getClaves();
    hijos[0] = raiz;
    hijos[1] = raiz->getNuevoDer();
    claves[0] = raiz->getClaveMedia();
    nuevo->setNumeroClaves(1);
    raiz = nuevo;
}

ArbolBGenero::ArbolBGenero() {
    raiz = new NodoArbolBMasHoja(ordenArbol);
}

ArbolBGenero::~ArbolBGenero() {
    delete raiz;
}

void ArbolBGenero::agregarLibro(Libro *libro) {
    agregarElemento(raiz, libro);
    if (raiz->getNumeroClaves() > maxElementos) {
        dividirRaiz();
    }
}
