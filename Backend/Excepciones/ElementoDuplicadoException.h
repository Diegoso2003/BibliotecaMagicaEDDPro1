//
// Created by rafael-cayax on 15/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_LIBRODUPLICADOEXCEPTION_H
#define BIBLIOTECAMAGICAEDDPRO1_LIBRODUPLICADOEXCEPTION_H
#include <string>
#include <utility>

class ElementoDuplicadoException : public std::exception {
private:
    std::string mensaje;
public:
    explicit ElementoDuplicadoException(std::string  msg) : mensaje(std::move(msg)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
#endif //BIBLIOTECAMAGICAEDDPRO1_LIBRODUPLICADOEXCEPTION_H