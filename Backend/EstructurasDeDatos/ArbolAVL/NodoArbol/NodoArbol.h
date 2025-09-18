//
// Created by rafael-cayax on 16/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H

template<typename T>
class NodoArbol {
private:
    NodoArbol<T>* izquierda;
    NodoArbol<T>* derecha;
    T* elemento;
    int Fe = 0;
public:
    explicit NodoArbol(T* elemento);
    void setDerecha(NodoArbol<T>* der);
    void setIzquierda(NodoArbol<T>* izq);
    NodoArbol<T>*& getDerecha(){return derecha;}
    NodoArbol<T>*& getIzquierda(){return izquierda;}
    T* getElemento(){return elemento;}
    [[nodiscard]] int getFe() const {return Fe;}
    void setFe(int fe){this->Fe = fe;}
};

#include "NodoArbol.cpp"
#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H