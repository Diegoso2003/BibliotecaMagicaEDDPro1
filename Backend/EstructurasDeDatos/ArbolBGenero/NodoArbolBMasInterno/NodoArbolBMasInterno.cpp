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

std::string * NodoArbolBMasInterno::prestarDerecha(NodoArbolBMas *nodo, std::string *clavePadre) {
    auto *nodoInterno = dynamic_cast<NodoArbolBMasInterno *>(nodo);
    this->claves[numeroClaves++] = clavePadre;
    this->hijos[numeroClaves] = nodoInterno->hijos[0];
    std::string *aux = nodoInterno->claves[0];
    nodoInterno->claves[0] = nullptr;
    nodoInterno->hijos[0] = nullptr;
    nodoInterno->correrElementos(0);
    nodoInterno->numeroClaves--;
    return aux;
}

std::string * NodoArbolBMasInterno::prestarIzquierda(NodoArbolBMas *nodo, std::string *clavePadre) {
    auto *nodoInterno = dynamic_cast<NodoArbolBMasInterno *>(nodo);
    int ultimaClave = nodoInterno->numeroClaves-1;
    std::string *aux = nodoInterno->claves[ultimaClave];
    nodoInterno->claves[ultimaClave] = nullptr;
    nodoInterno->numeroClaves--;
    this->numeroClaves++;
    std::string *aux2 = clavePadre;
    NodoArbolBMas *aux3 = nodoInterno->hijos[ultimaClave+1];
    nodoInterno->hijos[ultimaClave+1] = nullptr;
    for (int i = 0; i < numeroClaves; i++) {
        intercambiarClaves(aux2, claves[i]);
        intercambiarHijos(aux3, hijos[i]);
    }
    intercambiarHijos(aux3, hijos[ultimaClave]);
    return aux;
}

void NodoArbolBMasInterno::fusionar(NodoArbolBMas *nodo, std::string *clavePadre) {
    auto *nodoInterno = dynamic_cast<NodoArbolBMasInterno *>(nodo);
    this->claves[numeroClaves++] = clavePadre;
    int contador = 0;
    int i;
    for (i = numeroClaves; i < numeroClaves + nodoInterno->numeroClaves ; i++) {
        hijos[i] = nodoInterno->hijos[contador];
        claves[i] = nodoInterno->claves[contador];
        nodoInterno->hijos[contador] = nullptr;
        nodoInterno->claves[contador] = nullptr;
        contador++;
    }
    hijos[i] = nodoInterno->hijos[contador];
    nodoInterno->hijos[contador] = nullptr;
    numeroClaves += nodoInterno->numeroClaves;
    nodoInterno->numeroClaves = 0;
}

void NodoArbolBMasInterno::correrElementos(int posicion) {
    int i;
    for (i = posicion; i < numeroClaves; i++) {
        intercambiarHijos(hijos[i+1], hijos[i]);
        intercambiarClaves(claves[i+1], claves[i]);
    }
    intercambiarHijos(hijos[i+1], hijos[i]);
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
                    std::string *aux = claves[i];
                    claves[i] = hijos[i]->prestarDerecha(hijos[i+1], aux);
                } else if (i != 0 && hijos[i-1]->getNumeroClaves() > ordenArbol) {
                    std::string *aux =  claves[i-1];
                    claves[i-1] = hijos[i]->prestarIzquierda(hijos[i-1], aux);
                } else if (i != numeroClaves) {
                    hijos[i]->fusionar(hijos[i+1], claves[i]);
                    delete hijos[i+1];
                    hijos[i+1] = hijos[i];
                    hijos[i] = nullptr;
                    claves[i] = nullptr;
                    correrElementos(i);
                    numeroClaves--;
                } else {
                    hijos[i-1]->fusionar(hijos[i], claves[i-1]);
                    delete hijos[i];
                    hijos[i] = nullptr;
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