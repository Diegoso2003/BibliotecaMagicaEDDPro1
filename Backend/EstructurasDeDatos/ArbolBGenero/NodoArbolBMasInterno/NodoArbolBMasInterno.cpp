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
    delete hijos[0];
    for (int i = 1; i < max; i++) {
        delete hijos[i+1];
        delete claves[i];
    }
    delete[] hijos;
    delete[] claves;
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

std::string * NodoArbolBMasInterno::prestarDerecha(NodoArbolBMas *nodo) {
    return nullptr;
}

std::string * NodoArbolBMasInterno::prestarIzquierda(NodoArbolBMas *nodo) {
    return nullptr;
}

void NodoArbolBMasInterno::fusionar(NodoArbolBMas *nodo) {
}

void NodoArbolBMasInterno::correrElementos(int posicion) {
    for (int i = posicion; i < numeroClaves; i++) {
        intercambiarHijos(hijos[i+1], hijos[i]);
        intercambiarClaves(claves[i+1], claves[i]);
    }
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
    for (int i = 0; i <= numeroClaves; i++) {
        if (claves[i] == nullptr || genero < Auxiliar::textoMinuscula(*claves[i])) {
            hijos[i]->eliminarLibro(libro);
            if (hijos[i]->getNumeroClaves() < ordenArbol) {
                if (i != numeroClaves && hijos[i+1]->getNumeroClaves() > ordenArbol) {
                    delete claves[i];
                    claves[i] = hijos[i]->prestarDerecha(hijos[i+1]);
                } else if (i != 0 && hijos[i-1]->getNumeroClaves() > ordenArbol) {
                    delete claves[i-1];
                    claves[i-1] = hijos[i]->prestarIzquierda(hijos[i-1]);
                } else if (i != numeroClaves) {
                    hijos[i]->fusionar(hijos[i+1]);
                    delete hijos[i+1];
                    hijos[i+1] = hijos[i];
                    hijos[i] = nullptr;
                    delete claves[i];
                    claves[i] = nullptr;
                    correrElementos(i);
                    numeroClaves--;
                } else {
                    hijos[i-1]->fusionar(hijos[i]);
                    delete hijos[i];
                    hijos[i] = hijos[i-1];
                    hijos[i-1] = nullptr;
                    delete claves[i-1];
                    claves[i-1] = nullptr;
                    numeroClaves--;
                }
            }
            break;
        }
    }
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