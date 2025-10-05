//
// Created by rafael-cayax on 19/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLPORISBN_H
#define BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLPORISBN_H
#include "../ArbolAVL/ArbolAVL.h"


class ArbolAVLPorIsbn : public ArbolAVL{
private:
    bool visitarSubArbolDerecho(NodoArbol *&actual, Libro *&libro) override;
    bool visitarSubArbolIzquierdo(NodoArbol *&actual, Libro *&libro) override;
    NodoArbol *crearNuevoNodo(Libro *libro) override;
    bool eliminarNodo(NodoArbol *nodo, Libro *libro) override;
    void tratarLibroDuplicado(NodoArbol *nodo, Libro *&libro) override;
    void cambiarInformacion(NodoArbol *eliminar, NodoArbol *reemplazo) override;
public:
    Libro *buscarLibro(const std::string &isbn);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ARBOLAVLPORISBN_H