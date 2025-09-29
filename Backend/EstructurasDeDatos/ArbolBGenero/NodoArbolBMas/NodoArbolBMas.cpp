//
// Created by rafael-cayax on 28/9/25.
//

#include "NodoArbolBMas.h"

void NodoArbolBMas::intercambiarClaves(std::string *&nuevo, std::string *&viejo) {
    std::string *auxiliar = viejo;
    viejo = nuevo;
    nuevo = auxiliar;
}

NodoArbolBMas::NodoArbolBMas(int ordenArbol) {
    this->ordenArbol = ordenArbol;
    this->max = ordenArbol*2+1;
    claves = new std::string*[max];
}
