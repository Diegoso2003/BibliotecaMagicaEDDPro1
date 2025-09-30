//
// Created by rafael-cayax on 23/9/25.
//

#include "CreadorTextoDot.h"

#include <iostream>
#include <ostream>

#include "../EstructurasDeDatos/ArbolAVL/NodoArbolIsbn/NodoArbolIsbn.h"
#include "../EstructurasDeDatos/ArbolBFecha/NodoArbolB/NodoArbolB.h"
#include "../EstructurasDeDatos/ArbolBGenero/NodoArbolBMas/NodoArbolBMas.h"
#include "../EstructurasDeDatos/ArbolBGenero/NodoArbolBMasHoja/NodoArbolBMasHoja.h"
#include "../EstructurasDeDatos/ArbolBGenero/NodoArbolBMasInterno/NodoArbolBMasInterno.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include "../Libro/Libro.h"

void CreadorTextoDot::agregarDatosLibroIsbn(std::string &dot, Libro *libro) {
    dot += R"( [label="ISBN: )" + libro->getIsbn() + R"(\n)";
    dot += R"(Titulo: )" + libro->getTitulo() + R"(\n)";
    dot += "Autor: " + libro->getAutor() + R"(\n)";
    dot += "Genero: " + libro->getGenero() + R"(\n)";
    dot += "Año Publicacion: " + std::to_string(libro->getAño()) + R"(\n)";
    dot += "Cantidad: " + std::to_string(libro->getCantidad()) + R"(\n)";
    dot += R"("];)"; dot += "\n";
}

void CreadorTextoDot::agregarDatosLibroTitulo(std::string &dot, NodoArbolTitulo *nodo) {
    Libro *libro = nodo->getLibro();
    dot += R"( [label="Titulo: )" + libro->getTitulo() + R"(\n)";
    dot += "Cantidad: " + std::to_string(nodo->getCantidad()) + R"(\n)";
    dot += R"("];)"; dot += "\n";
}

void CreadorTextoDot::agregarDatosRecursivoPorAño(std::string &dot, NodoArbolB *nodo, int &numNodo) {
    dot += "nodo" + std::to_string(numNodo) + R"( [label=")";
    bool esHoja = nodo->esNodoHoja();
    dot += esHoja ? "" : "<f0> | ";
    ListaSimpleEnlazada** claves = nodo->getClaves();
    NodoArbolB** hijos = nodo->getHijos();
    int numClaves = nodo->getNumeroLibros();
    for (int i = 0; i < numClaves; i++) {
        dot+= std::to_string(claves[i]->getPrimero()->getAño()) + R"(\n)";
        dot+= "C: " +  std::to_string(claves[i]->getTamaño());
        dot+= esHoja ? "" : " | <f" + std::to_string(i+1) + ">";
        dot+= i == numClaves - 1 ? R"("];)" : " | ";
    }
    dot+="\n";
    if (esHoja) return;
    int numeroPadre = numNodo;
    for (int i = 0; i < numClaves+1; i++) {
        int numeroHijo = ++numNodo;
        agregarDatosRecursivoPorAño(dot, hijos[i], numNodo);
        dot+= "nodo" + std::to_string(numeroPadre) + ":f" + std::to_string(i) + " -> ";
        dot+= "nodo" + std::to_string(numeroHijo) + ";\n";
    }
}

void CreadorTextoDot::agregarDatosRecursivoPorGenero(std::string &dot, NodoArbolBMas *nodo, int &numNodo) {
    dot += "nodo" + std::to_string(numNodo) + R"( [label=")";
    bool esHoja = nodo->esNodoHoja();
    dot += esHoja ? "" : "<f0> | ";
    std::string** claves = nodo->getClaves();
    int numClaves = nodo->getNumeroClaves();
    ListaSimpleEnlazada **libros = nullptr;
    if (esHoja) {
        auto *hoja = dynamic_cast<NodoArbolBMasHoja *>(nodo);
        libros = hoja->getElementos();
    }
    for (int i = 0; i < numClaves; i++) {
        dot+= *claves[i];
        if (esHoja)dot+=R"(\nC:)" + std::to_string(libros[i]->getTamaño());
        dot+= esHoja ? "" : " | <f" + std::to_string(i+1) + ">";
        dot+= i == numClaves - 1 ? R"("];)" : " | ";
    }
    dot+="\n";
    if (esHoja) return;
    int numeroPadre = numNodo;
    auto *nodoInterno = dynamic_cast<NodoArbolBMasInterno *>(nodo);
    NodoArbolBMas **hijos = nodoInterno->getHijos();
    for (int i = 0; i <= numClaves; i++) {
        int numeroHijo = ++numNodo;
        agregarDatosRecursivoPorGenero(dot, hijos[i], numNodo);
        dot+= "nodo" + std::to_string(numeroPadre) + ":f" + std::to_string(i) + " -> ";
        dot+= "nodo" + std::to_string(numeroHijo) + ";\n";
    }
}

std::string CreadorTextoDot::obtenerDotPorAño(NodoArbolB *raiz) {
    if (raiz->getNumeroLibros() == 0) throw EntradaUsuarioException("Arbol vacio, ingrese libros para realizar diagrama");
    std::string dot = R"(digraph ArbolB {
    rankdir=TB;
    graph [ranksep=2, nodesep=1];
    node [shape=record, fillcolor=lightblue, style=filled];)";
    dot+="\n";
    int numNodo = 1;
    agregarDatosRecursivoPorAño(dot, raiz, numNodo);
    dot += "}";
    std::cout << dot << std::endl;
    return dot;
}

std::string CreadorTextoDot::obtenerDotPorGenero(NodoArbolBMas *raiz) {
    std::string dot = R"(digraph ArbolBGenero {
    rankdir=TB;
    graph [ranksep=3, nodesep=0.5];
    node [shape=record, fillcolor=lightblue, style=filled];)";
    dot+="\n";
    int numNodo = 1;
    agregarDatosRecursivoPorGenero(dot, raiz, numNodo);
    dot += "}";
    std::cout << dot << std::endl;
    return dot;
}

void CreadorTextoDot::agregarDatosRecursivoAVL(std::string &dot, NodoArbol *nodo, bool isbn) {
    std::string pl = "Libro";
    Libro *libro = nodo->getLibro();
    dot += pl + libro->getSinGuiones();
    if (isbn) agregarDatosLibroIsbn(dot, libro);
    else agregarDatosLibroTitulo(dot, dynamic_cast<NodoArbolTitulo *>(nodo));
    if (nodo->getDerecha()!= nullptr || nodo->getIzquierda()!= nullptr) {
        std::string auxiliar2 = pl + libro->getSinGuiones() + " -> {";
        std::string auxiliar = "{ rank=same; ";
        if (nodo->getIzquierda() != nullptr) {
            agregarDatosRecursivoAVL(dot, nodo->getIzquierda(), isbn);
            auxiliar2 += pl + nodo->getIzquierda()->getLibro()->getSinGuiones() + " ";
            auxiliar += pl + nodo->getIzquierda()->getLibro()->getSinGuiones() + "; ";
        }
        if (nodo->getDerecha() != nullptr) {
            agregarDatosRecursivoAVL(dot, nodo->getDerecha(), isbn);
            auxiliar2 += pl+nodo->getDerecha()->getLibro()->getSinGuiones();
            auxiliar += pl+nodo->getDerecha()->getLibro()->getSinGuiones() + ";";
        }
        auxiliar += "}\n";
        auxiliar2 += "}\n";
        dot += auxiliar2;
        dot+= auxiliar;
    }
}

std::string CreadorTextoDot::obtenerDotArbolAvl(NodoArbol *raiz, bool isbn) {
    std::string elementos = R"(digraph G {
        rankdir=TB;
        graph [ranksep=1, nodesep=0.5];
        node [shape=box, style=filled, color=lightblue, fontsize=10];)";
    elementos += "\n";
    agregarDatosRecursivoAVL(elementos, raiz, isbn);
    elementos += "}";
    return elementos;
}

std::string CreadorTextoDot::obtenerDotPorIsbn(NodoArbol *raiz) {
    return obtenerDotArbolAvl(raiz, true);
}

std::string CreadorTextoDot::obtenerDotPorTitulo(NodoArbol *raiz) {
    return obtenerDotArbolAvl(raiz, false);
}
