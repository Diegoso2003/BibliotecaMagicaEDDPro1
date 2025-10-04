//
// Created by rafael-cayax on 3/10/25.
//

#include "NodoDoble.h"

NodoDoble::NodoDoble(Libro *libro) : NodoSimple(libro){
    anterior = nullptr;
}

void NodoDoble::setAnterior(NodoDoble *anter) {
    this->anterior = anter;
}

NodoDoble * NodoDoble::getAnterior() {
    return anterior;
}

NodoDoble * NodoDoble::getSiguiente() {
    return dynamic_cast<NodoDoble *>(siguiente);
}
