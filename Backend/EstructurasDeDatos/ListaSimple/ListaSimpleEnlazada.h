//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#include "NodoSimple/NodoSimple.h"
#include <string>

class IteradorListaSimple;

class ListaSimpleEnlazada {
private:
    int tamaño;
    bool eliminarNodos = true;
    NodoSimple* primero;
    NodoSimple* ultimo;
    void actualizarPosicionUltimo();
    NodoSimple* eliminarNodo(const std::string &isbn, Libro *&libro,  NodoSimple* nodo);
public:
    ListaSimpleEnlazada();
    ~ListaSimpleEnlazada();
    explicit ListaSimpleEnlazada(ListaSimpleEnlazada *copia);
    bool estaVacia() const;
    void agregar(Libro* libro);
    void agregarLista(ListaSimpleEnlazada *copia);
    Libro* eliminar(const std::string &isbn);
    Libro* getPrimero(){return !estaVacia() ? primero->getLibro(): nullptr;}
    int getTamaño() const;
    IteradorListaSimple getIterator();
};

#endif //PRACTICA1EDD_LISTADOBLEENLAZADA_H