//
// Created by rafael-cayax on 14/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_LIBRO_H
#define BIBLIOTECAMAGICAEDDPRO1_LIBRO_H

#include <string>

class Libro {
private:
    inline static bool ordenTitulo = true;
    inline static bool ordenISBN = false;
    std::string titulo;
    std::string isbn;
    std::string isbnSinGuiones;
    std::string genero;
    std::string año;
    std::string autor;
public:
    static void ordenarPorISBN();
    static void ordenarTitulo();
    bool operator ==(const Libro &other) const;
    bool operator !=(const Libro &other) const;
    bool operator <(const Libro &other) const;
    bool operator >(const Libro& other) const;
    bool operator >=(const Libro& other) const;
    bool operator <=(const Libro& other) const;
    void ordenarPorTitulo();
    void setTitulo(const std::string &nuevoTitulo){this-> titulo = nuevoTitulo;}
    void setIsbn(const std::string &nuevoIsbn);
    void setGenero(const std::string &nuevoGenero){this->genero = nuevoGenero;}
    void setAutor(const std::string &nuevoAutor){this->autor = nuevoAutor;}
    void setAño(const std::string &nuevoAño){this->año = nuevoAño;}
    std::string getTitulo(){return this->titulo;}
    std::string getIsbn(){return this->isbn;}
    std::string getGenero(){return this->genero;}
    std::string getAutor(){return this->autor;}
    std::string getAño(){return this->año;}
    std::string getSinGuiones(){return this->isbnSinGuiones;}
};


#endif //BIBLIOTECAMAGICAEDDPRO1_LIBRO_H