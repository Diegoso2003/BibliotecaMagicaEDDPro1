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

class Biblioteca {
private:
    ArbolAVLPorIsbn *librosPorIsbn;
    ArbolAVLTitulo *librosPorTitulo;
    ArbolBFecha *librosPorFecha;
    ArbolBGenero *librosPorGenero;
    ListaSimpleSinOrdenar *listaSinOrdenar;
    double tiempoArbol = 0;
    double tiempoLista = 0;
public:
    Biblioteca();
    ~Biblioteca();
    void extraerLibrosArchivo(std::string& ruta);
    void ingresarNuevoLibro(Libro *nuevoLibro);
    void eliminarLibro(Libro *libro);
    std::string obtenerDotArbolAVLPorISBN();
    std::string obtenerDotArbolAVLPorTitulo();
    std::string obtenerDotArbolBFecha();
    std::string obtenerDotArbolBMasGenero();
    Libro *buscarLibroPorIsbn(const std::string& isbn);
    ListaOrdenada *buscarLibroPorTitulo(std::string& titulo);
    ListaOrdenada *buscarLibroPorGenero(std::string& genero);
    ListaOrdenada *obtenerLibrosEnOrdenAlfabetico();
    ListaOrdenada *obtenerLibrosPorFecha(std::string &fechas);
    double getTiempoArbol(){return tiempoArbol;}
    double getTiempoLista(){return tiempoLista;}
};


#endif //BIBLIOTECAMAGICAEDDPRO1_BIBLIOTECA_H