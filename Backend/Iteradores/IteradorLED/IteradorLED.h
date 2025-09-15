//
// Created by rafael-cayax on 20/8/25.
//

#ifndef PRACTICA1EDD_ITERADORLED_H
#define PRACTICA1EDD_ITERADORLED_H
#include "../../estructuras_de_datos/ListaEnlazadaDoble/NodoDoble.h"

template<typename T>
class IteradorLED {
private:
    NodoDoble<T> *actual;
public:
    IteradorLED(NodoDoble<T> *actual);
    bool haySiguiente(){return actual != nullptr;}
    T *getActual();
};

#include "IteradorLED.cpp"
#endif //PRACTICA1EDD_ITERADORLED_H