//
// Created by rafael-cayax on 22/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLBFECHA_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLBFECHA_H
#include "NodoArbolB/NodoArbolB.h"

class AuxiliarBusquedaB;
class ListaSimpleSinOrdenar;
class Libro;

class ArbolBFecha {
private:
    NodoArbolB *raiz;
    int const ordenArbol = 3;
    int numeroVeces = 1;
    int const maxElemNodo = 2 * ordenArbol;
    void agregarElemento(NodoArbolB *nodo, Libro *&nuevoLibro);
    void DividirRaiz();
    void agregarListaElementos(AuxiliarBusquedaB *aux, NodoArbolB *nodo);
public:
    ArbolBFecha();
    ~ArbolBFecha();
    void agregarLibro(Libro *nuevoLibro);
    std::string obtenerDotArbol();
    bool estaVacia();
    ListaSimpleSinOrdenar *getListaPorRango(const std::string &texto);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLBFECHA_H