//
// Created by rafael-cayax on 23/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#define BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#include <string>

class NodoArbolTitulo;
class NodoArbolIsbn;
class NodoArbol;
class NodoArbolBMas;
class NodoArbolB;

class CreadorTextoDot {
    void agregarDatosRecursivoPorAño(std::string &dot, NodoArbolB *nodo, int &numNodo);
    void agregarDatosRecursivoPorGenero(std::string &dot, NodoArbolBMas *nodo, int &numNodo);
    void agregarDatosRecursivoAVL(std::string &dot, NodoArbol *nodo);
public:
    std::string obtenerDotArbolAvl(NodoArbol *raiz);
    std::string obtenerDotPorAño(NodoArbolB *raiz);
    std::string obtenerDotPorGenero(NodoArbolBMas *raiz);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H