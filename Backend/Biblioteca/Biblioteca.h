//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_BIBLIOTECA_H
#define BIBLIOTECAMAGICAEDDPRO1_BIBLIOTECA_H
#include <string>

#include "../EstructurasDeDatos/ArbolAVLPorIsbn/ArbolAVLPorIsbn.h"
#include "../EstructurasDeDatos/ArbolAVLTitulo/ArbolAVLTitulo.h"
#include "../EstructurasDeDatos/ArbolBFecha/ArbolBFecha.h"
#include "../EstructurasDeDatos/ArbolBGenero/ArbolBGenero.h"
#include "../Libro/Libro.h"

class Biblioteca {
private:
    ArbolAVLPorIsbn *librosPorIsbn;
    ArbolAVLTitulo *librosPorTitulo;
    ArbolBFecha *librosPorFecha;
    ArbolBGenero *librosPorGenero;
    void agregarLibros(std::string &libros, NodoArbol *nodo);
    std::string obtenerDotArbolAVL(ArbolAVL *arbol);
public:
    Biblioteca();
    ~Biblioteca();
    void extraerLibrosArchivo(std::string& ruta);
    void ingresarNuevoLibro(Libro *nuevoLibro);
    std::string obtenerDotArbolAVLPorISBN();
    std::string obtenerDotArbolAVLPorTitulo();
    std::string obtenerDotArbolBFecha();
    std::string obtenerDotArbolBMasGenero();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_BIBLIOTECA_H