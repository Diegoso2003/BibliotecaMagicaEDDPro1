//
// Created by rafael-cayax on 19/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLTITULO_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLTITULO_H
#include "../ArbolAVL/ArbolAVL.h"

class ListaSimpleSinOrdenar;
class NodoArbolTitulo;
class ListaSimpleEnlazada;

class ArbolAVLTitulo : public ArbolAVL{
private:
    bool visitarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) override;
    bool visitarSubArbolIzquierdo(NodoArbol *&actual, Libro *&libro) override;
    NodoArbol *crearNuevoNodo(Libro *libro) override;
    void tratarLibroDuplicado(NodoArbol *nodo, Libro *&libro) override;
    void agregarOrdenAlfabetico(NodoArbolTitulo *nodo, ListaSimpleSinOrdenar *lista);
public:
    ListaSimpleEnlazada *buscarLibrosPorTitulo(std::string &titulo);
    ListaSimpleSinOrdenar *listarLibrosEnOrden();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLTITULO_H