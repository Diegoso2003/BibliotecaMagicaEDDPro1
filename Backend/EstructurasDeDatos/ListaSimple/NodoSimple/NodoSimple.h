//
// Created by rafael-cayax on 17/8/25.
//

#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H

class Libro;

class NodoSimple {
private:
    Libro *libro;
    NodoSimple* siguiente;
public:
    explicit NodoSimple(Libro* libro);
    ~NodoSimple();
    NodoSimple* getSiguiente();
    void setSiguiente(NodoSimple* siguiente);
    Libro* getLibro();
};

#endif //PRACTICA1EDD_NODODOBLE_H