//
// Created by rafael-cayax on 15/9/25.
//

#include "Biblioteca.h"

#include "../Libro/Libro.h"
#include "../AnalizadorLinea/AnalizadorLinea.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include <iostream>

#include "../CreadorSVG/CreadorSvg.h"
#include "../LectorArchivo/LectorArchivo.h"

void Biblioteca::agregarLibros(std::string &libros, NodoArbol *nodo) {
    std::string pl = "Libro";
    Libro *libro = nodo->getLibro();
    libros += pl + libro->getSinGuiones();
    libros += R"( [label="ISBN: )" + libro->getIsbn() + R"(\n)";
    libros += R"(Titulo: )" + libro->getTitulo() + R"(\n)";
    libros += R"(Fe: )" +std::to_string( nodo->getFe() )+ R"(\n)";
    libros += "Autor: " + libro->getAutor() + R"(\n)";
    libros += "Genero: " + libro->getGenero() + R"(\n)";
    libros += "Año Publicacion: " + libro->getAño() + R"(\n)";
    libros += R"("];)"; libros += "\n";
    if (nodo->getDerecha()!= nullptr || nodo->getIzquierda()!= nullptr) {
        std::string auxiliar2 = pl + libro->getSinGuiones() + " -> {";
        std::string auxiliar = "{ rank=same; ";
        if (nodo->getIzquierda() != nullptr) {
            agregarLibros(libros, nodo->getIzquierda());
            auxiliar2 += pl + nodo->getIzquierda()->getLibro()->getSinGuiones() + " ";
            auxiliar += pl + nodo->getIzquierda()->getLibro()->getSinGuiones() + "; ";
        }
        if (nodo->getDerecha() != nullptr) {
            agregarLibros(libros, nodo->getDerecha());
            auxiliar2 += pl+nodo->getDerecha()->getLibro()->getSinGuiones();
            auxiliar += pl+nodo->getDerecha()->getLibro()->getSinGuiones() + ";";
        }
        auxiliar += "}\n";
        auxiliar2 += "}\n";
        libros += auxiliar2;
        libros+= auxiliar;
    }
}

std::string Biblioteca::obtenerDotArbolAVL(ArbolAVL *arbol) {
    if (arbol->estaVacia()) throw EntradaUsuarioException("arbol vacio, ingrese datos para visualizar grafica");
    NodoArbol *raiz = arbol->getRaiz();
    std::string elementos = R"(digraph G {
        rankdir=TB;
        graph [ranksep=1, nodesep=0.5];
        node [shape=box, style=filled, color=lightblue, fontsize=10];)";
    elementos += "\n";
    agregarLibros(elementos, raiz);
    elementos += "}";
    return elementos;
}

Biblioteca::Biblioteca() {
    librosPorIsbn = new ArbolAVLPorIsbn();
    librosPorTitulo = new ArbolAVLTitulo();
}

Biblioteca::~Biblioteca() {
    delete librosPorIsbn;
}

void Biblioteca::extraerLibrosArchivo(std::string &ruta) {
    LectorArchivo lector;
    lector.leerArchivo(ruta, this);
    std::cout << librosPorIsbn->getNumElementos() << std::endl;
}

void Biblioteca::ingresarNuevoLibro(Libro *nuevoLibro) {
    librosPorIsbn->agregarLibro(nuevoLibro);
    librosPorTitulo->agregarLibro(nuevoLibro);
    /**CreadorSvg creeador;
    creeador.crearSvg(obtenerDotArbolAVLPorISBN(), true,
        "prueba"+std::to_string(librosPorIsbn->getNumElementos()));**/
}

std::string Biblioteca::obtenerDotArbolAVLPorISBN() {
    return obtenerDotArbolAVL(librosPorIsbn);
}

std::string Biblioteca::obtenerDotArbolAVLPorTitulo() {
    return obtenerDotArbolAVL(librosPorTitulo);
}
