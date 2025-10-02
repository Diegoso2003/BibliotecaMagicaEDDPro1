//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#include "NodoSimple/NodoSimple.h"
#include <string>

class IteradorListaSimple;

class ListaSimpleEnlazada {
protected:
    int tamaño;
    NodoSimple* primero;
    NodoSimple* ultimo;
    bool eliminarNodos = true;
    friend class ListaSimpleCopia;
private:
    void actualizarPosicionUltimo();
    NodoSimple* eliminarNodo(const std::string &isbn, Libro *&libro,  NodoSimple* nodo);
public:
    ListaSimpleEnlazada();
    virtual ~ListaSimpleEnlazada();
    bool estaVacia() const;
    virtual void agregar(Libro* libro);
    virtual Libro* eliminar(const std::string &isbn);
    Libro* getPrimero(){return !estaVacia() ? primero->getLibro(): nullptr;}
    int getTamaño() const;
    IteradorListaSimple getIterator();
};

#endif //PRACTICA1EDD_LISTADOBLEENLAZADA_H