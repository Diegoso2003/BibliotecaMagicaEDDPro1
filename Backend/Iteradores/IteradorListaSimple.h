//
// Created by rafael-cayax on 30/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ITERADORLISTASIMPLE_H
#define BIBLIOTECAMAGICAEDDPRO1_ITERADORLISTASIMPLE_H


class Libro;
class NodoSimple;

class IteradorListaSimple {
    NodoSimple *actual;
    NodoSimple *auxiliar;
public:
    explicit IteradorListaSimple(NodoSimple *nodo);
    bool haySiguiente();
    Libro *getActual();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_ITERADORLISTASIMPLE_H