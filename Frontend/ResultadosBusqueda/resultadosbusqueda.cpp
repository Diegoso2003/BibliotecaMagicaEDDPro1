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
}

ResultadosBusqueda::~ResultadosBusqueda()
{
    delete ui;
}

void ResultadosBusqueda::agregarItemCentrado(int fila, int columna, QString valor) {
    auto *item = new QTableWidgetItem(valor);
    item->setTextAlignment(Qt::AlignCenter);
    ui->tablaResultados->setItem(fila, columna, item);
}

void ResultadosBusqueda::agregarLibro(Libro *libro, int fila) {
    agregarItemCentrado(fila, 0, QString::fromStdString(libro->getIsbn()));
    agregarItemCentrado(fila, 1, QString::fromStdString(libro->getTitulo()));
    agregarItemCentrado(fila, 2, QString::fromStdString(libro->getGenero()));
    agregarItemCentrado(fila, 3, QString::number(libro->getAño()));
    agregarItemCentrado(fila, 4, QString::fromStdString(libro->getAutor()));
    agregarItemCentrado(fila, 5, QString::number(libro->getCantidad()));
}

void ResultadosBusqueda::agregarLista(ListaSimpleEnlazada *lista) {
    IteradorListaSimple iterador = lista->getIterator();
    int fila = 0;
    ui->tablaResultados->setRowCount(lista->getTamaño());
    while (iterador.haySiguiente()) {
        agregarLibro(iterador.getActual(), fila++);
    }
    ajustarTabla();
}

void ResultadosBusqueda::ajustarTabla() {
    ui->tablaResultados->verticalHeader()->setDefaultSectionSize(40);
    ui->tablaResultados->verticalHeader()->setMinimumSectionSize(40);

    ui->tablaResultados->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablaResultados->setWordWrap(true);
    ui->tablaResultados->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tablaResultados->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ResultadosBusqueda::agregarLibro(Libro *libro) {
    ui->tablaResultados->setRowCount(1);
    agregarLibro(libro, 0);
    ajustarTabla();
}
