#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"
#include "../Backend/CreadorSVG/CreadorSvg.h"
#include "../Backend/EnumBusqueda/EnumBusqueda.h"
#include "../Backend/Excepciones/ElementoDuplicadoException.h"
#include "carga_archivo/carga_archivo.h"
#include "FormAgregarLibro/formagregarlibro.h"
#include "FormBusquedaLibro/formbusquedalibro.h"
#include "ResultadosBusqueda/resultadosbusqueda.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    biblioteca = new Biblioteca();
    auto *carga = new CargaArchivo(this);
    carga->setBiblioteca(biblioteca);
    auto *agregarLibro = new FormAgregarLibro(this);
    agregarLibro->setBiblioteca(biblioteca);
    busquedaLibro = new FormBusquedaLibro(biblioteca,this);
    ui->stackedWidget->addWidget(carga);
    ui->stackedWidget->addWidget(agregarLibro);
    ui->stackedWidget->addWidget(busquedaLibro);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow() {
    delete ui;
    delete biblioteca;
}

void MainWindow::on_actionCargar_archivo_csv_triggered() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionAgregar_libro_triggered() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::crearGrafica(std::string &nombre,const std::string& grafica, bool r) {
    try {
        CreadorSvg creador;
        creador.crearSvg(grafica, r, nombre);
        QMessageBox::information(this, "Exito",
            "grafica creada en la carpeta: " + QString::fromStdString(CreadorSvg::carpeta)
            + "/ con el nombre de: " + QString::fromStdString(nombre)+ ".svg");
    } catch (const ElementoDuplicadoException &e) {
        std::string mensaje = e.what();
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this,
            "Advertencia",
            QString::fromStdString(mensaje),
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::No // Botón por defecto
        );
        if (respuesta == QMessageBox::Yes) {
            crearGrafica(nombre, grafica, true);
        }
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::on_actionGrafico_de_arbol_AVL_ordenado_por_ISBN_triggered() {
    try {
        std::string nombre = "arbol_isbn";
        std::string grafica = biblioteca->obtenerDotArbolAVLPorISBN();
        crearGrafica(nombre, grafica);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::on_actionGrafico_de_arbol_AVl_ordenado_por_titulo_triggered()
{
    try {
        std::string nombre = "arbol_titulo";
        std::string grafica = biblioteca->obtenerDotArbolAVLPorTitulo();
        crearGrafica(nombre, grafica);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


void MainWindow::on_actionGrafico_arbol_B_ordenado_por_a_o_triggered()
{
    try {
        std::string nombre = "arbol_fecha";
        std::string grafica = biblioteca->obtenerDotArbolBFecha();
        crearGrafica(nombre, grafica);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


void MainWindow::on_actionGrafico_arbol_B_ordenado_por_genero_triggered()
{
    try {
        std::string nombre = "arbol_genero";
        std::string grafica = biblioteca->obtenerDotArbolBMasGenero();
        crearGrafica(nombre, grafica);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


void MainWindow::on_actionpor_ISBN_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->busquedaLibro->limpiarValores(EnumBusqueda::BUSQUEDA_ISBN);
}

void MainWindow::on_actionpor_titulo_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->busquedaLibro->limpiarValores(EnumBusqueda::BUSQUEDA_TITULO);
}


void MainWindow::on_actionpor_genero_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->busquedaLibro->limpiarValores(EnumBusqueda::BUSQUEDA_GENERO);
}


void MainWindow::on_actionpor_fecha_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->busquedaLibro->limpiarValores(EnumBusqueda::BUSQUEDA_AÑO);
}


void MainWindow::on_actionListar_por_titulo_triggered()
{
    try {
        ListaOrdenada *lista = biblioteca->obtenerLibrosEnOrdenAlfabetico();
        auto *resultado = new ResultadosBusqueda(this);
        resultado->agregarLista(lista);
        resultado->show();
        delete lista;
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}