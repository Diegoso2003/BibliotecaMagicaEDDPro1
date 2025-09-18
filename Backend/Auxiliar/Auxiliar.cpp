//
// Created by rafael-cayax on 15/9/25.
//

#include "Auxiliar.h"

#include <algorithm>
#include <regex>

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
