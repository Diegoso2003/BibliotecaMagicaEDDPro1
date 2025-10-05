//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_AUXILIAR_H
#define BIBLIOTECAMAGICAEDDPRO1_AUXILIAR_H
#include <string>

class Auxiliar {
private:
    static std::string quitarTildes(const std::string &entrada);
public:
    static void trim(std::string &entrada);
    static void eliminarEspaciosIntermedio(std::string &entrada);
    static std::string obtenerISBNSinGuion(const std::string &isbn);
    static std::string textoMinuscula(std::string texto);
    static void obtenerFechas(const std::string &texto, int fechas[]);
    static bool esNumero(char c);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_AUXILIAR_H