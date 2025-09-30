//
// Created by rafael-cayax on 28/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASHOJA_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASHOJA_H
#include "../../ListaSimple/ListaSimpleEnlazada.h"
#include "../NodoArbolBMas/NodoArbolBMas.h"


class Libro;
class ListaSimpleEnlazada;

class NodoArbolBMasHoja : public NodoArbolBMas{
private:
    ListaSimpleEnlazada **elementos;
    void intercambiarElementos(ListaSimpleEnlazada *&nuevo, ListaSimpleEnlazada *&viejo);
public:
    explicit NodoArbolBMasHoja(int ordenArbol);
    ~NodoArbolBMasHoja();
    void agregarElemento(Libro *libro);
    bool esNodoHoja() const override;
    ListaSimpleEnlazada **getElementos() {return elementos;}
    std::string *getClaveMedia() override;
    NodoArbolBMas *getNuevoDer() override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASHOJA_H