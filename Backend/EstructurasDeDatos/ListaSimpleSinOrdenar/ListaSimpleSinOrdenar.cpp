//
// Created by rafael-cayax on 2/10/25.
//

#include "ListaSimpleSinOrdenar.h"
#include "../ListaOrdenada/ListaOrdenada.h"
#include "../../Iteradores/IteradorListaSimple.h"
#include "NodoSimple/NodoSimple.h"

Libro * ListaSimpleSinOrdenar::eliminar(const std::string &isbn) {
    return nullptr;
}

void ListaSimpleSinOrdenar::agregar(Libro *libro) {
    NodoSimple *nodo = new NodoSimple(libro);
    if (estaVacia()) {
        primero = nodo;
        ultimo = nodo;
    } else {
        ultimo->setSiguiente(nodo);
        ultimo = nodo;
    }
    tamaño++;
}

void ListaSimpleSinOrdenar::copiarLista(ListaOrdenada *lista) {
    IteradorListaSimple iterador = lista->getIterator();
    while (iterador.haySiguiente()) {
        this->agregar(iterador.getActual());
    }
}

IteradorListaSimple ListaSimpleSinOrdenar::getIterator() {
    return IteradorListaSimple(primero);
}
