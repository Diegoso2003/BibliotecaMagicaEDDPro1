#include "mainwindow.h"

#include <QMessageBox>
#include "ui_mainwindow.h"
#include "../Backend/CreadorSVG/CreadorSvg.h"
#include "../Backend/Excepciones/EntradaUsuarioException.h"
#include "carga_archivo/carga_archivo.h"
#include "FormAgregarLibro/formagregarlibro.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    biblioteca = new Biblioteca();
    auto *carga = new CargaArchivo(this);
    carga->setBiblioteca(biblioteca);
    auto *agregarLibro = new FormAgregarLibro(this);
    agregarLibro->setBiblioteca(biblioteca);
    ui->stackedWidget->addWidget(carga);
    ui->stackedWidget->addWidget(agregarLibro);
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

void MainWindow::crearGrafica(const std::string& grafica, bool r, std::string nombre) {
    std::string grafica2;
    try {
        CreadorSvg creador;
        grafica2 = grafica.empty() ? biblioteca->obtenerDotArbolAVLPorISBN() : grafica;
        creador.crearSvg(grafica2, r, "arbol_avl_isbn");
        QMessageBox::information(this, "Exito",
            "grafica creada en la carpeta: " + QString::fromStdString(CreadorSvg::carpeta)
            + "/ con el nombre de: arbol_avl_isbn.svg");
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
            crearGrafica(grafica2, true, "arbol_avl_isbn");
        }
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::on_actionGrafico_de_arbol_AVL_ordenado_por_ISBN_triggered() {
    crearGrafica();
}
