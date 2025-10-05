//
// Created by rafael-cayax on 30/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLISBN_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLISBN_H
#include "../../ArbolAVL/NodoArbol/NodoArbol.h"


class Libro;

class NodoArbolIsbn : public NodoArbol{
private:
    Libro *libro;
public:
    explicit NodoArbolIsbn(Libro *libro);
    ~NodoArbolIsbn() override;
    Libro *getLibro() const override;
    void setLibro(Libro *libro);
    void obtenerDotLibro(std::string &dot) override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLISBN_H
