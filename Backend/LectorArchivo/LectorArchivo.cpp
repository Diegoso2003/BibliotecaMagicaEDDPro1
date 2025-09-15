//
// Created by rafael-cayax on 14/9/25.
//

#include "LectorArchivo.h"

#include <filesystem>
#include <fstream>

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

ListaSimpleEnlazada<std::string> LectorArchivo::leerArchivo(std::string &ruta) {
    if (ruta.empty()) {
        throw EntradaUsuarioException("ingresar ruta valida");
    }
    if (!existeArchivo(ruta)) {
        throw EntradaUsuarioException("El archivo ingresado no existe");
    }
    if (!esLegible(ruta)) {
        throw EntradaUsuarioException("El archivo ingresado no es legible");
    }
    std::ifstream archivo;
    ListaSimpleEnlazada<std::string> lista;
    archivo.open(ruta.c_str(), std::ios::in);
    if (archivo.fail()) {
        throw EntradaUsuarioException("Error al abrir el archivo, intente de nuevo");
    }

    while (!archivo.eof()) {
        std::string linea;
        std::getline(archivo, linea);
        lista.agregar(new std::string(linea));
    }
    archivo.close();
    return lista;
}
