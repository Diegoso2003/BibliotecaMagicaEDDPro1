//
// Created by rafael-cayax on 22/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H
#include "../../ListaSimple/ListaSimpleEnlazada.h"


class Libro;
class ListaSimpleEnlazada;

class NodoArbolB {
private:
    ListaSimpleEnlazada **claves;
    NodoArbolB **hijos;
    bool esHoja = true;
    int numeroClaves = 0;
    int max;
    int ordenArbol;
    void cambiarHijos(NodoArbolB *&nuevo, NodoArbolB *&viejo);
    void cambiarClaves(ListaSimpleEnlazada *& nuevo, ListaSimpleEnlazada *&viejo);
    explicit NodoArbolB(NodoArbolB *otro);
public:
    explicit NodoArbolB(int ordenArbol);
    ~NodoArbolB();
    void setNumeroLibros(int numLibros){this->numeroClaves = numLibros;}
    int getNumeroLibros() const {return this->numeroClaves;}
    void agregarClave(Libro *libro);
    void dividirNodoHijo(int posicion);
    bool esNodoHoja() const {return esHoja;}
    void setEsHoja(bool esNodoHoja) {this->esHoja = esNodoHoja;}
    ListaSimpleEnlazada **getClaves() const {return claves;}
    NodoArbolB **getHijos() const {return hijos;}
    ListaSimpleEnlazada *getMedio();
    NodoArbolB *getNuevoDer();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H