//
// Created by rafael-cayax on 15/9/25.
//

#include "Auxiliar.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <ostream>

#include "../Excepciones/EntradaUsuarioException.h"

std::string Auxiliar::quitarTildes(const std::string &entrada) {
    std::string resultado;
    resultado.reserve(entrada.length());

    for (size_t i = 0; i < entrada.length(); ) {
        unsigned char c = static_cast<unsigned char>(entrada[i]);

        if (c == 0xC3 && i + 1 < entrada.length()) {
            unsigned char next = static_cast<unsigned char>(entrada[i + 1]);
            if (next == 0xA1 || next == 0xA0 || next == 0xA4 || next == 0xA2) {
                resultado += 'a';
            } else if (next == 0x81 || next == 0x80 || next == 0x84 || next == 0x82) {
                resultado += 'A';
            } else if (next == 0xA9 || next == 0xA8 || next == 0xAB || next == 0xAA) {
                resultado += 'e';
            } else if (next == 0x89 || next == 0x88 || next == 0x8B || next == 0x8A) {
                resultado += 'E';
            } else if (next == 0xAD || next == 0xAC || next == 0xAF || next == 0xAE) {
                resultado += 'i';
            } else if (next == 0x8D || next == 0x8C || next == 0x8F || next == 0x8E) {
                resultado += 'I';
            } else if (next == 0xB3 || next == 0xB2 || next == 0xB6 || next == 0xB4) {
                resultado += 'o';
            } else if (next == 0x93 || next == 0x92 || next == 0x96 || next == 0x94) {
                resultado += 'O';
            } else if (next == 0xBA || next == 0xB9 || next == 0xBC || next == 0xBB) {
                resultado += 'u';
            } else if (next == 0x9A || next == 0x99 || next == 0x9C || next == 0x9B) {
                resultado += 'U';
            } else if (next == 0xB1) {
                resultado += "n\x7F";
            } else if (next == 0x91) {
                resultado += "N\x7F";
            } else {
                resultado += c;
                resultado += next;
            }
            i+=2;
        } else {
            resultado += c;
            i++;
        }
    }

    return resultado;
}

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
    for (char c: isbn) {
        if (std::isdigit(c)) {
            isbnSinGuiones += c;
        }
    }
    return isbnSinGuiones;
}

std::string Auxiliar::textoMinuscula(std::string texto) {
    texto = quitarTildes(texto);
    std::transform(texto.begin(), texto.end(), texto.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return texto;
}

void Auxiliar::obtenerFechas(const std::string &texto, int fechas[]) {
    std::string año1;
    std::string año2;
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
