//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H
#define BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H
#include "../EstructurasDeDatos/ListaSimple/ListaSimpleEnlazada/ListaSimpleEnlazada.h"
#include <string>

class Libro;

class AnalizadorArchivo {
public:
    void analizarArchivo(std::string& rutaArchivo);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H