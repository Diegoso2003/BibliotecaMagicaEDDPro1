//
// Created by rafael-cayax on 28/9/25.
//

#include "NodoArbolBMasInterno.h"

#include "../../../Auxiliar/Auxiliar.h"
#include "../../../Libro/Libro.h"

void NodoArbolBMasInterno::intercambiarHijos(NodoArbolBMas *&nuevo, NodoArbolBMas *&viejo) {
    NodoArbolBMas *aux = viejo;
    viejo = nuevo;
    nuevo = aux;
}

NodoArbolBMasInterno::NodoArbolBMasInterno(int ordenArbol)
    : NodoArbolBMas(ordenArbol){
    hijos = new NodoArbolBMas*[max+1];
    hijos[0] = nullptr;
    for (int i = 0; i < max; i++) {
        claves[i] = nullptr;
        hijos[i+1] = nullptr;
    }
}

NodoArbolBMasInterno::~NodoArbolBMasInterno() {
}

bool NodoArbolBMasInterno::esNodoHoja() const {
    return false;
}

std::string * NodoArbolBMasInterno::getClaveMedia() {
    std::string *claveMedia = claves[ordenArbol];
    claves[ordenArbol] = nullptr;
    return claveMedia;
}

NodoArbolBMas * NodoArbolBMasInterno::getNuevoDer() {
    auto *nuevo = new NodoArbolBMasInterno(ordenArbol);
    this->numeroClaves = ordenArbol;
    nuevo->numeroClaves = ordenArbol;
    int mitad = ordenArbol + 1;
    for (int i = 0; i <= ordenArbol; i++) {
        if (i < ordenArbol) {
            nuevo->claves[i] = this->claves[mitad+i];
            this->claves[mitad+i] = nullptr;
        }
        nuevo->hijos[i] = this->hijos[mitad+i];
        this->hijos[mitad+i] = nullptr;
    }
    return nuevo;
}

void NodoArbolBMasInterno::agregarElemento(Libro *libro) {
    for (int i = 0; i <= numeroClaves; i++) {
        if (claves[i] == nullptr || Auxiliar::textoMinuscula(libro->getGenero())
            < Auxiliar::textoMinuscula(*claves[i])) {
            hijos[i]->agregarElemento(libro);
            if (hijos[i]->getNumeroClaves() == max) {
                this->dividirNodoHijo(i);
            }
            break;
        }
    }
}

void NodoArbolBMasInterno::eliminarLibro(Libro *libro) {
    std::string genero = Auxiliar::textoMinuscula(libro->getGenero());
    for (int i = 0; i < numeroClaves; i++) {
        if (genero < Auxiliar::textoMinuscula(*claves[i])) {
            hijos[i]->eliminarLibro(libro);
            if (hijos[i]->getNumeroClaves() < ordenArbol) {

            }
        }
    }
    hijos[numeroClaves]->eliminarLibro(libro);
}

void NodoArbolBMasInterno::dividirNodoHijo(int posicion) {
    std::string *claveAux = claves[posicion];
    claves[posicion] = hijos[posicion]->getClaveMedia();
    NodoArbolBMas *aux = hijos[posicion+1];
    hijos[posicion+1] = hijos[posicion]->getNuevoDer();
    numeroClaves++;
    for (int i = posicion+1; i < numeroClaves; i++) {
        intercambiarHijos(aux, hijos[i+1]);
        intercambiarClaves(claveAux, claves[i]);
    }
}

ListaOrdenada * NodoArbolBMasInterno::buscarElemento(std::string &genero) {
    for (int i = 0; i < numeroClaves; i++) {
        if (genero < Auxiliar::textoMinuscula(*claves[i])) {
            return hijos[i]->buscarElemento(genero);
        }
    }
    return hijos[numeroClaves]->buscarElemento(genero);
}