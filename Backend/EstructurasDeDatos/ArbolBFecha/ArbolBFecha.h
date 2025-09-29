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
    int const ordenArbol = 3;
    int const maxElemNodo = 2 * ordenArbol;
    void agregarElemento(NodoArbolB *nodo, Libro *&nuevoLibro);
    void DividirRaiz();
public:
    ArbolBFecha();
    ~ArbolBFecha();
    void agregarLibro(Libro *nuevoLibro);
    Libro** librosPorAño(int año);
    std::string obtenerDotArbol();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLBFECHA_H