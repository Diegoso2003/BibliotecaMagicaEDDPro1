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
    void correrElementos(int posicion);
public:
    explicit NodoArbolBMasHoja(int ordenArbol);
    ~NodoArbolBMasHoja() override;
    void agregarElemento(Libro *libro) override;
    bool esNodoHoja() const override;
    ListaOrdenada **getElementos() {return elementos;}
    std::string *getClaveMedia() override;
    std::string * prestarDerecha(NodoArbolBMas *nodo, std::string *clavePadre) override;
    std::string * prestarIzquierda(NodoArbolBMas *nodo, std::string *clavePadre) override;
    void fusionar(NodoArbolBMas *nodo, std::string *clavePadre) override;
    NodoArbolBMas *getNuevoDer() override;
    void eliminarLibro(Libro *libro) override;
    ListaOrdenada *buscarElemento(std::string &genero) override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASHOJA_H