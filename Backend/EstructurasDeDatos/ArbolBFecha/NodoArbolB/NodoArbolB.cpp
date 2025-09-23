//
// Created by rafael-cayax on 22/9/25.
//

#include "NodoArbolB.h"

#include "../../../Libro/Libro.h"
#include "../../ListaSimple/ListaSimpleEnlazada.h"

NodoArbolB::NodoArbolB(int ordenArbol) {
    max = 2*ordenArbol+1;
    libros = new ListaSimpleEnlazada *[max];
    hijos = new NodoArbolB *[max];
    for (int i = 0; i < max; i++) {
        libros[i] = nullptr;
        hijos[i] = nullptr;
    }
}

void NodoArbolB::agregarClave(Libro *libro) {
    ListaSimpleEnlazada *aux = nullptr;
    NodoArbolB *nodoAux = nullptr;
    bool agregado = false;
    for (int i = 0; i < numeroLibros; i++) {
        if (agregado) {
            libros[i] = aux;
            aux = libros[i];
        } else {
            if (libros[i]->getPrimero()->getAño() == libro->getAño()) {
                libros[i]->agregar(libro);
                return;
            }
            if (libros[i]->getPrimero()->getAño() > libro->getAño()) {
                aux = libros[i];
                libros[i] = new ListaSimpleEnlazada();
                libros[i]->agregar(libro);
                numeroLibros++;
                agregado = true;
            }
        }
    }
}