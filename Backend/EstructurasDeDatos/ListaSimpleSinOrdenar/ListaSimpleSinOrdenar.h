//
// Created by rafael-cayax on 2/10/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_LISTASIMPLESINORDENAR_H
#define BIBLIOTECAMAGICAEDDPRO1_LISTASIMPLESINORDENAR_H
#include "../ListaOrdenada/ListaOrdenada.h"


class ListaSimpleSinOrdenar : public ListaOrdenada{
private:
    NodoSimple *primero = nullptr;
    NodoSimple *ultimo = nullptr;
public:
    Libro * eliminar(const std::string &isbn) override;
    void agregar(Libro *libro) override;
    void copiarLista(ListaOrdenada *lista);
    IteradorListaSimple getIterator() override;
};


#endif //BIBLIOTECAMAGICAEDDPRO1_LISTASIMPLESINORDENAR_H