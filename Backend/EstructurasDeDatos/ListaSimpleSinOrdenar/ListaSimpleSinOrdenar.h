//
// Created by rafael-cayax on 2/10/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_LISTASIMPLESINORDENAR_H
#define BIBLIOTECAMAGICAEDDPRO1_LISTASIMPLESINORDENAR_H
#include "../ListaSimple/ListaSimpleEnlazada.h"


class ListaSimpleSinOrdenar : public ListaSimpleEnlazada{
public:
    Libro * eliminar(const std::string &isbn) override;
    void agregar(Libro *libro) override;
    void copiarLista(ListaSimpleEnlazada *lista);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_LISTASIMPLESINORDENAR_H