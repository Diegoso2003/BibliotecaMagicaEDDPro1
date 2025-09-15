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
        Backend/AnalizadorArchivo/LectorArchivo.cpp
        Backend/AnalizadorArchivo/LectorArchivo.h
        Backend/EntradaUsuarioException/EntradaUsuarioException.h
        Backend/EstructurasDeDatos/ListaEnlazadaDoble/NodoDoble.cpp
        Backend/EstructurasDeDatos/ListaEnlazadaDoble/NodoDoble/ListaDobleEnlazada.cpp
)
target_link_libraries(BibliotecaMagicaEDDPro1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)