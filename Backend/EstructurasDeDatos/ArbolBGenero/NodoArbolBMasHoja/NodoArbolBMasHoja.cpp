//
// Created by rafael-cayax on 28/9/25.
//

#include "NodoArbolBMasHoja.h"

#include "../../../Auxiliar/Auxiliar.h"
#include "../../../Libro/Libro.h"
#include "../../ListaSimple/ListaSimpleEnlazada.h"

void NodoArbolBMasHoja::intercambiarElementos(ListaSimpleEnlazada *&nuevo, ListaSimpleEnlazada *&viejo) {
    ListaSimpleEnlazada *aux = viejo;
    viejo = nuevo;
    nuevo = aux;
}

NodoArbolBMasHoja::NodoArbolBMasHoja(int ordenArbol)
    : NodoArbolBMas(ordenArbol){
    elementos = new ListaSimpleEnlazada *[max];
    for (int i = 0; i < max; i++) {
        elementos[i] = nullptr;
        claves[i] = nullptr;
    }
}

NodoArbolBMasHoja::~NodoArbolBMasHoja() {
}

void NodoArbolBMasHoja::agregarElemento(Libro *libro) {
    std::string *aux = nullptr;
    ListaSimpleEnlazada *auxElemento = nullptr;
    bool agregado = false;
    numeroClaves++;
    for (int i = 0; i < numeroClaves; i++) {
        if (agregado) {
            intercambiarClaves(aux, claves[i]);
            intercambiarElementos(auxElemento, elementos[i]);
        } else {
            if (claves[i] == nullptr ||
                Auxiliar::textoMinuscula(*claves[i]) > Auxiliar::textoMinuscula(libro->getGenero())) {
                aux = claves[i];
                auxElemento = elementos[i];
                claves[i] = new std::string(libro->getGenero());
                elementos[i] = new ListaSimpleEnlazada();
                elementos[i]->agregar(libro);
                agregado = true;
            } else if (*claves[i] == Auxiliar::textoMinuscula(libro->getGenero())) {
                elementos[i]->agregar(libro);
                numeroClaves--;
                return;
            }
        }
    }
}

bool NodoArbolBMasHoja::esNodoHoja() const {
    return true;
}

std::string * NodoArbolBMasHoja::getClaveMedia() {
    return claves[ordenArbol];
}

NodoArbolBMas * NodoArbolBMasHoja::getNuevoDer() {
    auto *hoja = new NodoArbolBMasHoja(ordenArbol);
    this->numeroClaves = ordenArbol;
    hoja->numeroClaves = ordenArbol+1;
    for (int i = 0; i <= ordenArbol; i++) {
        hoja->claves[i] = this->claves[ordenArbol+i];
        hoja->elementos[i] = this->elementos[ordenArbol+i];
        this->claves[ordenArbol+i] = nullptr;
        this->elementos[ordenArbol+i] = nullptr;
    }
    return hoja;
}
