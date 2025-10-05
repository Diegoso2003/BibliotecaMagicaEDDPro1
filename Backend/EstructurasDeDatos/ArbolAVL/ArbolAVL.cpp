//
// Created by rafael-cayax on 15/9/25.
//
#include "ArbolAVL.h"

#include "../../CreadorTextoDot/CreadorTextoDot.h"
#include "../../Excepciones/ElementoDuplicadoException.h"
#include "../../Excepciones/EntradaUsuarioException.h"
#include "../ArbolAVLPorIsbn/NodoArbolIsbn/NodoArbolIsbn.h"

NodoArbol *ArbolAVL::buscarNodo(NodoArbol *nodo, Libro *libroBuscado) {
    if (nodo == nullptr) return nullptr;
    if (visitarSubArbolIzquierdo(nodo, libroBuscado)) {
        return buscarNodo(nodo->getIzquierda(), libroBuscado);
    }
    if (visitarSubArbolDerecho(nodo, libroBuscado)) {
        return buscarNodo(nodo->getDerecha(), libroBuscado);
    }
    return nodo;
}

NodoArbol *ArbolAVL::reorganizarArbolDerecho(NodoArbol *nodo, bool eliminacion, bool &verificarFeSubArbol) {
    NodoArbol *nodo1 = nodo->getDerecha();
    if (nodo1->getFe() >= 0) {
        nodo = rotacionDD(nodo, eliminacion, verificarFeSubArbol);
    } else {
        nodo = rotacionDI(nodo);
        nodo->setFe(0);
    }
    return nodo;
}

NodoArbol *ArbolAVL::reorganizarArbolIzquierdo(NodoArbol *nodo, bool eliminacion, bool &verificacionFeSubArbol) {
    NodoArbol *nodo1 = nodo->getIzquierda();
    if (nodo1->getFe() <= 0) {
        nodo = rotacionII(nodo, eliminacion, verificacionFeSubArbol);
    } else {
        nodo = rotacionID(nodo);
        nodo->setFe(0);
    }
    return nodo;
}

NodoArbol * ArbolAVL::rotacionII(NodoArbol *nodo, bool eliminacion, bool &verificacionFeSubArbol) {
    NodoArbol *nodo1 = nodo->getIzquierda();
    nodo->setIzquierda(nodo1->getDerecha());
    nodo1->setDerecha(nodo);
    if (!eliminacion) {
        nodo->setFe(0);
        nodo1->setFe(0);
    } else {
        switch (nodo1->getFe()) {
            case 0:
                nodo->setFe(0);
                nodo1->setFe(1);
                verificacionFeSubArbol = false;
                break;
            default:
                nodo->setFe(0);
                nodo1->setFe(0);
        }
    }
    return nodo1;
}

NodoArbol * ArbolAVL::rotacionID(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getIzquierda();
    NodoArbol *nodo2 = nodo1->getDerecha();
    nodo->setIzquierda(nodo2->getDerecha());
    nodo2->setDerecha(nodo);
    nodo1->setDerecha(nodo2->getIzquierda());
    nodo2->setIzquierda(nodo1);
    if (nodo2->getFe() == -1) {
        nodo->setFe(1);
    } else {
        nodo->setFe(0);
    }
    if (nodo2->getFe() == 1) {
        nodo1->setFe(-1);
    } else {
        nodo1->setFe(0);
    }
    return nodo2;
}

NodoArbol * ArbolAVL::rotacionDD(NodoArbol *nodo, bool eliminacion, bool &verificarFeSubArbol) {
    NodoArbol *nodo1 = nodo->getDerecha();
    nodo->setDerecha(nodo1->getIzquierda());
    nodo1->setIzquierda(nodo);
    if (!eliminacion) {
        nodo->setFe(0);
        nodo1->setFe(0);
    } else {
        switch (nodo1->getFe()) {
            case 0:
                nodo->setFe(0);
                nodo1->setFe(-1);
                verificarFeSubArbol = false;
                break;
            default:
                nodo->setFe(0);
                nodo1->setFe(0);
        }
    }
    return nodo1;
}

NodoArbol * ArbolAVL::rotacionDI(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getDerecha();
    NodoArbol *nodo2 = nodo1->getIzquierda();
    nodo->setDerecha(nodo2->getIzquierda());
    nodo2->setIzquierda(nodo);
    nodo1->setIzquierda(nodo2->getDerecha());
    nodo2->setDerecha(nodo1);
    if (nodo2->getFe() == 1) {
        nodo->setFe(-1);
    } else {
        nodo->setFe(0);
    }
    if (nodo2->getFe() == -1) {
        nodo1->setFe(1);
    } else {
        nodo1->setFe(0);
    }
    return nodo2;
}

NodoArbol * ArbolAVL::eliminarNodo(NodoArbol *nodo, Libro *libro, bool &verificarFeSubArbol) {
    if (visitarSubArbolIzquierdo(nodo, libro)) {
        nodo->setIzquierda(eliminarNodo(nodo->getIzquierda(), libro, verificarFeSubArbol));
        if (verificarFeSubArbol) nodo = evaluarNodoDerecho(nodo, verificarFeSubArbol, true);
        return nodo;
    }
    if (visitarSubArbolDerecho(nodo, libro)) {
        nodo->setDerecha(eliminarNodo(nodo->getDerecha(), libro, verificarFeSubArbol));
        if (verificarFeSubArbol) nodo = evaluarNodoIzquierdo(nodo, verificarFeSubArbol, true);
        return nodo;
    }
    verificarFeSubArbol = eliminarNodo(nodo, libro);
    if (!verificarFeSubArbol) return nodo;
    NodoArbol *otro = nodo;
    if (otro->getDerecha() == nullptr) {
        nodo = otro->getIzquierda();
    }else if (otro->getIzquierda() == nullptr) {
        nodo = otro->getDerecha();
    } else {
        NodoArbol *aux = nodo->getIzquierda();
        NodoArbol *aux1 = nullptr;
        while (aux->getDerecha() != nullptr) {
            aux1 = aux;
            aux = aux->getDerecha();
        }
        this->cambiarInformacion(nodo, aux);
        otro = aux;
        verificarFeSubArbol = aux1 != nullptr;
        if (verificarFeSubArbol) {
            aux1->setDerecha(aux->getIzquierda());
        } else {
            nodo->setIzquierda(aux->getIzquierda());
        }
        if (verificarFeSubArbol) nodo->setIzquierda(evaluarNodoIzquierdo(nodo->getIzquierda(), verificarFeSubArbol, true));
        if (!verificarFeSubArbol) nodo = evaluarNodoDerecho(nodo, verificarFeSubArbol, true);
    }
    otro->setIzquierda(nullptr);
    otro->setDerecha(nullptr);
    auto *nodoIsbn = dynamic_cast<NodoArbolIsbn *>(otro);
    if (nodoIsbn != nullptr) nodoIsbn->setLibro(nullptr);
    delete otro;
    return nodo;
}

NodoArbol * ArbolAVL::evaluarNodoIzquierdo(NodoArbol *nodo, bool &verificarFeSubArbol, bool eliminacion) {
    switch (nodo->getFe()) {
        case 1:
            nodo->setFe(0);
            if (!eliminacion) verificarFeSubArbol = false;
            break;
        case 0:
            nodo->setFe(-1);
            if (eliminacion) verificarFeSubArbol = false;
            break;
        default:
            nodo = reorganizarArbolIzquierdo(nodo, eliminacion, verificarFeSubArbol);
            verificarFeSubArbol = false;
    }
    return nodo;
}

NodoArbol * ArbolAVL::evaluarNodoDerecho(NodoArbol *nodo, bool &verificarFeSubArbol, bool eliminacion) {
    switch (nodo->getFe()) {
        case -1:
            nodo->setFe(0);
            if (!eliminacion) verificarFeSubArbol = false;
            break;
        case 0:
            nodo->setFe(1);
            if (eliminacion) verificarFeSubArbol = false;
            break;
        default:
            nodo = reorganizarArbolDerecho(nodo, eliminacion, verificarFeSubArbol);
            verificarFeSubArbol = false;
    }
    return nodo;
}

NodoArbol *ArbolAVL::agregarNuevoNodo(NodoArbol *nodo, Libro *nuevoLibro, bool &verificarFeSubArbol) {
    if (nodo != nullptr) {
        if (visitarSubArbolIzquierdo(nodo, nuevoLibro)) {
            nodo->setIzquierda(agregarNuevoNodo(nodo->getIzquierda(), nuevoLibro, verificarFeSubArbol));
            if (verificarFeSubArbol) {
                return evaluarNodoIzquierdo(nodo, verificarFeSubArbol, false);
            }
        } else if (visitarSubArbolDerecho(nodo, nuevoLibro)) {
            nodo->setDerecha(agregarNuevoNodo(nodo->getDerecha(), nuevoLibro, verificarFeSubArbol));
            if (verificarFeSubArbol) {
                return evaluarNodoDerecho(nodo, verificarFeSubArbol, false);
            }
        } else {
            tratarLibroDuplicado(nodo, nuevoLibro);
        }
    } else {
        nodo = crearNuevoNodo(nuevoLibro);
        verificarFeSubArbol = true;
        elementos++;
    }
    return nodo;
}

ArbolAVL::ArbolAVL() : raiz(nullptr) {
}

ArbolAVL::~ArbolAVL() {
    delete raiz;
}

std::string ArbolAVL::obtenerDotArbol() {
    CreadorTextoDot creador;
    if (estaVacia()) throw EntradaUsuarioException("Arbol vacio, ingresar datos para crear grafica");
    return creador.obtenerDotArbolAvl(raiz);
}

void ArbolAVL::agregarLibro(Libro *libro) {
    bool cambioAlturaArbol = false;
    duplicado = false;
    agregarDemasArboles = true;
    raiz = agregarNuevoNodo(raiz, libro, cambioAlturaArbol);
    if (duplicado) throw ElementoDuplicadoException("libro con isbn duplicado");
}

void ArbolAVL::eliminarLibro(Libro *libro) {
    this->elementos--;
    bool verificarFeSubArbol = false;
    raiz = eliminarNodo(raiz, libro, verificarFeSubArbol);
}