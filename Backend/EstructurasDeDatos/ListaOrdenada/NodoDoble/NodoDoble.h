//
// Created by rafael-cayax on 3/10/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODODOBLE_H
#define BIBLIOTECAMAGICAEDDPRO1_NODODOBLE_H
#include "../../ListaSimpleSinOrdenar/NodoSimple/NodoSimple.h"


class Libro;

class NodoDoble : public NodoSimple{
    NodoDoble *anterior;
public:
    explicit NodoDoble(Libro *libro);
    void setAnterior(NodoDoble *anter);
    NodoDoble *getAnterior();
    NodoDoble *getSiguiente() override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODODOBLE_H