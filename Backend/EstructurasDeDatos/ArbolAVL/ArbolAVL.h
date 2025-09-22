//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
#include "NodoArbol/NodoArbol.h"

class Libro;

class ArbolAVL {
private:
    NodoArbol *raiz;
    int elementos = 0;
    void eliminarArbol(NodoArbol *actual);
    void reorganizarArbolDerecho(NodoArbol *&nodo);
    void reorganizarArbolIzquierdo(NodoArbol *&nodo);
    virtual bool agregarSubArbolDerecho(NodoArbol *&actual,Libro *&libro) = 0;
    virtual bool agregarSubArbolIzquierdo(NodoArbol *&actual,Libro *&libro) = 0;
    void agregarNuevoNodo(NodoArbol*& nodo,Libro*& Libro, bool &cambioAlturaArbol);
public:
    ArbolAVL();
    virtual ~ArbolAVL();
    bool estaVacia(){return this->elementos == 0;}
    int getNumElementos(){return elementos;}
    void agregarLibro(Libro* nuevoLibro);
    NodoArbol* getRaiz(){return raiz;}
};

#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
