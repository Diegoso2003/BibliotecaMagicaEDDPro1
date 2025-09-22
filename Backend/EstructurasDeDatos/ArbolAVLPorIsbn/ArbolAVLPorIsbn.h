//
// Created by rafael-cayax on 19/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLPORISBN_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLPORISBN_H
#include "../ArbolAVL/ArbolAVL.h"


class ArbolAVLPorIsbn : public ArbolAVL{
private:
    bool agregarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) override;
    bool agregarSubArbolIzquierdo(NodoArbol *&actual, Libro *&libro) override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLPORISBN_H