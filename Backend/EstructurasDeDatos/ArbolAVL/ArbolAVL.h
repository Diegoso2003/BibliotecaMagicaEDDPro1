//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
#include "NodoArbol/NodoArbol.h"
#include <string>

class Libro;

class ArbolAVL {
protected:
    NodoArbol *raiz;
    bool duplicado = false;
private:
    int elementos = 0;
    void reorganizarArbolDerecho(NodoArbol *&nodo);
    void reorganizarArbolIzquierdo(NodoArbol *&nodo);
    virtual bool agregarSubArbolDerecho(NodoArbol *&actual,Libro *&libro) = 0;
    virtual bool agregarSubArbolIzquierdo(NodoArbol *&actual,Libro *&libro) = 0;
    virtual void tratarLibroDuplicado(NodoArbol* nodo, Libro *&libro) = 0;
    virtual NodoArbol *crearNuevoNodo(Libro *libro) = 0;
    NodoArbol* agregarNuevoNodo(NodoArbol* nodo,Libro*& Libro, bool &verificarFeSubArbol);
public:
    ArbolAVL();
    virtual ~ArbolAVL();
    virtual std::string obtenerDotArbol() = 0;
    bool estaVacia(){return this->elementos == 0;}
    int getNumElementos(){return elementos;}
    void agregarLibro(Libro* nuevoLibro);
};

#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
