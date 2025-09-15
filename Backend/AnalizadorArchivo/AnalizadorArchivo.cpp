//
// Created by rafael-cayax on 15/9/25.
//

#include "AnalizadorArchivo.h"
#include <iostream>
#include "../LectorArchivo/LectorArchivo.h"
#include "../Libro/Libro.h"

void AnalizadorArchivo::analizarArchivo(std::string &rutaArchivo) {
    ListaSimpleEnlazada<Libro> librosNuevos;
    LectorArchivo lector;
    ListaSimpleEnlazada<std::string> lineas = lector.leerArchivo(rutaArchivo);
    IteradorLED<std::string>* iterador = lineas.getIterador();
    while (iterador->haySiguiente()) {
        std::string* actual = iterador->getActual();
        std::cout << *actual << std::endl;
    }
}