//
// Created by rafael-cayax on 15/9/25.
//

#include "Biblioteca.h"

#include "../Libro/Libro.h"
#include "../AnalizadorLinea/AnalizadorLinea.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include <iostream>

#include "../LectorArchivo/LectorArchivo.h"

void Biblioteca::agregarLibros(std::string &libros, NodoArbol<Libro> *nodo) {
    std::string pl = "Libro";
    Libro *libro = nodo->getElemento();
    libros += pl + libro->getSinGuiones();
    libros += R"( [label="ISBN: )" + libro->getIsbn() + R"(\n)";
    libros += R"(Titulo: )" + libro->getTitulo() + R"(\n)";
    libros += "Autor: " + libro->getAutor() + R"(\n)";
    libros += "Genero: " + libro->getGenero() + R"(\n)";
    libros += "Año Publicacion: " + libro->getAño() + R"(\n)";
    libros += R"("];)"; libros += "\n";
    if (nodo->getDerecha()!= nullptr || nodo->getIzquierda()!= nullptr) {
        std::string auxiliar2 = pl + libro->getSinGuiones() + " -> {";
        std::string auxiliar = "{ rank=same; ";
        if (nodo->getIzquierda() != nullptr) {
            agregarLibros(libros, nodo->getIzquierda());
            auxiliar2 += pl + nodo->getIzquierda()->getElemento()->getSinGuiones() + " ";
            auxiliar += pl + nodo->getIzquierda()->getElemento()->getSinGuiones() + "; ";
        }
        if (nodo->getDerecha() != nullptr) {
            agregarLibros(libros, nodo->getDerecha());
            auxiliar2 += pl+nodo->getDerecha()->getElemento()->getSinGuiones();
            auxiliar += pl+nodo->getDerecha()->getElemento()->getSinGuiones() + ";";
        }
        auxiliar += "}\n";
        auxiliar2 += "}\n";
        libros += auxiliar2;
        libros+= auxiliar;
    }
}

Biblioteca::Biblioteca() {
    librosPorIsbn = new ArbolAVL<Libro>(false);
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
    Libro::ordenarPorISBN();
    librosPorIsbn->agregarElemento(nuevoLibro);
}

std::string Biblioteca::obtenerDotArbolAVLPorISBN() {
    if (librosPorIsbn->estaVacia()) throw EntradaUsuarioException("arbol vacio, ingrese datos para visualizar grafica");
    NodoArbol<Libro> *raiz = librosPorIsbn->getRaiz();
    std::string elementos = R"(digraph G {
        rankdir=TB;
        graph [ranksep=1, nodesep=0.5];
        node [shape=box, style=filled, color=lightblue, fontsize=10];)";
    elementos += "\n";
    agregarLibros(elementos, raiz);
    elementos += "}";
    return elementos;
}
