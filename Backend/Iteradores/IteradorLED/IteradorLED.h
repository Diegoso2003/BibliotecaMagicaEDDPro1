//
// Created by rafael-cayax on 20/8/25.
//

#ifndef PRACTICA1EDD_ITERADORLED_H
#define PRACTICA1EDD_ITERADORLED_H
template<typename T>
class NodoSimple;

template<typename T>
class IteradorLED {
private:
    NodoSimple<T> *actual;
public:
    IteradorLED(NodoSimple<T> *actual);
    bool haySiguiente();
    T *getActual();
};

#include "IteradorLED.cpp"
#endif //PRACTICA1EDD_ITERADORLED_H