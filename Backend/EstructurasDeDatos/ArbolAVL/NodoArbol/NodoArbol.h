//
// Created by rafael-cayax on 16/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H

#include <string>
class Libro;

class NodoArbol {
protected:
    NodoArbol* izquierda = nullptr;
    NodoArbol* derecha = nullptr;
    bool esNodoHoja();
private:
    int Fe = 0;
public:
    virtual ~NodoArbol() = default;
    void setDerecha(NodoArbol* der);
    void setIzquierda(NodoArbol* izq);
    NodoArbol* getDerecha(){return derecha;}
    NodoArbol* getIzquierda(){return izquierda;}
    virtual Libro *getLibro() const = 0;
    virtual void obtenerDotLibro(std::string &dot) = 0;
    [[nodiscard]] int getFe() const {return Fe;}
    void setFe(int fe){this->Fe = fe;}
};

#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOL_H