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
    NodoArbol *crearNuevoNodo(Libro *libro) override;
    void tratarLibroDuplicado(NodoArbol *nodo, Libro *&libro) override;
public:
    std::string obtenerDotArbol() override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLPORISBN_H