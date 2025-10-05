#include "formeliminacionlibro.h"

#include <QMessageBox>

#include "ui_formeliminacionlibro.h"
#include "../../Backend/Biblioteca/Biblioteca.h"
#include "../../Backend/Excepciones/BusquedaSinResultadoException.h"
#include "../../Backend/Libro/Libro.h"

FormEliminacionLibro::FormEliminacionLibro(Biblioteca *biblioteca, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormEliminacionLibro)
{
    ui->setupUi(this);
    this->biblioteca = biblioteca;
}

FormEliminacionLibro::~FormEliminacionLibro()
{
    delete ui;
}

void FormEliminacionLibro::limpiarEntrada() {
    ui->isbnEliminar->setText("");
}

void FormEliminacionLibro::on_botonEliminar_clicked()
{
    std::string texto = ui->isbnEliminar->text().toStdString();
    try {
        Libro *libro = biblioteca->buscarLibroPorIsbn(texto);
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this,
            "Advertencia",
            obtenerInfoLibro(libro),
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::No
        );
        if (respuesta == QMessageBox::Yes) {
            biblioteca->eliminarLibro(libro);
            //delete libro;
            QMessageBox::information(this, "Exito", "Libro eliminado correctamente");
        }
    } catch (const BusquedaSinResultadoException &e) {
        QMessageBox::information(this, "Sin resultados", e.what());
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

QString FormEliminacionLibro::obtenerInfoLibro(Libro *libro) {
    QString mensaje = QString("¿Esta seguro de eliminar este libro?\n\n"
            "ISBN: %1\n"
            "Titulo: %2\n"
            "Autor: %3\n"
            "Genero : %4\n"
            "Año: %5\n"
            "Copias: %6\n")
            .arg(libro->getIsbn())
            .arg(libro->getTitulo())
            .arg(libro->getAutor())
            .arg(libro->getGenero())
            .arg(libro->getAño())
            .arg(libro->getCantidad());
    return mensaje;
}

