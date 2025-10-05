cmake_minimum_required(VERSION 3.10)
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
        Backend/EstructurasDeDatos/ListaSimpleSinOrdenar/NodoSimple/NodoSimple.cpp
        Backend/EstructurasDeDatos/ListaOrdenada/ListaOrdenada.cpp
        Backend/Biblioteca/Biblioteca.cpp
        Backend/Biblioteca/Biblioteca.h
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
        Backend/CreadorTextoDot/CreadorTextoDot.cpp
        Backend/CreadorTextoDot/CreadorTextoDot.h
        Backend/EstructurasDeDatos/ArbolBGenero/ArbolBGenero.cpp
        Backend/EstructurasDeDatos/ArbolBGenero/ArbolBGenero.h
        Backend/EstructurasDeDatos/ArbolBGenero/NodoArbolBMas/NodoArbolBMas.cpp
        Backend/EstructurasDeDatos/ArbolBGenero/NodoArbolBMas/NodoArbolBMas.h
        Backend/EstructurasDeDatos/ArbolBGenero/NodoArbolBMasHoja/NodoArbolBMasHoja.cpp
        Backend/EstructurasDeDatos/ArbolBGenero/NodoArbolBMasHoja/NodoArbolBMasHoja.h
        Backend/EstructurasDeDatos/ArbolBGenero/NodoArbolBMasInterno/NodoArbolBMasInterno.cpp
        Backend/EstructurasDeDatos/ArbolBGenero/NodoArbolBMasInterno/NodoArbolBMasInterno.h
        Backend/EstructurasDeDatos/ArbolAVLPorIsbn/NodoArbolIsbn/NodoArbolIsbn.cpp
        Backend/EstructurasDeDatos/ArbolAVLPorIsbn/NodoArbolIsbn/NodoArbolIsbn.h
        Backend/EstructurasDeDatos/ArbolAVLTitulo/NodoArbolTitulo/NodoArbolTitulo.cpp
        Backend/EstructurasDeDatos/ArbolAVLTitulo/NodoArbolTitulo/NodoArbolTitulo.h
        Frontend/FormBusquedaLibro/formbusquedalibro.cpp
        Backend/EnumBusqueda/EnumBusqueda.cpp
        Backend/EnumBusqueda/EnumBusqueda.h
        Backend/Iteradores/IteradorListaSimple.cpp
        Backend/Iteradores/IteradorListaSimple.h
        Frontend/ResultadosBusqueda/resultadosbusqueda.h
        Frontend/ResultadosBusqueda/resultadosbusqueda.cpp
        Backend/Excepciones/BusquedaSinResultadoException.h
        Backend/Excepciones/BusquedaSinResultadoException.h
        Backend/EstructurasDeDatos/ListaSimpleSinOrdenar/ListaSimpleSinOrdenar.cpp
        Backend/EstructurasDeDatos/ListaSimpleSinOrdenar/ListaSimpleSinOrdenar.h
        Backend/AuxiliarBusquedaB/AuxiliarBusquedaB.cpp
        Backend/AuxiliarBusquedaB/AuxiliarBusquedaB.h
        Backend/EstructurasDeDatos/ListaSimpleSinOrdenar/NodoSimple/NodoSimple.h
        Backend/EstructurasDeDatos/ListaOrdenada/NodoDoble/NodoDoble.cpp
        Backend/EstructurasDeDatos/ListaOrdenada/NodoDoble/NodoDoble.h
        Frontend/FormEliminacionLibro/formeliminacionlibro.h
        Frontend/FormEliminacionLibro/formeliminacionlibro.cpp
)
target_link_libraries(BibliotecaMagicaEDDPro1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(BibliotecaMagicaEDDPro1 PRIVATE -Os -s -ffunction-sections -fdata-sections)
    target_link_options(BibliotecaMagicaEDDPro1 PRIVATE -Wl,--gc-sections)
endif()