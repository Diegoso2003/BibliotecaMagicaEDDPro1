//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H
#define BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H
#include "../EstructurasDeDatos/ListaSimple/ListaSimpleEnlazada.h"
#include <string>

class Libro;

class AnalizadorArchivo {
private:
    std::string titulo;
    std::string isbn;
    std::string fecha;
    std::string genero;
    std::string autor;
    bool hayError = false;
    int lineaActual = 0;
    std::string mensajeError;
    void extraerCampos(std::string* linea);
    void validarCampos();
public:
    void analizarArchivo(std::string& rutaArchivo);
    [[nodiscard]] bool harError() const {return hayError;}
    [[nodiscard]] std::string getMensajeError() const {return mensajeError;}
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H