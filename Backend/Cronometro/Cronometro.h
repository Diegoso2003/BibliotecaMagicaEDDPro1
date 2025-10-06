//
// Created by rafael-cayax on 5/10/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_CRONOMETRO_H
#define BIBLIOTECAMAGICAEDDPRO1_CRONOMETRO_H
#include <chrono>


class Cronometro {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> inicio;
public:
    Cronometro();
    void reset();
    double tiempoEnMicrosegundos();
};


#endif //BIBLIOTECAMAGICAEDDPRO1_CRONOMETRO_H