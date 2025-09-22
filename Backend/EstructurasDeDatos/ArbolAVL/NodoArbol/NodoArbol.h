//
// Created by rafael-cayax on 16/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H

class Libro;

class NodoArbol {
private:
    NodoArbol* izquierda;
    NodoArbol* derecha;
    Libro* libro;
    int Fe = 0;
public:
    explicit NodoArbol(Libro* libro);
    void setDerecha(NodoArbol* der);
    void setIzquierda(NodoArbol* izq);
    NodoArbol*& getDerecha(){return derecha;}
    NodoArbol*& getIzquierda(){return izquierda;}
    Libro* getLibro() const { return libro; }
    [[nodiscard]] int getFe() const {return Fe;}
    void setFe(int fe){this->Fe = fe;}
};

#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H