//
// Created by rafael-cayax on 28/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLBGENERO_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLBGENERO_H
#include "NodoArbolBMas/NodoArbolBMas.h"


class Libro;

class ArbolBGenero {
private:
    int const ordenArbol = 3;
    int const maxElementos = ordenArbol * 2;
    NodoArbolBMas* raiz;
    void dividirRaiz();
public:
    ArbolBGenero();
    ~ArbolBGenero();
    void agregarLibro(Libro *libro);
    bool estaVacia();
    std::string getDotArbolGenero();
    ListaOrdenada *buscarPorGenero(std::string &genero);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLBGENERO_H