//
// Created by rafael-cayax on 17/8/25.
//

#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H

template <typename T>
class NodoDoble {
private:
    T* elemento;
    NodoDoble<T>* anterior;
    NodoDoble<T>* siguiente;
public:
    explicit NodoDoble(T* elemento);
    NodoDoble<T>* getAnterior();
    NodoDoble<T>* getSiguiente();
    void setAnterior(NodoDoble<T>* anterior);
    void setSiguiente(NodoDoble<T>* siguiente);
    T* getElemento();
};

#include "NodoDoble.cpp"
#endif //PRACTICA1EDD_NODODOBLE_H