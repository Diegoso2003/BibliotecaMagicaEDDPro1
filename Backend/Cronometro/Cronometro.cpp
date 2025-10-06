//
// Created by rafael-cayax on 5/10/25.
//

#include "Cronometro.h"

Cronometro::Cronometro() {
    inicio = std::chrono::high_resolution_clock::now();
}

void Cronometro::reset() {
    inicio = std::chrono::high_resolution_clock::now();
}

double Cronometro::tiempoEnMicrosegundos() {
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    return duracion.count();
}
