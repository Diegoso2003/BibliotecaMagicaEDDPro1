//
// Created by rafael-cayax on 23/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#define BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H
#include <string>

class NodoArbolB;

class CreadorTextoDot {
    void agregarDatosRecursivo(std::string &dot, NodoArbolB *nodo, int &numNodo);
public:
    std::string obtenerDotPorAño(NodoArbolB *raiz);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_CREADORTEXTODOT_H