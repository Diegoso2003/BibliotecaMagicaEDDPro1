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
    int numeroHijos = 0;
    int numeroClaves = 0;
    int max;
    int ordenArbol;
    void cambiarHijos(NodoArbolB *&nuevo, NodoArbolB *&viejo);
    void cambiarClaves(ListaSimpleEnlazada *& nuevo, ListaSimpleEnlazada *&viejo);
public:
    explicit NodoArbolB(int ordenArbol);
    ~NodoArbolB();
    void setNumeroHijos(int numHijos){this->numeroHijos = numHijos;}
    void setNumeroLibros(int numLibros){this->numeroClaves = numLibros;}
    int getNumeroHijos() const {return this->numeroHijos;}
    int getNumeroLibros() const {return this->numeroClaves;}
    void agregarClave(Libro *libro);
    void agregarClaveDelHijo(ListaSimpleEnlazada *libros, NodoArbolB *der, int posicion);
    bool esNodoHoja() const {return numeroHijos == 0;}
    ListaSimpleEnlazada **getClaves() const {return claves;}
    NodoArbolB **getHijos() const {return hijos;}
    ListaSimpleEnlazada *getMedio();
    NodoArbolB *getNuevoDer();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H