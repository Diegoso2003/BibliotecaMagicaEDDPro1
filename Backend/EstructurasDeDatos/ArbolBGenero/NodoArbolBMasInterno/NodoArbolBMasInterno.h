//
// Created by rafael-cayax on 28/9/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASINTERNOÇ_H
#define BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASINTERNOÇ_H
#include "../NodoArbolBMas/NodoArbolBMas.h"


class NodoArbolBMasInterno : public NodoArbolBMas{
private:
    NodoArbolBMas **hijos;
    void intercambiarHijos(NodoArbolBMas *&nuevo, NodoArbolBMas *&viejo);
public:
    explicit NodoArbolBMasInterno(int ordenArbol);
    ~NodoArbolBMasInterno() override;
    bool esNodoHoja() const override;
    std::string *getClaveMedia() override;
    NodoArbolBMas *getNuevoDer() override;
    NodoArbolBMas **getHijos() {return hijos;}
    void dividirNodoHijo(int posicion);
};


#endif //BIBLIOTECAMAGICAEDDPRO1_NODOARBOLBMASINTERNOÇ_H