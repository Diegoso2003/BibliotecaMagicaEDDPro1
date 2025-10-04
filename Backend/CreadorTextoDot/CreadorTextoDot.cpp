//
// Created by rafael-cayax on 23/9/25.
//

#include "CreadorTextoDot.h"

#include <iostream>
#include <ostream>

#include "../EstructurasDeDatos/ArbolAVL/NodoArbol/NodoArbol.h"
#include "../EstructurasDeDatos/ArbolBFecha/NodoArbolB/NodoArbolB.h"
#include "../EstructurasDeDatos/ArbolBGenero/NodoArbolBMas/NodoArbolBMas.h"
#include "../EstructurasDeDatos/ArbolBGenero/NodoArbolBMasHoja/NodoArbolBMasHoja.h"
#include "../EstructurasDeDatos/ArbolBGenero/NodoArbolBMasInterno/NodoArbolBMasInterno.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include "../Libro/Libro.h"

void CreadorTextoDot::agregarDatosRecursivoPorAño(std::string &dot, NodoArbolB *nodo, int &numNodo) {
    dot += "nodo" + std::to_string(numNodo) + R"( [label=")";
    bool esHoja = nodo->esNodoHoja();
    dot += esHoja ? "" : "<f0> | ";
    ListaOrdenada **claves = nodo->getClaves();
    NodoArbolB **hijos = nodo->getHijos();
    int numClaves = nodo->getNumeroLibros();
    for (int i = 0; i < numClaves; i++) {
        dot += std::to_string(claves[i]->getPrimero()->getAño()) + R"(\n)";
        dot += "C: " + std::to_string(claves[i]->getTamaño());
        dot += esHoja ? "" : " | <f" + std::to_string(i + 1) + ">";
        dot += i == numClaves - 1 ? R"("];)" : " | ";
    }
    dot += "\n";
    if (esHoja) return;
    int numeroPadre = numNodo;
    for (int i = 0; i < numClaves + 1; i++) {
        int numeroHijo = ++numNodo;
        agregarDatosRecursivoPorAño(dot, hijos[i], numNodo);
        dot += "nodo" + std::to_string(numeroPadre) + ":f" + std::to_string(i) + " -> ";
        dot += "nodo" + std::to_string(numeroHijo) + ";\n";
    }
}

void CreadorTextoDot::agregarDatosRecursivoPorGenero(std::string &dot, NodoArbolBMas *nodo, int &numNodo) {
    dot += "nodo" + std::to_string(numNodo) + R"( [label=")";
    bool esHoja = nodo->esNodoHoja();
    dot += esHoja ? "" : "<f0> | ";
    std::string **claves = nodo->getClaves();
    int numClaves = nodo->getNumeroClaves();
    ListaOrdenada **libros = nullptr;
    if (esHoja) {
        auto *hoja = dynamic_cast<NodoArbolBMasHoja *>(nodo);
        libros = hoja->getElementos();
    }
    for (int i = 0; i < numClaves; i++) {
        dot += *claves[i];
        if (esHoja)dot += R"(\nC:)" + std::to_string(libros[i]->getTamaño());
        dot += esHoja ? "" : " | <f" + std::to_string(i + 1) + ">";
        dot += i == numClaves - 1 ? R"("];)" : " | ";
    }
    dot += "\n";
    if (esHoja) return;
    int numeroPadre = numNodo;
    auto *nodoInterno = dynamic_cast<NodoArbolBMasInterno *>(nodo);
    NodoArbolBMas **hijos = nodoInterno->getHijos();
    for (int i = 0; i <= numClaves; i++) {
        int numeroHijo = ++numNodo;
        agregarDatosRecursivoPorGenero(dot, hijos[i], numNodo);
        dot += "nodo" + std::to_string(numeroPadre) + ":f" + std::to_string(i) + " -> ";
        dot += "nodo" + std::to_string(numeroHijo) + ";\n";
    }
}

std::string CreadorTextoDot::obtenerDotPorAño(NodoArbolB *raiz) {
    if (raiz->getNumeroLibros() == 0) throw EntradaUsuarioException(
        "Arbol vacio, ingrese libros para realizar diagrama");
    std::string dot = R"(digraph ArbolB {
    rankdir=TB;
    graph [ranksep=2, nodesep=1];
    node [shape=record, fillcolor=lightblue, style=filled];)";
    dot += "\n";
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
    dot += "\n";
    int numNodo = 1;
    agregarDatosRecursivoPorGenero(dot, raiz, numNodo);
    dot += "}";
    std::cout << dot << std::endl;
    return dot;
}

void CreadorTextoDot::agregarDatosRecursivoAVL(std::string &dot, NodoArbol *nodo) {
    std::string pl = "Libro";
    Libro *libro = nodo->getLibro();
    dot += pl + libro->getSinGuiones();
    nodo->obtenerDotLibro(dot);
    if (nodo->getIzquierda() != nullptr) {
        agregarDatosRecursivoAVL(dot, nodo->getIzquierda());
        dot += pl + libro->getSinGuiones() + ":f0 -> ";
        dot += pl + nodo->getIzquierda()->getLibro()->getSinGuiones() + ";\n";
    }
    if (nodo->getDerecha() != nullptr) {
        agregarDatosRecursivoAVL(dot, nodo->getDerecha());
        dot += pl + libro->getSinGuiones() + ":f1 -> ";
        dot += pl + nodo->getDerecha()->getLibro()->getSinGuiones() + ";\n";
    }
}

std::string CreadorTextoDot::obtenerDotArbolAvl(NodoArbol *raiz) {
    std::string elementos = R"(digraph G {
        rankdir=TB;
        graph [ranksep=2, nodesep=1];
        node [shape=record, fillcolor=lightblue, style=filled];)";
    elementos += "\n";
    agregarDatosRecursivoAVL(elementos, raiz);
    elementos += "}";
    std::cout << elementos << std::endl;
    return elementos;
}
