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

NodoArbol *ArbolAVL::reorganizarArbolDerecho(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getDerecha();
    if (nodo1->getFe() >= 1) {
        nodo = rotacionDD(nodo);
    } else {
        nodo = rotacionDI(nodo);
    }
    return nodo;
}

NodoArbol *ArbolAVL::reorganizarArbolIzquierdo(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getIzquierda();
    if (nodo1->getFe() <= -1) {
        nodo = rotacionII(nodo);
    } else {
        nodo = rotacionID(nodo);
    }
    return nodo;
}

NodoArbol * ArbolAVL::rotacionII(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getIzquierda();
    nodo->setIzquierda(nodo1->getDerecha());
    nodo1->setDerecha(nodo);
    nodo->recalcularAltura();
    nodo1->recalcularAltura();
    return nodo1;
}

NodoArbol * ArbolAVL::rotacionID(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getIzquierda();
    NodoArbol *nodo2 = nodo1->getDerecha();
    nodo->setIzquierda(nodo2->getDerecha());
    nodo2->setDerecha(nodo);
    nodo1->setDerecha(nodo2->getIzquierda());
    nodo2->setIzquierda(nodo1);
    nodo->recalcularAltura();
    nodo1->recalcularAltura();
    nodo2->recalcularAltura();
    return nodo2;
}

NodoArbol * ArbolAVL::rotacionDD(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getDerecha();
    nodo->setDerecha(nodo1->getIzquierda());
    nodo1->setIzquierda(nodo);
    nodo->recalcularAltura();
    nodo1->recalcularAltura();
    return nodo1;
}

NodoArbol * ArbolAVL::rotacionDI(NodoArbol *nodo) {
    NodoArbol *nodo1 = nodo->getDerecha();
    NodoArbol *nodo2 = nodo1->getIzquierda();
    nodo->setDerecha(nodo2->getIzquierda());
    nodo2->setIzquierda(nodo);
    nodo1->setIzquierda(nodo2->getDerecha());
    nodo2->setDerecha(nodo1);
    nodo->recalcularAltura();
    nodo1->recalcularAltura();
    nodo2->recalcularAltura();
    return nodo2;
}

NodoArbol * ArbolAVL::eliminarNodo(NodoArbol *nodo, Libro *libro, bool &verificarFeSubArbol) {
    if (visitarSubArbolIzquierdo(nodo, libro)) {
        nodo->setIzquierda(eliminarNodo(nodo->getIzquierda(), libro, verificarFeSubArbol));
        if (verificarFeSubArbol) nodo = evaluarNodoDerecho(nodo);
        return nodo;
    }
    if (visitarSubArbolDerecho(nodo, libro)) {
        nodo->setDerecha(eliminarNodo(nodo->getDerecha(), libro, verificarFeSubArbol));
        if (verificarFeSubArbol) nodo = evaluarNodoIzquierdo(nodo);
        return nodo;
    }
    verificarFeSubArbol = eliminarNodo(nodo, libro);
    if (!verificarFeSubArbol) return nodo;
    this->elementos--;
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
            nodo->setIzquierda(evaluarNodoIzquierdo(nodo->getIzquierda()));
        } else {
            nodo->setIzquierda(aux->getIzquierda());
            nodo = evaluarNodoDerecho(nodo);
        }
    }
    otro->setIzquierda(nullptr);
    otro->setDerecha(nullptr);
    delete otro;
    return nodo;
}

NodoArbol * ArbolAVL::evaluarNodoIzquierdo(NodoArbol *nodo) {
    nodo->recalcularAltura();
    if (nodo->getFe() <= -2) {
        nodo = reorganizarArbolIzquierdo(nodo);
    }
    return nodo;
}

NodoArbol * ArbolAVL::evaluarNodoDerecho(NodoArbol *nodo) {
    nodo->recalcularAltura();
    if (nodo->getFe() >= 2) {
        nodo = reorganizarArbolDerecho(nodo);
    }
    return nodo;
}

NodoArbol *ArbolAVL::agregarNuevoNodo(NodoArbol *nodo, Libro *nuevoLibro, bool &verificarFeSubArbol) {
    if (nodo != nullptr) {
        if (visitarSubArbolIzquierdo(nodo, nuevoLibro)) {
            nodo->setIzquierda(agregarNuevoNodo(nodo->getIzquierda(), nuevoLibro, verificarFeSubArbol));
            if (verificarFeSubArbol) {
                return evaluarNodoIzquierdo(nodo);
            }
        } else if (visitarSubArbolDerecho(nodo, nuevoLibro)) {
            nodo->setDerecha(agregarNuevoNodo(nodo->getDerecha(), nuevoLibro, verificarFeSubArbol));
            if (verificarFeSubArbol) {
                return evaluarNodoDerecho(nodo);
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
    bool verificarFeSubArbol = false;
    raiz = eliminarNodo(raiz, libro, verificarFeSubArbol);
}