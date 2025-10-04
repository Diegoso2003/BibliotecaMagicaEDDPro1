//
// Created by rafael-cayax on 30/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLTITULO_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLTITULO_H
#include <string>

#include "../../ArbolAVL/NodoArbol/NodoArbol.h"


class ListaOrdenada;

class NodoArbolTitulo : public NodoArbol {
    ListaOrdenada *libros;
public:
    explicit NodoArbolTitulo(Libro *libro);
    ~NodoArbolTitulo() override;
    Libro *getLibro() const override;
    ListaOrdenada *getLibros() const {return libros;}
    int getCantidad();
    void agregarLibro(Libro *libro);
    void obtenerDotLibro(std::string &dot) override;
};

#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLTITULO_H
