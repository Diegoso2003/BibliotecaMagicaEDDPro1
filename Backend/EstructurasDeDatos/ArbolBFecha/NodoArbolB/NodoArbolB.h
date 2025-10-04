//
// Created by rafael-cayax on 22/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H
#include "../../ListaOrdenada/ListaOrdenada.h"


class Libro;
class ListaOrdenada;

class NodoArbolB {
private:
    ListaOrdenada **claves;
    NodoArbolB **hijos;
    bool esHoja = true;
    int numeroClaves = 0;
    int max;
    int ordenArbol;
    void cambiarHijos(NodoArbolB *&nuevo, NodoArbolB *&viejo);
    void cambiarClaves(ListaOrdenada *& nuevo, ListaOrdenada *&viejo);
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
    ListaOrdenada **getClaves() const {return claves;}
    NodoArbolB **getHijos() const {return hijos;}
    ListaOrdenada *getMedio();
    NodoArbolB *getNuevoDer();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H