//
// Created by rafael-cayax on 23/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#define BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#include <string>

#include "../EstructurasDeDatos/ArbolAVL/NodoArbol/NodoArbol.h"

class NodoArbol;
class NodoArbolBMas;
class NodoArbolB;

class CreadorTextoDot {
    void agregarDatosRecursivoPorAño(std::string &dot, NodoArbolB *nodo, int &numNodo);
    void agregarDatosRecursivoPorGenero(std::string &dot, NodoArbolBMas *nodo, int &numNodo);
    void agregarDatosRecursivoPorIsbn(std::string &dot, NodoArbol *nodo);
    void agregarDatosRecursivoPorTitulo(std::string &dot, NodoArbol *nodo);
public:
    std::string obtenerDotPorAño(NodoArbolB *raiz);
    std::string obtenerDotPorGenero(NodoArbolBMas *raiz);
    std::string obtenerDotPorIsbn(NodoArbol *raiz);
    std::string obtenerDotPorTitulo(NodoArbol *raiz);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H