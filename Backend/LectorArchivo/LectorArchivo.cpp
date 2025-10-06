//
// Created by rafael-cayax on 14/9/25.
//

#include "LectorArchivo.h"

#include <filesystem>
#include <fstream>

#include "../AnalizadorLinea/AnalizadorLinea.h"
#include "../Biblioteca/Biblioteca.h"
#include "../Excepciones/ArchivoInvalidoException.h"
#include "../Excepciones/EntradaUsuarioException.h"

bool LectorArchivo::existeArchivo(std::string &ruta) {
    return std::filesystem::exists(ruta);
}

bool LectorArchivo::esLegible(std::string &ruta) {
    if (!std::filesystem::is_regular_file(ruta)) {
        return false;
    }

    std::filesystem::file_status status = std::filesystem::status(ruta);
    return (status.permissions() & std::filesystem::perms::owner_read) != std::filesystem::perms::none;
}

void LectorArchivo::leerArchivo(std::string &ruta, Biblioteca *biblioteca) {
    if (ruta.empty()) {
        throw ArchivoInvalidoException("ingresar ruta valida");
    }
    if (!existeArchivo(ruta)) {
        throw ArchivoInvalidoException("El archivo ingresado no existe");
    }
    if (!esLegible(ruta)) {
        throw ArchivoInvalidoException("El archivo ingresado no es legible");
    }
    std::ifstream archivo;
    archivo.open(ruta.c_str(), std::ios::in);
    if (archivo.fail()) {
        throw ArchivoInvalidoException("Error al abrir el archivo, intente de nuevo");
    }
    AnalizadorLinea analizador;
    while (!archivo.eof()) {
        std::string linea;
        std::getline(archivo, linea);
        analizador.analizarLinea(linea, biblioteca);
    }
    if (analizador.harError()) {
        throw EntradaUsuarioException(analizador.getMensajeError());
    }
    archivo.close();
}
