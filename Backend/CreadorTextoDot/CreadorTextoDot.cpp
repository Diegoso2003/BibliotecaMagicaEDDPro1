//
// Created by rafael-cayax on 23/9/25.
//

#include "CreadorTextoDot.h"

#include <iostream>
#include <ostream>

#include "../EstructurasDeDatos/ArbolBFecha/NodoArbolB/NodoArbolB.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include "../Libro/Libro.h"

void CreadorTextoDot::agregarDatosRecursivo(std::string &dot, NodoArbolB *nodo, int &numNodo) {
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
        agregarDatosRecursivo(dot, hijos[i], numNodo);
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
    agregarDatosRecursivo(dot, raiz, numNodo);
    dot += "}";
    std::cout << dot << std::endl;
    return dot;
}
