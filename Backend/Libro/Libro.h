//
// Created by rafael-cayax on 14/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_LIBRO_H
#define BIBLIOTECAMAGICAEDDPRO1_LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string isbn;
    std::string isbnSinGuiones;
    std::string genero;
    std::string autor;
    int año = 0;
    int cantidad = 1;
public:
    bool esLibroIgual(Libro *libro);
    void setTitulo(const std::string &nuevoTitulo){this-> titulo = nuevoTitulo;}
    void setIsbn(const std::string &nuevoIsbn);
    void setGenero(const std::string &nuevoGenero){this->genero = nuevoGenero;}
    void setAutor(const std::string &nuevoAutor){this->autor = nuevoAutor;}
    void setAño(int nuevoAño){this->año = nuevoAño;}
    void aumentarCantidad(){cantidad++;}
    [[nodiscard]] std::string getTitulo() const {return this->titulo;}
    [[nodiscard]] std::string getIsbn() const {return this->isbn;}
    [[nodiscard]] std::string getGenero() const {return this->genero;}
    [[nodiscard]] std::string getAutor() const {return this->autor;}
    [[nodiscard]] int getAño() const {return this->año;}
    int getCantidad() const {return this->cantidad;}
    [[nodiscard]] std::string getSinGuiones() const {return this->isbnSinGuiones;}
};


#endif //BIBLIOTECAMAGICAEDDPRO1_LIBRO_H