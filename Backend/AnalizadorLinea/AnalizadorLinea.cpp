//
// Created by rafael-cayax on 15/9/25.
//

#include "AnalizadorLinea.h"
#include <regex>

#include "../Auxiliar/Auxiliar.h"
#include "../Biblioteca/Biblioteca.h"
#include "../Excepciones/EntradaUsuarioException.h"
#include "../Libro/Libro.h"

void AnalizadorLinea::analizarLinea(const std::string &linea, Biblioteca *biblioteca) {
    lineaActual++;
    Libro *libro = nullptr;
    if (linea.empty()) return;
    try {
        extraerCampos(linea);
        validarCampos();
        libro = crearLibro();
        biblioteca->ingresarNuevoLibro(libro);
    } catch (const std::exception &e) {
        delete libro;
        hayError = true;
        mensajeError += "Error en la linea: "
                + std::to_string(lineaActual) + "\n"
                + e.what() + " " + linea + "\n";
    }
}

void AnalizadorLinea::extraerCampos(const std::string &linea) {
    size_t start = 0;
    size_t end = 0;
    size_t field = 0;
    bool in_quotes = false;

    titulo.clear(); isbn.clear(); genero.clear(); fecha.clear(); autor.clear();

    for (size_t i = 0; i < linea.size() && field < 5; i++) {
        if (linea[i] == '"') {
            in_quotes = !in_quotes;
            if (!in_quotes) {
                size_t field_start = start;
                while (field_start < i && std::isspace(linea[field_start])) field_start++;
                size_t field_end = i;
                while (field_end > field_start && std::isspace(linea[field_end-1])) field_end--;

                std::string field_value = linea.substr(field_start, field_end - field_start);

                switch (field) {
                    case 0: titulo = field_value; break;
                    case 1: isbn = field_value; break;
                    case 2: genero = field_value; break;
                    case 3: fecha = field_value; break;
                    case 4: autor = field_value; break;
                }
                field++;
            }
            start = i + 1;
        } else if (linea[i] == ',' && !in_quotes) {
            start = i + 1;
        }
    }

    if (field != 5) {
        throw EntradaUsuarioException("Formato invalido - se esperaban 5 campos entre comillas");
    }
}

void AnalizadorLinea::validarCampos() {
    Auxiliar::eliminarEspaciosIntermedio(titulo);
    Auxiliar::eliminarEspaciosIntermedio(genero);
    Auxiliar::eliminarEspaciosIntermedio(autor);
    if (titulo.empty() || autor.empty() || genero.empty()) {
        throw EntradaUsuarioException("ingresar campos validos");
    }

    if (fecha.size() != 4 ||
        !std::all_of(fecha.begin(), fecha.end(), ::isdigit) ||
        fecha[0] == '0') {
        throw EntradaUsuarioException("Año invalido: " + fecha);
        }

    int year = std::stoi(fecha);
    if (year < 1000 || year > 9999) {
        throw EntradaUsuarioException("Año fuera de rango: " + fecha);
    }

    std::string isbn_clean;
    int guionesMaximos = 4;
    int guiones = 0;
    for (char c : isbn) {
        if (std::isdigit(c)) {
            isbn_clean += c;
        } else if (c == '-') {
            guiones++;
        } else {
            throw EntradaUsuarioException("ISBN invalido: " + isbn);
        }
    }

    if (guiones > guionesMaximos) {
        throw EntradaUsuarioException("ISBN invalido: " + isbn);
    }

    if (isbn_clean.size() != 13 ||
        (isbn_clean.substr(0, 3) != "978" && isbn_clean.substr(0, 3) != "979")) {
        throw EntradaUsuarioException("ISBN invalido: " + isbn);
        }
}

Libro *AnalizadorLinea::crearLibro() {
    auto *libro = new Libro();
    libro->setAutor(autor);
    libro->setIsbn(isbn);
    libro->setGenero(genero);
    libro->setTitulo(titulo);
    libro->setAño(std::stoi(fecha));
    return libro;
}
