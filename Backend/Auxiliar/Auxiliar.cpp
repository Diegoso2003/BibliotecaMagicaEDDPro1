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
    std::regex patron("\\s+");
    entrada = std::regex_replace(entrada, patron, " ");
}

std::string Auxiliar::obtenerISBNSinGuion(const std::string &isbn) {
    if (isbn.empty()) return "";
    std::regex patron("-");
    return std::regex_replace(isbn, patron, "");
}
