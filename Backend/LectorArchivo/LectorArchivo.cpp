//
// Created by rafael-cayax on 14/9/25.
//

#include "LectorArchivo.h"

#include <filesystem>
#include <iostream>
#include <fstream>

#include "../EntradaUsuarioException/EntradaUsuarioException.h"


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

std::string LectorArchivo::leerArchivo(std::string &ruta) {

}
