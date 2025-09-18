//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_BIBLIOTECA_H
#define BIBLIOTECAMAGICAEDDPRO1_BIBLIOTECA_H
#include <string>

#include "../EstructurasDeDatos/ArbolAVL/ArbolAVL.h"
#include "../Libro/Libro.h"

class Biblioteca {
private:
    ArbolAVL<Libro> *librosPorIsbn;
    void agregarLibros(std::string &libros, NodoArbol<Libro> *nodo);
public:
    Biblioteca();
    ~Biblioteca();
    void extraerLibrosArchivo(std::string& ruta);
    void ingresarNuevoLibro(Libro *nuevoLibro);
    std::string obtenerDotArbolAVLPorISBN();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_BIBLIOTECA_H