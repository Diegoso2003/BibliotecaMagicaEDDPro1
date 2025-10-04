//
// Created by rafael-cayax on 14/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_LECTORLINEA_H
#define BIBLIOTECAMAGICAEDDPRO1_LECTORLINEA_H
#include <string>

#include "../EstructurasDeDatos/ListaOrdenada/ListaOrdenada.h"


class Biblioteca;

class LectorArchivo {
private:
    bool existeArchivo(std::string& ruta);
    bool esLegible(std::string& ruta);
public:
    void leerArchivo(std::string& ruta, Biblioteca *biblioteca);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_LECTORLINEA_H