//
// Created by rafael-cayax on 18/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_CREADORSVG_H
#define BIBLIOTECAMAGICAEDDPRO1_CREADORSVG_H
#include <string>

class CreadorSvg {
public:
    static constexpr std::string carpeta = "graficas";
    void crearSvg(const std::string& grafica, bool reemplazar, std::string nombreArchivo);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_CREADORSVG_H