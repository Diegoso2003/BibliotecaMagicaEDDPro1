//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H
#define BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H
#include "../EstructurasDeDatos/ListaOrdenada/ListaOrdenada.h"
#include <string>

class Biblioteca;
class Libro;

class AnalizadorLinea {
private:
    std::string titulo;
    std::string isbn;
    std::string fecha;
    std::string genero;
    std::string autor;
    bool hayError = false;
    int lineaActual = 0;
    std::string mensajeError;
    void extraerCampos(const std::string& linea);
    void validarCampos();
    Libro* crearLibro();
public:
    static void validarIsbn(const std::string &isbn);
    void analizarLinea(const std::string &linea, Biblioteca *biblioteca);
    [[nodiscard]] bool harError() const {return hayError;}
    [[nodiscard]] std::string getMensajeError() const {return mensajeError;}
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ANALIZADORARCHIVO_H