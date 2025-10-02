#include "formbusquedalibro.h"

#include <QMessageBox>

#include "ui_formbusquedalibro.h"
#include "../../Backend/Biblioteca/Biblioteca.h"
#include "../../Backend/EnumBusqueda/EnumBusqueda.h"
#include "../../Backend/Excepciones/BusquedaSinResultadoException.h"
#include "../ResultadosBusqueda/resultadosbusqueda.h"

FormBusquedaLibro::FormBusquedaLibro(Biblioteca *biblioteca, QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::FormBusquedaLibro) {
    ui->setupUi(this);
    this->biblioteca = biblioteca;
    QPalette palette = ui->valorBusqueda->palette();
    palette.setColor(QPalette::PlaceholderText, QColor(150, 150, 150));
    ui->valorBusqueda->setPalette(palette);
}

FormBusquedaLibro::~FormBusquedaLibro() {
    delete ui;
    delete tipo;
}

void FormBusquedaLibro::limpiarValores(EnumBusqueda tipo) {
    ui->valorBusqueda->setText("");
    delete this->tipo;
    this->tipo = new EnumBusqueda(tipo);
    obtenerPlaceHolder();
}

void FormBusquedaLibro::obtenerPlaceHolder() {
    switch (*tipo) {
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

void FormBusquedaLibro::on_botonBuscar_clicked() {
    auto *resultados = new ResultadosBusqueda(this->window());
    std::string texto = ui->valorBusqueda->text().toStdString();
    try {
        switch (*tipo) {
            case EnumBusqueda::BUSQUEDA_AÑO: ;
            case EnumBusqueda::BUSQUEDA_GENERO:
                resultados->agregarLista(biblioteca->buscarLibroPorGenero(texto));
                break;
            case EnumBusqueda::BUSQUEDA_ISBN:
                resultados->agregarLibro(biblioteca->buscarLibroPorIsbn(texto));
                break;
            default:
                resultados->agregarLista(biblioteca->buscarLibroPorTitulo(texto));
        }
        resultados->show();
    } catch (const BusquedaSinResultadoException &e) {
        delete resultados;
        QMessageBox::information(this, "Sin resultados", e.what());
    } catch (const std::exception &e){
        delete resultados;
        QMessageBox::critical(this, "Error", e.what());
    }
}
