//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
#include "NodoArbol/NodoArbol.h"

/**
 *
 * @tparam T tipo de dato que se almacenara, para clases personalizadas
 * sobrecargar los operadores de comparacion <, >, <=, >= e ==
 */
template<typename T>
class ArbolAVL {
private:
    NodoArbol<T>* raiz;
    const bool duplicados;
    int elementos = 0;
    void reorganizarArbolDerecho(NodoArbol<T> *&nodo);
    void reorganizarArbolIzquierdo(NodoArbol<T> *&nodo);
    void agregarNuevoNodo(NodoArbol<T>*& nodo, T*& nuevoElemento, bool &cambioAlturaArbol);
public:
    explicit ArbolAVL(bool duplicados);
    bool estaVacia(){return elementos == 0;}
    int getNumElementos(){return elementos;}
    void agregarElemento(T* elemento);
    NodoArbol<T>* getRaiz(){return raiz;}
};

#include "ArbolAVL.cpp"
#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVL_H
