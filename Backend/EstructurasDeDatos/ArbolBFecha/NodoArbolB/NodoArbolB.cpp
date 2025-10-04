//
// Created by rafael-cayax on 22/9/25.
//

#include "NodoArbolB.h"

#include <iostream>
#include <ostream>

#include "../../../Libro/Libro.h"
#include "../../ListaOrdenada/ListaOrdenada.h"

void NodoArbolB::cambiarHijos(NodoArbolB *&nuevo, NodoArbolB *&viejo) {
    NodoArbolB *auxiliar = viejo;
    viejo = nuevo;
    nuevo = auxiliar;
}

void NodoArbolB::cambiarClaves(ListaOrdenada *&nuevo, ListaOrdenada *&viejo) {
    ListaOrdenada *aux = viejo;
    viejo = nuevo;
    nuevo = aux;
}

NodoArbolB::NodoArbolB(NodoArbolB *otro) {
    this->ordenArbol = otro->ordenArbol;
    this->max = 2*ordenArbol+1;
    claves = new ListaOrdenada *[max];
    hijos = new NodoArbolB *[max+1];
    this->numeroClaves = ordenArbol;
    this->esHoja = otro->esHoja;
    for (int i = 0; i < max; i++) {
        if (i < ordenArbol) {
            this->claves[i] = otro->claves[ordenArbol+i+1];
            otro->claves[ordenArbol+i+1] = nullptr;
        } else {
            this->claves[i] = nullptr;
        }
        if (i <= ordenArbol) {
            this->hijos[i] = otro->hijos[ordenArbol+i+1];
            otro->hijos[ordenArbol+i+1] = nullptr;
        } else {
            this->hijos[i] = nullptr;
        }
    }
    this->hijos[max] = nullptr;
}

NodoArbolB::NodoArbolB(int ordenArbol) {
    max = 2*ordenArbol+1;
    this->ordenArbol = ordenArbol;
    claves = new ListaOrdenada *[max];
    hijos = new NodoArbolB *[max+1];
    hijos[0] = nullptr;
    for (int i = 0; i < max; i++) {
        claves[i] = nullptr;
        hijos[i+1] = nullptr;
    }
}

NodoArbolB::~NodoArbolB() {
    delete hijos[0];
    for (int i = 0; i < max; i++) {
        delete hijos[i+1];
        delete claves[i];
    }
    delete[] claves;
    delete[] hijos;
}

void NodoArbolB::agregarClave(Libro *libro) {
    ListaOrdenada *aux = nullptr;
    bool agregado = false;
    numeroClaves++;
    for (int i = 0; i < numeroClaves; i++) {
        if (agregado) {
            cambiarClaves(aux, claves[i]);
        } else {
            if (claves[i] == nullptr || claves[i]->getPrimero()->getAño() > libro->getAño()) {
                aux = claves[i];
                claves[i] = new ListaOrdenada();
                claves[i]->agregar(libro);
                agregado = true;
            } else if (claves[i]->getPrimero()->getAño() == libro->getAño()) {
                claves[i]->agregar(libro);
                numeroClaves--;
                return;
            }
        }
    }
}

void NodoArbolB::dividirNodoHijo(int posicion) {
    NodoArbolB *aux = hijos[posicion+1];
    hijos[posicion+1] = hijos[posicion]->getNuevoDer();
    ListaOrdenada *listaAux = claves[posicion];
    claves[posicion] = hijos[posicion]->getMedio();
    numeroClaves++;
    for (int i = posicion+1; i < numeroClaves; i++) {
        cambiarHijos(aux, hijos[i+1]);
        cambiarClaves(listaAux, claves[i]);
    }
}

ListaOrdenada * NodoArbolB::getMedio() {
    ListaOrdenada* mitad = claves[ordenArbol];
    claves[ordenArbol] = nullptr;
    return mitad;
}

NodoArbolB * NodoArbolB::getNuevoDer() {
    auto *aux = new NodoArbolB(this);
    this->numeroClaves = ordenArbol;
    return aux;
}