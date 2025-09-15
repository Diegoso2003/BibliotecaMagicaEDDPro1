//
// Created by rafael-cayax on 17/8/25.
//

#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H

template <typename T>
class NodoSimple {
private:
    T* elemento;
    NodoSimple<T>* siguiente;
public:
    explicit NodoSimple(T* elemento);
    NodoSimple<T>* getSiguiente();
    void setSiguiente(NodoSimple<T>* siguiente);
    T* getElemento();
};

#include "NodoSimple.cpp"
#endif //PRACTICA1EDD_NODODOBLE_H