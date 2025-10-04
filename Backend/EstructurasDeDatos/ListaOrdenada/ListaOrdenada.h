//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#include <string>

class NodoSimple;
class Libro;
class NodoDoble;
class IteradorListaSimple;

class ListaOrdenada {
protected:
    int tamaño;
private:
    NodoDoble* primero;
    NodoDoble* ultimo;
    NodoDoble* eliminarNodo(const std::string &isbn, Libro *&libro,  NodoSimple* nodo);
    bool debeBuscarAlPrincipio(const std::string &nuevoDato);
    void buscarDesdePrincipio(NodoDoble *nuevo);
    void buscarDesdeFinal(NodoDoble *nuevo);
public:
    ListaOrdenada();
    virtual ~ListaOrdenada();
    bool estaVacia() const;
    virtual void agregar(Libro* libro);
    virtual Libro* eliminar(const std::string &isbn);
    Libro* getPrimero();
    int getTamaño() const;
    virtual IteradorListaSimple getIterator();
};

#endif //PRACTICA1EDD_LISTADOBLEENLAZADA_H