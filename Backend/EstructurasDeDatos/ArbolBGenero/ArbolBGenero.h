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
    void agregarElemento(NodoArbolBMas *nodo, Libro *&nuevoLibro);
    void dividirRaiz();
public:
    ArbolBGenero();
    ~ArbolBGenero();
    void agregarLibro(Libro *libro);
    std::string getDotArbolGenero();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLBGENERO_H