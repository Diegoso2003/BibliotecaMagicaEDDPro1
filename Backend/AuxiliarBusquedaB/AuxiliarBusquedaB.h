//
// Created by rafael-cayax on 2/10/25.
//

#ifndef BIBLIOTECAMAGICAEDDPRO1_AUXILIARBUSQUEDAB_H
#define BIBLIOTECAMAGICAEDDPRO1_AUXILIARBUSQUEDAB_H


class ListaSimpleSinOrdenar;

class AuxiliarBusquedaB {
private:
    bool buscar = true;
    bool fueraDeRango = false;
    ListaSimpleSinOrdenar *listaSinOrden = nullptr;
    int fechas[2] = {0, 0};
public:
    AuxiliarBusquedaB(ListaSimpleSinOrdenar *listaSinOrden,const int fechas[2]);
    bool seguirBuscando() const { return buscar; }
    bool estaFueraDeRango() const { return fueraDeRango; }
    bool esFechaUnica() const { return fechas[0] == fechas[1]; }
    void marcarFueraDeRango() { fueraDeRango = true; }
    void pararBusqueda() {buscar = false;}
    int fechaInicio() {return fechas[0];}
    int fechaFin() {return fechas[1];}
    ListaSimpleSinOrdenar *getLista() {return listaSinOrden;}
};


#endif //BIBLIOTECAMAGICAEDDPRO1_AUXILIARBUSQUEDAB_H