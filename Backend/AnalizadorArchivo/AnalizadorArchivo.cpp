//
// Created by rafael-cayax on 15/9/25.
//

#include "AnalizadorArchivo.h"
#include <regex>

#include "../Auxiliar/Auxiliar.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include "../LectorArchivo/LectorArchivo.h"
#include "../Libro/Libro.h"

void AnalizadorArchivo::analizarArchivo(std::string &rutaArchivo) {
    LectorArchivo lector;
    ListaSimpleEnlazada<std::string> lineas = lector.leerArchivo(rutaArchivo);
    IteradorLED<std::string>* datos = lineas.getIterador();
    while (datos->haySiguiente()) {
        lineaActual++;
        if (!datos->getActual()->empty()) {
            try {
                extraerCampos(datos->getActual());
                validarCampos();
            }catch (const std::exception& e) {
                hayError = true;
                mensajeError += "Error en la linea: "
                + std::to_string(lineaActual) + "\n"
                + e.what() + " " + *datos->getActual() + "\n";
            }
        }
    }
}

void AnalizadorArchivo::extraerCampos(std::string *linea) {
    std::regex patron(R"lit(^\s*"(.*)"\s*,\s*"(.*)"\s*,\s*"(.*)"\s*,\s*"(.*)"\s*,\s*"(.*)"\s*$)lit");
    std::smatch coincidencias;
    if (!std::regex_match(*linea, coincidencias, patron)) {
        throw EntradaUsuarioException("la informacion del libro tiene un formato invalido");
    }
    titulo = coincidencias[1];
    isbn = coincidencias[2];
    genero= coincidencias[3];
    fecha = coincidencias[4];
    autor= coincidencias[5];
}

void AnalizadorArchivo::validarCampos() {
    Auxiliar::eliminarEspaciosIntermedio(titulo);
    Auxiliar::eliminarEspaciosIntermedio(genero);
    Auxiliar::eliminarEspaciosIntermedio(autor);
    if (titulo.empty() || autor.empty() || genero.empty()) {
        throw EntradaUsuarioException("ingresar campos validos");
    }
    std::regex año("^[1-9][0-9]{3}$");
    if (!std::regex_match(fecha, año)) {
        throw EntradaUsuarioException("ingresar un año valido");
    }
    std::regex isbn13(R"(^(97[89]-?\d{1,5}-?\d{1,7}-?\d{1,6}-?\d)$)");
    if (!std::regex_match(isbn, isbn13) || Auxiliar::obtenerISBNSinGuion(isbn).size() != 13) {
        throw EntradaUsuarioException("Ingresar un isbn valido");
    }
}
