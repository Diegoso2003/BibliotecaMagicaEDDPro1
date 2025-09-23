//
// Created by rafael-cayax on 22/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H


class Libro;
class ListaSimpleEnlazada;

class NodoArbolB {
private:
    ListaSimpleEnlazada **libros;
    NodoArbolB **hijos;
    int numeroHijos = 0;
    int numeroLibros = 0;
    int max;
public:
    explicit NodoArbolB(int ordenArbol);
    void setNumeroHijos(int numHijos){this->numeroHijos = numHijos;}
    void setNumeroLibros(int numLibros){this->numeroLibros = numLibros;}
    int getNumeroHijos() const {return this->numeroHijos;}
    int getNumeroLibros() const {return this->numeroLibros;}
    void agregarClave(Libro *libro);
    ListaSimpleEnlazada **getClaves() const {return libros;}
    NodoArbolB **getHijos() const {return hijos;}
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLB_H