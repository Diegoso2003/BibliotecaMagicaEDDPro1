//
// Created by rafael-cayax on 22/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLBFECHA_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLBFECHA_H
#include "NodoArbolB/NodoArbolB.h"

class Libro;

class ArbolBFecha {
private:
    NodoArbolB *raiz;
    int const ordenArbol = 4;
    int const maxElemNodo = 2 * ordenArbol;
    int const minElemNodo = ordenArbol;
    int const maxHijosNodo = maxElemNodo + 1;
    int const minHijosNodo = minElemNodo + 1;
    NodoArbolB *agregarElemento(NodoArbolB *nodo, Libro *&nuevoLibro);
public:
    ArbolBFecha();
    ~ArbolBFecha();
    void agregarLibro(Libro *nuevoLibro);
    Libro** librosPorAño(int año);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLBFECHA_H