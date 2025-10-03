//
// Created by rafael-cayax on 15/9/25.
//

#include "Auxiliar.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <ostream>

#include "../Excepciones/EntradaUsuarioException.h"

void Auxiliar::trim(std::string &entrada) {
    if (entrada.empty()) return;
    auto rit = std::find_if_not(entrada.rbegin(), entrada.rend(), ::isspace);
    entrada.erase(rit.base(), entrada.end());
    if (entrada.empty()) return;
    auto it = std::find_if_not(entrada.begin(), entrada.end(), ::isspace);
    entrada.erase(entrada.begin(), it);
}

void Auxiliar::eliminarEspaciosIntermedio(std::string &entrada) {
    trim(entrada);
    if (entrada.empty()) return;
    size_t write_pos = 0;
    bool last_was_space = false;

    for (size_t read_pos = 0; read_pos < entrada.size(); ++read_pos) {
        if (std::isspace(static_cast<unsigned char>(entrada[read_pos]))) {
            if (!last_was_space) {
                entrada[write_pos++] = ' ';
                last_was_space = true;
            }
        } else {
            entrada[write_pos++] = entrada[read_pos];
            last_was_space = false;
        }
    }

    entrada.resize(write_pos);
}

std::string Auxiliar::obtenerISBNSinGuion(const std::string &isbn) {
    if (isbn.empty()) return "";
    std::string isbnSinGuiones;
    for (char c : isbn) {
        if (std::isdigit(c)) {
            isbnSinGuiones += c;
        }
    }
    return isbnSinGuiones;
}

std::string Auxiliar::textoMinuscula(std::string texto) {
    std::transform(texto.begin(), texto.end(), texto.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return texto;
}

void Auxiliar::obtenerFechas(const std::string &texto, int fechas[]) {
    std::string año1;
    std::string año2;
    bool primero = true;
    int estado = 1;
    for (char c: texto) {
        switch (estado) {
            case 1:
                if (esNumero(c) && c != '0') {
                    año1 += c;
                    estado = 2;
                } else {
                    estado = 20;
                }
                break;
            case 2:
                if (esNumero(c)) año1 += c;
                else if (c == '-') estado = 3;
                else estado = 20;
                break;
            case 3:
                if (esNumero(c) && c != '0') {
                    año2 += c;
                    estado = 4;
                } else {
                    estado = 20;
                }
                break;
            case 4:
                if (esNumero(c)) año2 += c;
                else estado = 20;
                break;
            default:
                throw EntradaUsuarioException("Formato de busqueda de año invalido");
        }
    }
    if (estado != 2 && estado != 4) throw EntradaUsuarioException("Formato de busqueda de año invalido");
    fechas[0] = std::stoi(año1);
    fechas[1] = año2.empty() ? fechas[0] : std::stoi(año2);
}

bool Auxiliar::esNumero(char c) {
    return c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
    || c == '8' || c == '9' || c == '0';
}
