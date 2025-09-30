//
// Created by rafael-cayax on 15/9/25.
//

#include "Biblioteca.h"

#include "../Libro/Libro.h"
#include <iostream>

#include "../CreadorSVG/CreadorSvg.h"
#include "../LectorArchivo/LectorArchivo.h"

Biblioteca::Biblioteca() {
    librosPorIsbn = new ArbolAVLPorIsbn();
    librosPorTitulo = new ArbolAVLTitulo();
    librosPorFecha = new ArbolBFecha();
    librosPorGenero = new ArbolBGenero();
}

Biblioteca::~Biblioteca() {
    delete librosPorIsbn;
    delete librosPorTitulo;
    delete librosPorFecha;
    delete librosPorGenero;
}

void Biblioteca::extraerLibrosArchivo(std::string &ruta) {
    LectorArchivo lector;
    lector.leerArchivo(ruta, this);
    std::cout << librosPorIsbn->getNumElementos() << std::endl;
}

void Biblioteca::ingresarNuevoLibro(Libro *nuevoLibro) {
    librosPorIsbn->agregarLibro(nuevoLibro);
    if (!librosPorIsbn->agregarLibro()) return;
    librosPorTitulo->agregarLibro(nuevoLibro);
    librosPorFecha->agregarLibro(nuevoLibro);
    librosPorGenero->agregarLibro(nuevoLibro);
    /**CreadorSvg creador;
    creador.crearSvg(obtenerDotArbolBMasGenero(), true,
        "prueba"+std::to_string(librosPorIsbn->getNumElementos()));**/
}

std::string Biblioteca::obtenerDotArbolAVLPorISBN() {
    return librosPorIsbn->obtenerDotArbol();
}

std::string Biblioteca::obtenerDotArbolAVLPorTitulo() {
    return librosPorTitulo->obtenerDotArbol();
}

std::string Biblioteca::obtenerDotArbolBFecha() {
    return librosPorFecha->obtenerDotArbol();
}

std::string Biblioteca::obtenerDotArbolBMasGenero() {
    return librosPorGenero->getDotArbolGenero();
}