//
// Created by rafael-cayax on 28/9/25.
//

#include "ArbolBGenero.h"

#include "../../Auxiliar/Auxiliar.h"
#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../../Libro/Libro.h"
#include "NodoArbolBMasHoja/NodoArbolBMasHoja.h"
#include "NodoArbolBMasInterno/NodoArbolBMasInterno.h"

void ArbolBGenero::dividirRaiz() {
    auto *nuevo = new NodoArbolBMasInterno(ordenArbol);
    NodoArbolBMas **hijos = nuevo->getHijos();
    std::string **claves = nuevo->getClaves();
    hijos[0] = raiz;
    claves[0] = raiz->getClaveMedia();
    hijos[1] = raiz->getNuevoDer();
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
    raiz->agregarElemento(libro);
    if (raiz->getNumeroClaves() > maxElementos) {
        dividirRaiz();
    }
}

std::string ArbolBGenero::getDotArbolGenero() {
    if (raiz->getNumeroClaves() == 0) throw EntradaUsuarioException("arbol vacio, ingresar datos");
    CreadorTextoDot creador;
    return creador.obtenerDotPorGenero(raiz);
}
