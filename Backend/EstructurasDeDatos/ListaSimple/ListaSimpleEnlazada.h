//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#include "NodoSimple/NodoSimple.h"
#include <string>

class ListaSimpleEnlazada {
private:
    int tamaño;
    NodoSimple* primero;
    NodoSimple *obtenerLibro(NodoSimple *nodo, Libro *&libro);
public:
    ListaSimpleEnlazada();
    ~ListaSimpleEnlazada();
    bool estaVacia() const;
    void agregar(Libro* libro);
    Libro* eliminar(const std::string &isbn);
    Libro* getPrimero(){return !estaVacia() ? primero->getLibro(): nullptr;}
    int getTamaño() const;
};

#endif //PRACTICA1EDD_LISTADOBLEENLAZADA_H