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
    bool agregarDemasArboles = true;
    NodoArbol *buscarNodo(NodoArbol *nodo, Libro *libroBuscado);
private:
    int elementos = 0;
    NodoArbol *reorganizarArbolDerecho(NodoArbol *nodo);
    NodoArbol *reorganizarArbolIzquierdo(NodoArbol *nodo);
    NodoArbol *rotacionII(NodoArbol *nodo);
    NodoArbol *rotacionID(NodoArbol *nodo);
    NodoArbol *rotacionDD(NodoArbol *nodo);
    NodoArbol *rotacionDI(NodoArbol *nodo);
    NodoArbol *eliminarNodo(NodoArbol *nodo, Libro *libro, bool &verificarFeSubArbol);
    virtual bool visitarSubArbolDerecho(NodoArbol *&actual,Libro *&libro) = 0;
    virtual bool visitarSubArbolIzquierdo(NodoArbol *&actual,Libro *&libro) = 0;
    virtual bool eliminarNodo(NodoArbol* nodo, Libro *libro) = 0;
    virtual void tratarLibroDuplicado(NodoArbol* nodo, Libro *&libro) = 0;
    virtual void cambiarInformacion(NodoArbol* eliminar, NodoArbol* Reemplazo) = 0;
    virtual NodoArbol *crearNuevoNodo(Libro *libro) = 0;
    NodoArbol *evaluarNodoIzquierdo(NodoArbol *nodo);
    NodoArbol *evaluarNodoDerecho(NodoArbol *nodo);
    NodoArbol *agregarNuevoNodo(NodoArbol *nodo,Libro *Libro, bool &verificarFeSubArbol);
public:
    ArbolAVL();
    virtual ~ArbolAVL();
    std::string obtenerDotArbol();
    bool estaVacia(){return this->elementos == 0;}
    bool agregarLibro(){return agregarDemasArboles;}
    int getNumElementos(){return elementos;}
    void agregarLibro(Libro* nuevoLibro);
    void eliminarLibro(Libro *libro);
};

#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
