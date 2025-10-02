//
// Created by rafael-cayax on 1/10/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_BUSQUEDASINRESULTADOEXCEPTION_H
#define BIBLIOTECAMAGICAEDDPRO1_BUSQUEDASINRESULTADOEXCEPTION_H
#include <string>

class BusquedaSinResultadoException : public std::exception {
private:
    std::string mensaje;
public:
    explicit BusquedaSinResultadoException(std::string  msg) : mensaje(std::move(msg)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

#endif //BIBLIOTECAMAGICAEDDPRO1_BUSQUEDASINRESULTADOEXCEPTION_H