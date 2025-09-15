//
// Created by rafael-cayax on 15/9/25.
//

#include "Biblioteca.h"

#include "../EstructurasDeDatos/ListaSimple/ListaSimpleEnlazada/ListaSimpleEnlazada.h"
#include "../Libro/Libro.h"
#include "../AnalizadorArchivo/AnalizadorArchivo.h"

void Biblioteca::analizarArchivo(std::string &ruta) {
    AnalizadorArchivo analizador;
    analizador.analizarArchivo(ruta);
}
