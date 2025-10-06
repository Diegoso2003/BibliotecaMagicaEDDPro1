//
// Created by rafael-cayax on 28/9/25.
//

#include "NodoArbolBMasHoja.h"


#include "../../../Auxiliar/Auxiliar.h"
#include "../../../Libro/Libro.h"
#include "../../ListaOrdenada/ListaOrdenada.h"

void NodoArbolBMasHoja::intercambiarElementos(ListaOrdenada *&nuevo, ListaOrdenada *&viejo) {
    ListaOrdenada *aux = viejo;
    viejo = nuevo;
    nuevo = aux;
}

void NodoArbolBMasHoja::correrElementos(int posicion) {
    for (int i = posicion; i < numeroClaves; i++) {
        intercambiarElementos(elementos[i+1], elementos[i]);
        intercambiarClaves(claves[i+1], claves[i]);
    }
}

NodoArbolBMasHoja::NodoArbolBMasHoja(int ordenArbol)
    : NodoArbolBMas(ordenArbol) {
    elementos = new ListaOrdenada *[max];
    for (int i = 0; i < max; i++) {
        elementos[i] = nullptr;
        claves[i] = nullptr;
    }
}

NodoArbolBMasHoja::~NodoArbolBMasHoja() {
    for (int i = 0; i< numeroClaves; i++) {
        delete claves[i];
        delete elementos[i];
    }
    delete[] elementos;
    delete[] claves;
}

void NodoArbolBMasHoja::agregarElemento(Libro *libro) {
    std::string *aux = nullptr;
    ListaOrdenada *auxElemento = nullptr;
    bool agregado = false;
    numeroClaves++;
    for (int i = 0; i < numeroClaves; i++) {
        if (agregado) {
            intercambiarClaves(aux, claves[i]);
            intercambiarElementos(auxElemento, elementos[i]);
        } else {
            if (claves[i] == nullptr ||
                Auxiliar::textoMinuscula(*claves[i]) > Auxiliar::textoMinuscula(libro->getGenero())) {
                aux = claves[i];
                auxElemento = elementos[i];
                claves[i] = new std::string(libro->getGenero());
                elementos[i] = new ListaOrdenada();
                elementos[i]->agregar(libro);
                agregado = true;
            } else if (Auxiliar::textoMinuscula(*claves[i]) ==
                       Auxiliar::textoMinuscula(libro->getGenero())) {
                elementos[i]->agregar(libro);
                numeroClaves--;
                return;
            }
        }
    }
}

bool NodoArbolBMasHoja::esNodoHoja() const {
    return true;
}

std::string *NodoArbolBMasHoja::getClaveMedia() {
    return new std::string(*claves[ordenArbol]);
}

std::string * NodoArbolBMasHoja::prestarDerecha(NodoArbolBMas *nodo, std::string *clavePadre) {
    delete clavePadre;
    auto *nodoHoja = dynamic_cast<NodoArbolBMasHoja *>(nodo);
    this->elementos[numeroClaves] = nodoHoja->elementos[0];
    this->claves[numeroClaves] = nodoHoja->claves[0];
    numeroClaves++;
    std::string *aux = nodoHoja->claves[1];
    nodoHoja->elementos[0] = nullptr;
    nodoHoja->claves[0] = nullptr;
    nodoHoja->correrElementos(0);
    nodoHoja->numeroClaves--;
    return new std::string(*aux);
}

std::string * NodoArbolBMasHoja::prestarIzquierda(NodoArbolBMas *nodo, std::string *clavePadre) {
    delete clavePadre;
    auto *nodoHoja = dynamic_cast<NodoArbolBMasHoja *>(nodo);
    int ultimoElemento = nodoHoja->numeroClaves-1;
    nodoHoja->numeroClaves--;
    this->numeroClaves++;
    ListaOrdenada *aux = nodoHoja->elementos[ultimoElemento];
    std::string *auxClave = nodoHoja->claves[ultimoElemento];
    std::string *aux2Clave = nodoHoja->claves[ultimoElemento];
    for (int i = 0; i < numeroClaves; i++) {
        intercambiarElementos(aux, elementos[i]);
        intercambiarClaves(auxClave, claves[i]);
    }
    nodoHoja->claves[ultimoElemento] = nullptr;
    return new std::string(*aux2Clave);;
}

void NodoArbolBMasHoja::fusionar(NodoArbolBMas *nodo) {
    auto *nodoHoja = dynamic_cast<NodoArbolBMasHoja *>(nodo);
    int contador = 0;
    for (int i = numeroClaves; i < numeroClaves + nodoHoja->numeroClaves ; i++) {
        this->claves[i] = nodoHoja->claves[contador];
        this->elementos[i] = nodoHoja->elementos[contador];
        nodoHoja->claves[contador] = nullptr;
        nodoHoja->elementos[contador] = nullptr;
        contador++;
    }
    this->numeroClaves += nodoHoja->numeroClaves;
    nodoHoja->numeroClaves = 0;
}

NodoArbolBMas *NodoArbolBMasHoja::getNuevoDer() {
    auto *hoja = new NodoArbolBMasHoja(ordenArbol);
    this->numeroClaves = ordenArbol;
    hoja->numeroClaves = ordenArbol + 1;
    for (int i = 0; i <= ordenArbol; i++) {
        hoja->claves[i] = this->claves[ordenArbol + i];
        hoja->elementos[i] = this->elementos[ordenArbol + i];
        this->claves[ordenArbol + i] = nullptr;
        this->elementos[ordenArbol + i] = nullptr;
    }
    return hoja;
}

void NodoArbolBMasHoja::eliminarLibro(Libro *libro) {
    std::string genero = Auxiliar::textoMinuscula(libro->getGenero());
    ListaOrdenada *aux = nullptr;
    for (int i = 0; i < numeroClaves; ++i) {
        if (genero == Auxiliar::textoMinuscula(*claves[i])) {
            elementos[i]->eliminar(libro->getSinGuiones());
            if (elementos[i]->estaVacia()) {
                delete claves[i];
                claves[i] == nullptr;
                aux = elementos[i];
                numeroClaves--;
                correrElementos(i);
                delete aux;
            }
            break;
        }
    }
}

ListaOrdenada *NodoArbolBMasHoja::buscarElemento(std::string &genero) {
    for (int i = 0; i < numeroClaves; ++i) {
        if (genero == Auxiliar::textoMinuscula(*claves[i])) {
            return elementos[i];
        }
    }
    return nullptr;
}
