//
// Created by rafael-cayax on 28/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASHOJA_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASHOJA_H
#include "../../ListaOrdenada/ListaOrdenada.h"
#include "../NodoArbolBMas/NodoArbolBMas.h"


class Libro;
class ListaOrdenada;

class NodoArbolBMasHoja : public NodoArbolBMas{
private:
    ListaOrdenada **elementos;
    void intercambiarElementos(ListaOrdenada *&nuevo, ListaOrdenada *&viejo);
public:
    explicit NodoArbolBMasHoja(int ordenArbol);
    ~NodoArbolBMasHoja();
    void agregarElemento(Libro *libro);
    bool esNodoHoja() const override;
    ListaOrdenada **getElementos() {return elementos;}
    std::string *getClaveMedia() override;
    NodoArbolBMas *getNuevoDer() override;
    ListaOrdenada *buscarElemento(std::string &genero) override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASHOJA_H