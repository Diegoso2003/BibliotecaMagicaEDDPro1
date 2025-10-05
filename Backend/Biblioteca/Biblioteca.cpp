//
// Created by rafael-cayax on 15/9/25.
//

#include "Biblioteca.h"

#include "../Libro/Libro.h"
#include <iostream>

#include "../AnalizadorLinea/AnalizadorLinea.h"
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
    listaSinOrdenar = new ListaSimpleSinOrdenar();
}

Biblioteca::~Biblioteca() {
    delete librosPorIsbn;
    delete librosPorTitulo;
    delete librosPorFecha;
    delete librosPorGenero;
    delete listaSinOrdenar;
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
    listaSinOrdenar->agregar(nuevoLibro);
    /**CreadorSvg creador;
    creador.crearSvg(obtenerDotArbolBMasGenero(), true,
        "prueba"+std::to_string(librosPorIsbn->getNumElementos()));**/
}

void Biblioteca::eliminarLibro(Libro *libro) {
    listaSinOrdenar->eliminar(libro->getSinGuiones());
    librosPorIsbn->eliminarLibro(libro);
    CreadorSvg creador;
    creador.crearSvg(obtenerDotArbolAVLPorISBN(), true,
        "prueba"+std::to_string(librosPorIsbn->getNumElementos()));
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

ListaOrdenada * Biblioteca::buscarLibroPorTitulo(std::string &titulo) {
    ListaOrdenada *lista = librosPorTitulo->buscarLibrosPorTitulo(titulo);
    if (lista == nullptr) throw BusquedaSinResultadoException("No se encontro ningun libro con este titulo");
    return lista;
}

ListaOrdenada * Biblioteca::buscarLibroPorGenero(std::string &genero) {
    ListaOrdenada *lista = librosPorGenero->buscarPorGenero(genero);
    if (lista == nullptr) throw BusquedaSinResultadoException("No se encontro ningun libro con este genero");
    return lista;
}

ListaOrdenada *Biblioteca::obtenerLibrosEnOrdenAlfabetico() {
    if (librosPorTitulo->estaVacia()) throw EntradaUsuarioException("Ingrese datos para trabajar");
    return librosPorTitulo->listarLibrosEnOrden();
}

ListaOrdenada * Biblioteca::obtenerLibrosPorFecha(std::string &fechas) {
    if (librosPorFecha->estaVacia()) throw EntradaUsuarioException("Ingrese datos para realizar busqueda");
    return librosPorFecha->getListaPorRango(fechas);
}
