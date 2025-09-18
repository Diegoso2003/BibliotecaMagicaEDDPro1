//
// Created by rafael-cayax on 18/9/25.
//

#include "CreadorSvg.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#include "../Excepciones/ArchivoInvalidoException.h"
#include "../Excepciones/ElementoDuplicadoException.h"

void CreadorSvg::crearSvg(const std::string &grafica, bool reemplazar, std::string nombreArchivo) {
    std::filesystem::create_directories(carpeta);

    std::string tempDotFile = carpeta + "/temp.dot";
    std::ofstream dotFile(tempDotFile);
    dotFile << grafica;
    dotFile.close();

    std::string archivoSvg = carpeta + "/" + nombreArchivo + ".svg";
    if (std::filesystem::exists(nombreArchivo) && !reemplazar) {
        throw ElementoDuplicadoException("¿Desea reemplazar la grafica actual?");
    }
    std::string command = "dot -Tsvg " + tempDotFile + " -o " + archivoSvg;

    int result = system(command.c_str());

    if (result != 0) {
        throw ArchivoInvalidoException("Error al crear la imagen");
    }

    std::filesystem::remove(tempDotFile);
}
