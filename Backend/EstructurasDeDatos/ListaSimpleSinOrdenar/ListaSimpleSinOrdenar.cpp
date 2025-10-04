//
// Created by rafael-cayax on 2/10/25.
//

#include "ListaSimpleSinOrdenar.h"
#include "../ListaOrdenada/ListaOrdenada.h"
#include "../../Iteradores/IteradorListaSimple.h"
#include "../../Libro/Libro.h"
#include "NodoSimple/NodoSimple.h"

void ListaSimpleSinOrdenar::eliminar(const std::string &isbn) {
    NodoSimple *aux = primero;
    if (primero->getLibro()->getSinGuiones() == isbn) {
        primero = primero->getSiguiente();
        aux->setSiguiente(nullptr);
        delete aux;
        tamaño--;
        return;
    }
    NodoSimple *anterior = primero;
    while (aux->getLibro()->getSinGuiones() != isbn) {
        anterior = aux;
        aux = aux->getSiguiente();
    }
    anterior->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nullptr);
    if (aux == ultimo) ultimo = anterior;
    delete aux;
    tamaño--;
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
