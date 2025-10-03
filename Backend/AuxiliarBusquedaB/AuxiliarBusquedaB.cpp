//
// Created by rafael-cayax on 2/10/25.
//

#include "AuxiliarBusquedaB.h"

AuxiliarBusquedaB::AuxiliarBusquedaB(ListaSimpleSinOrdenar *listaSinOrden, const int fechas[2]) {
    this->listaSinOrden = listaSinOrden;
    this->fechas[0] = fechas[0];
    this->fechas[1] = fechas[1];
}
