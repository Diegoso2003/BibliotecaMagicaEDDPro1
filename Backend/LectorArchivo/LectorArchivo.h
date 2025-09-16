//
// Created by rafael-cayax on 14/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_LECTORLINEA_H
#define BIBLIOTECAMAGICAEDDPRO1_LECTORLINEA_H
#include <string>

#include "../EstructurasDeDatos/ListaSimple/ListaSimpleEnlazada.h"


class LectorArchivo {
private:
    bool existeArchivo(std::string& ruta);
    bool esLegible(std::string& ruta);
public:
    ListaSimpleEnlazada<std::string> leerArchivo(std::string& ruta);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_LECTORLINEA_H