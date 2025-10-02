#include "formbusquedalibro.h"
#include "ui_formbusquedalibro.h"
#include "../../Backend/EnumBusqueda/EnumBusqueda.h"

FormBusquedaLibro::FormBusquedaLibro(Biblioteca *biblioteca, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormBusquedaLibro)
{
    ui->setupUi(this);
    this->biblioteca = biblioteca;
    QPalette palette = ui->valorBusqueda->palette();
    palette.setColor(QPalette::PlaceholderText, QColor(150, 150, 150));
    ui->valorBusqueda->setPalette(palette);
}

FormBusquedaLibro::~FormBusquedaLibro()
{
    delete ui;
}

void FormBusquedaLibro::limpiarValores(EnumBusqueda tipo) {
    ui->valorBusqueda->setText("");
    this->tipo = tipo;
    obtenerPlaceHolder();
}

void FormBusquedaLibro::obtenerPlaceHolder() {
    switch (tipo) {
        case EnumBusqueda::BUSQUEDA_ISBN:
            ui->descripcion->setText("Ingrese el ISBN del libro");
            ui->valorBusqueda->setPlaceholderText("ISBN");
            break;
        case EnumBusqueda::BUSQUEDA_TITULO:
            ui->descripcion->setText("Ingrese el titulo del libro");
            ui->valorBusqueda->setPlaceholderText("Titulo");
            break;
        case EnumBusqueda::BUSQUEDA_GENERO:
            ui->descripcion->setText("Ingrese el genero de los libros a buscar");
            ui->valorBusqueda->setPlaceholderText("Genero");
            break;
        default:
            ui->descripcion->setText("Ingrese el año de publicacion o un rango de fecha");
            ui->valorBusqueda->setPlaceholderText("1920-2010");
    }
}

void FormBusquedaLibro::on_botonBuscar_clicked()
{

}

