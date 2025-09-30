//
// Created by rafael-cayax on 23/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#define BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#include <string>

#include "../EstructurasDeDatos/ArbolAVL/NodoArbol/NodoArbol.h"
#include "../EstructurasDeDatos/ArbolAVL/NodoArbolTitulo/NodoArbolTitulo.h"

class NodoArbolTitulo;
class NodoArbolIsbn;
class NodoArbol;
class NodoArbolBMas;
class NodoArbolB;

class CreadorTextoDot {
    void agregarDatosLibroIsbn(std::string &dot, Libro* libro);
    void agregarDatosLibroTitulo(std::string &dot, NodoArbolTitulo *nodo);
    void agregarDatosRecursivoPorAño(std::string &dot, NodoArbolB *nodo, int &numNodo);
    void agregarDatosRecursivoPorGenero(std::string &dot, NodoArbolBMas *nodo, int &numNodo);
    void agregarDatosRecursivoAVL(std::string &dot, NodoArbol *nodo, bool isbn);
    std::string obtenerDotArbolAvl(NodoArbol *raiz, bool isbn);
public:
    std::string obtenerDotPorAño(NodoArbolB *raiz);
    std::string obtenerDotPorGenero(NodoArbolBMas *raiz);
    std::string obtenerDotPorIsbn(NodoArbol *raiz);
    std::string obtenerDotPorTitulo(NodoArbol *raiz);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H