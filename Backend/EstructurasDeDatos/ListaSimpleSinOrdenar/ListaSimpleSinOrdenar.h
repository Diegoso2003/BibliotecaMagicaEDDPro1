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
    void eliminar(const std::string &isbn) override;
    void agregar(Libro *libro) override;
    void copiarLista(ListaOrdenada *lista);
    IteradorListaSimple getIterator() override;
    ListaSimpleSinOrdenar *getLibrosPorTitulo(const std::string & busqueda);

    Libro *buscarLibro(const std::string & isbn);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_LISTASIMPLESINORDENAR_H