//
// Created by rafael-cayax on 30/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLTITULO_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLTITULO_H
#include "../NodoArbol/NodoArbol.h"


class ListaSimpleEnlazada;

class NodoArbolTitulo : public NodoArbol {
    ListaSimpleEnlazada *libros;
public:
    explicit NodoArbolTitulo(Libro *libro);
    ~NodoArbolTitulo() override;
    Libro *getLibro() const override;
    int getCantidad();
    void agregarLibro(Libro *libro);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLTITULO_H