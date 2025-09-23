cmake_minimum_required(VERSION 4.0)
project(BibliotecaMagicaEDDPro1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/rafael-cayax/Qt/6.9.2/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(BibliotecaMagicaEDDPro1 main.cpp
        Backend/Libro/Libro.cpp
        Frontend/mainwindow.cpp
        Frontend/carga_archivo/carga_archivo.cpp
        Frontend/FormAgregarLibro/formagregarlibro.cpp
        Backend/LectorArchivo/LectorArchivo.cpp
        Backend/Excepciones/EntradaUsuarioException.h
        Backend/EstructurasDeDatos/ListaSimple/NodoSimple/NodoSimple.cpp
        Backend/EstructurasDeDatos/ListaSimple/ListaSimpleEnlazada.cpp
        Backend/Biblioteca/Biblioteca.cpp
        Backend/Biblioteca/Biblioteca.h
        Backend/Iteradores/IteradorLED/IteradorLED.cpp
        Backend/AnalizadorLinea/AnalizadorLinea.h
        Backend/Excepciones/ElementoDuplicadoException.h
        Backend/AnalizadorLinea/AnalizadorLinea.cpp
        Backend/Auxiliar/Auxiliar.cpp
        Backend/Auxiliar/Auxiliar.h
        Frontend/MensajeArchivoError/dialogerrorarchivo.cpp
        Backend/Excepciones/ArchivoInvalidoException.h
        Backend/EstructurasDeDatos/ArbolAVL/ArbolAVL.cpp
        Backend/EstructurasDeDatos/ArbolAVL/ArbolAVL.h
        Backend/EstructurasDeDatos/ArbolAVL/NodoArbol/NodoArbol.cpp
        Backend/EstructurasDeDatos/ArbolAVL/NodoArbol/NodoArbol.h
        Backend/CreadorSVG/CreadorSvg.cpp
        Backend/CreadorSVG/CreadorSvg.h
        Backend/EstructurasDeDatos/ArbolAVLPorIsbn/ArbolAVLPorIsbn.cpp
        Backend/EstructurasDeDatos/ArbolAVLPorIsbn/ArbolAVLPorIsbn.h
        Backend/EstructurasDeDatos/ArbolAVLTitulo/ArbolAVLTitulo.h
        Backend/EstructurasDeDatos/ArbolAVLTitulo/ArbolAVLTitulo.cpp
        Backend/EstructurasDeDatos/ArbolBFecha/ArbolBFecha.cpp
        Backend/EstructurasDeDatos/ArbolBFecha/ArbolBFecha.h
        Backend/EstructurasDeDatos/ArbolBFecha/NodoArbolB/NodoArbolB.cpp
        Backend/EstructurasDeDatos/ArbolBFecha/NodoArbolB/NodoArbolB.h
)
target_link_libraries(BibliotecaMagicaEDDPro1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)