//
// Created by rafael-cayax on 14/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_ENTRADAUSUARIOEXCEPTION_H
#define BIBLIOTECAMAGICAEDDPRO1_ENTRADAUSUARIOEXCEPTION_H
#include <string>
#include <utility>

class EntradaUsuarioException : public std::exception {
private:
    std::string mensaje;
public:
    explicit EntradaUsuarioException(std::string  msg) : mensaje(std::move(msg)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
#endif //BIBLIOTECAMAGICAEDDPRO1_ENTRADAUSUARIOEXCEPTION_H