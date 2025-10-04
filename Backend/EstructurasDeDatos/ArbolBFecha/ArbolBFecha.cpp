//
// Created by rafael-cayax on 22/9/25.
//

#include "ArbolBFecha.h"

#include <iostream>
#include <ostream>


#include "../../Auxiliar/Auxiliar.h"
#include "../../AuxiliarBusquedaB/AuxiliarBusquedaB.h"
#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/BusquedaSinResultadoException.h"
#include "../../Libro/Libro.h"
#include "../ListaOrdenada/ListaOrdenada.h"
#include "../ListaSimpleSinOrdenar/ListaSimpleSinOrdenar.h"

void ArbolBFecha::agregarElemento(NodoArbolB *nodo, Libro *&nuevoLibro) {
    if (nodo->esNodoHoja()) {
        nodo->agregarClave(nuevoLibro);
        return;
    }
    ListaOrdenada **libros = nodo->getClaves();
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
    ListaOrdenada **claves = nuevo->getClaves();
    hijos[0] = this->raiz;
    hijos[1] = this->raiz->getNuevoDer();
    claves[0] = this->raiz->getMedio();
    raiz = nuevo;
    raiz->setEsHoja(false);
    raiz->setNumeroLibros(1);
}

void ArbolBFecha::agregarListaElementos(AuxiliarBusquedaB *aux, NodoArbolB *nodo) {
    if (nodo == nullptr) return;
    ListaOrdenada **claves = nodo->getClaves();
    NodoArbolB **hijos = nodo->getHijos();
    for (int i = 0; i <= nodo->getNumeroLibros() && aux->seguirBuscando(); i++) {
    numeroVeces++;
        if (claves[i] != nullptr) {
            int actual = claves[i]->getPrimero()->getAño();
            if (actual >= aux->fechaInicio() && actual <= aux->fechaFin()) {
                if (actual != aux->fechaInicio()) agregarListaElementos(aux, hijos[i]);
                aux->getLista()->copiarLista(claves[i]);
                if (actual == aux->fechaFin()) aux->pararBusqueda();
                continue;
            }
            if (nodo->esNodoHoja() && actual > aux->fechaFin()) aux->pararBusqueda();
        }
        if (claves[i] == nullptr || aux->fechaInicio() < claves[i]->getPrimero()->getAño()) {
            agregarListaElementos(aux, hijos[i]);
            if (aux->esFechaUnica()) break;
        }
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
        DividirRaiz();
    }
}

std::string ArbolBFecha::obtenerDotArbol() {
    CreadorTextoDot creador;
    return creador.obtenerDotPorAño(raiz);
}

bool ArbolBFecha::estaVacia() {
    return raiz->getNumeroLibros() == 0;
}

ListaSimpleSinOrdenar *ArbolBFecha::getListaPorRango(const std::string &texto) {
    int fechas[2] = {-1, -1};
    Auxiliar::obtenerFechas(texto, fechas);
    auto *lista = new ListaSimpleSinOrdenar();
    AuxiliarBusquedaB aux(lista, fechas);
    numeroVeces = 0;
    agregarListaElementos(&aux, raiz);
    std::cout << "numero de veces: "<< numeroVeces << std::endl;
    if (lista->estaVacia()) throw BusquedaSinResultadoException("No se encontro ningun libro en este rango de fecha");
    return lista;
}
