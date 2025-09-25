//
// Created by rafael-cayax on 22/9/25.
//

#include "NodoArbolB.h"

#include "../../../Libro/Libro.h"
#include "../../ListaSimple/ListaSimpleEnlazada.h"

void NodoArbolB::cambiarHijos(NodoArbolB *&nuevo, NodoArbolB *&viejo) {
    NodoArbolB *auxiliar = viejo;
    viejo = nuevo;
    nuevo = auxiliar;
}

void NodoArbolB::cambiarClaves(ListaSimpleEnlazada *&nuevo, ListaSimpleEnlazada *&viejo) {
    ListaSimpleEnlazada *aux = viejo;
    viejo = nuevo;
    nuevo = aux;
}

NodoArbolB::NodoArbolB(int ordenArbol) {
    max = 2*ordenArbol+1;
    this->ordenArbol = ordenArbol;
    claves = new ListaSimpleEnlazada *[max];
    hijos = new NodoArbolB *[max+1];
    hijos[0] = nullptr;
    for (int i = 0; i < max; i++) {
        claves[i] = nullptr;
        hijos[i+1] = nullptr;
    }
}

NodoArbolB::~NodoArbolB() {
    delete hijos[0];
    for (int i = 1; i < max; i++) {
        delete hijos[i+1];
        delete claves[i];
    }
    delete[] claves;
    delete[] hijos;
}

void NodoArbolB::agregarClave(Libro *libro) {
    ListaSimpleEnlazada *aux = nullptr;
    bool agregado = false;
    if (numeroClaves == 0) {
        claves[0] = new ListaSimpleEnlazada();
        claves[0]->agregar(libro);
        numeroClaves++;
        return;
    }
    for (int i = 0; i < numeroClaves; i++) {
        if (agregado) {
            ListaSimpleEnlazada *aux2 = claves[i];
            claves[i] = aux;
            aux = aux2;
        } else {
            if (claves[i]->getPrimero()->getAño() == libro->getAño()) {
                claves[i]->agregar(libro);
                return;
            }
            if (claves[i]->getPrimero()->getAño() > libro->getAño()) {
                aux = claves[i];
                claves[i] = new ListaSimpleEnlazada();
                claves[i]->agregar(libro);
                numeroClaves++;
                agregado = true;
            }
        }
    }
    if (!agregado) {
        claves[numeroClaves] = new ListaSimpleEnlazada();
        claves[numeroClaves]->agregar(libro);
        numeroClaves++;
    }
}

void NodoArbolB::agregarClaveDelHijo(ListaSimpleEnlazada *nuevaClave, NodoArbolB *der, int posicion) {
    NodoArbolB *aux = hijos[posicion+1];
    hijos[posicion+1] = der;
    ListaSimpleEnlazada *listaAux = claves[posicion];
    claves[posicion] = nuevaClave;
    numeroClaves++;
    numeroHijos++;
    for (int i = posicion+1; i < numeroClaves; i++) {
        cambiarHijos(aux, hijos[i+1]);
        cambiarClaves(listaAux, claves[i]);
    }
}

ListaSimpleEnlazada * NodoArbolB::getMedio() {
    ListaSimpleEnlazada* mitad = claves[max/2];
    claves[max/2] = nullptr;
    return mitad;
}

NodoArbolB * NodoArbolB::getNuevoDer() {
    auto *aux = new NodoArbolB(ordenArbol);
    aux->numeroClaves = (this->numeroClaves-1)/2;
    aux->numeroHijos = (this->numeroHijos)/2;
    int mitad = (max-1)/2;
    for (int i = 0; i < max; i++) {
        if (i < mitad) {
            aux->claves[i] = this->claves[mitad+i+1];
            this->claves[mitad+i+1] = nullptr;
        } else {
            aux->claves[i] = nullptr;
        }
        if (i <= mitad) {
            aux->hijos[i] = this->hijos[mitad+i+1];
            this->hijos[mitad+i+1] = nullptr;
        } else {
            aux->hijos[i] = nullptr;
        }
    }
    this->numeroClaves = (numeroClaves-1)/2;
    this->numeroHijos /= 2;
    return aux;
}