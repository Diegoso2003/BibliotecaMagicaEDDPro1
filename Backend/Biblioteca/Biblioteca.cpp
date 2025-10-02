//
// Created by rafael-cayax on 15/9/25.
//

#include "Biblioteca.h"

#include "../Libro/Libro.h"
#include <iostream>

#include "../CreadorSVG/CreadorSvg.h"
#include "../Excepciones/BusquedaSinResultadoException.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include "../LectorArchivo/LectorArchivo.h"
#include "../EstructurasDeDatos/ListaSimpleSinOrdenar/ListaSimpleSinOrdenar.h"

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

Libro * Biblioteca::buscarLibroPorIsbn(const std::string &isbn) {
    Libro *libro = librosPorIsbn->buscarLibro(isbn);
    if (libro == nullptr) throw BusquedaSinResultadoException("No se encontro ningun libro con este isbn");
    return libro;
}

ListaSimpleEnlazada * Biblioteca::buscarLibroPorTitulo(std::string &titulo) {
    ListaSimpleEnlazada *lista = librosPorTitulo->buscarLibrosPorTitulo(titulo);
    if (lista == nullptr) throw BusquedaSinResultadoException("No se encontro ningun libro con este titulo");
    return lista;
}

ListaSimpleEnlazada * Biblioteca::buscarLibroPorGenero(std::string &genero) {
    ListaSimpleEnlazada *lista = librosPorGenero->buscarPorGenero(genero);
    if (lista == nullptr) throw BusquedaSinResultadoException("No se encontro ningun libro con este genero");
    return lista;
}

ListaSimpleEnlazada *Biblioteca::obtenerLibrosEnOrdenAlfabetico() {
    if (librosPorTitulo->estaVacia()) throw EntradaUsuarioException("Ingrese datos para trabajar");
    return librosPorTitulo->listarLibrosEnOrden();
}
