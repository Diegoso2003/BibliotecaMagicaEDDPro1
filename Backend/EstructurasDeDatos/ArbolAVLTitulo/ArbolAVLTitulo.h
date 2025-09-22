//
// Created by rafael-cayax on 19/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLTITULO_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLTITULO_H
#include "../ArbolAVL/ArbolAVL.h"


class ArbolAVLTitulo : public ArbolAVL{
private:
    bool agregarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) override;
    bool agregarSubArbolIzquierdo(NodoArbol *&actual, Libro *&libro) override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLTITULO_H