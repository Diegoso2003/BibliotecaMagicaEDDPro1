#include "resultadosbusqueda.h"
#include "ui_resultadosbusqueda.h"
#include "../../Backend/EstructurasDeDatos/ListaSimple/ListaSimpleEnlazada.h"
#include "../../Backend/Iteradores/IteradorListaSimple.h"
#include "../../Backend/Libro/Libro.h"

ResultadosBusqueda::ResultadosBusqueda(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ResultadosBusqueda)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
}

ResultadosBusqueda::~ResultadosBusqueda()
{
    delete ui;
}

void ResultadosBusqueda::agregarLibro(Libro *libro, int fila) {
    ui->tableWidget->
    setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(libro->getIsbn())));
    ui->tableWidget->
    setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(libro->getTitulo())));
    ui->tableWidget->
    setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(libro->getGenero())));
    ui->tableWidget->
    setItem(fila, 3, new QTableWidgetItem(QString::number(libro->getAño())));
    ui->tableWidget->
    setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(libro->getAutor())));
    ui->tableWidget->
    setItem(fila, 5, new QTableWidgetItem(QString::number(libro->getCantidad())));
}

void ResultadosBusqueda::agregarLista(ListaSimpleEnlazada *lista) {
    IteradorListaSimple iterador = lista->getIterator();
    int fila = 1;
    ui->tableWidget->setRowCount(lista->getTamaño());
    while (iterador.haySiguiente()) {
        agregarLibro(iterador.getActual(), fila++);
    }
}