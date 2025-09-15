//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#include "../NodoSimple.h"
#include "../../../Iteradores/IteradorLED/IteradorLED.h"

template<typename T>
class ListaSimpleEnlazada {
private:
    int tamaño;
    NodoSimple<T>* primero;
    NodoSimple<T>* ultimo;
    NodoSimple<T>* obtenerDesdePrimero(int posicion);
    NodoSimple<T>* obtenerNodo(int posicion);
public:
    ListaSimpleEnlazada();
    ~ListaSimpleEnlazada();
    bool estaVacia() const;
    void agregar(T* elemento);
    T* obtener(int posicion);
    T* eliminar(int posicion);
    int getTamaño() const;
    IteradorLED<T> *getIterador();
};

#include "ListaSimpleEnlazada.cpp"
#endif //PRACTICA1EDD_LISTADOBLEENLAZADA_H