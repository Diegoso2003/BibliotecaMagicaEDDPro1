#include "mainwindow.h"

#include <iostream>

#include "ui_mainwindow.h"
#include "carga_archivo/carga_archivo.h"
#include "FormAgregarLibro/formagregarlibro.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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

MainWindow::~MainWindow()
{
    delete ui;
    delete biblioteca;
}

void MainWindow::on_actionCargar_archivo_csv_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionAgregar_libro_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

