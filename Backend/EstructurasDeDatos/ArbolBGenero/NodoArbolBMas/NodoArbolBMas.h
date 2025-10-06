//
// Created by rafael-cayax on 28/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMAS_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMAS_H

#include <string>
class ListaOrdenada;
class Libro;

class NodoArbolBMas {
protected:
    int numeroClaves = 0;
    int ordenArbol;
    int max;
    std::string **claves;
    void intercambiarClaves(std::string *&nuevo, std::string *&viejo);
public:
    explicit NodoArbolBMas(int ordenArbol);
    int getNumeroClaves() const {return numeroClaves;}
    std::string **getClaves() {return claves;}
    void setNumeroClaves(int numClaves){numeroClaves = numClaves;}
    virtual ~NodoArbolBMas() = default;
    virtual std::string *getClaveMedia() = 0;
    virtual NodoArbolBMas *getNuevoDer() = 0;
    virtual bool esNodoHoja() const = 0;
    virtual void agregarElemento(Libro *libro) = 0;
    virtual void eliminarLibro(Libro *libro) = 0;
    virtual std::string *prestarDerecha(NodoArbolBMas *nodo, std::string *clavePadre) = 0;
    virtual std::string *prestarIzquierda(NodoArbolBMas *nodo, std::string *clavePadre) = 0;
    virtual void fusionar(NodoArbolBMas *nodo) = 0;
    virtual ListaOrdenada *buscarElemento(std::string &genero) = 0;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMAS_H