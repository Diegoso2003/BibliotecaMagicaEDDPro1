//
// Created by rafael-cayax on 15/9/25.
//

#include "Biblioteca.h"

#include "../EstructurasDeDatos/ListaSimple/ListaSimpleEnlazada.h"
#include "../Libro/Libro.h"
#include "../AnalizadorArchivo/AnalizadorArchivo.h"
#include "../Excepciones/EntradaUsuarioException.h"

void Biblioteca::obtenerLibros(std::string &ruta) {
    AnalizadorArchivo analizador;
    analizador.analizarArchivo(ruta);
    if (analizador.harError()) {
        throw EntradaUsuarioException(analizador.getMensajeError());
    }
}
