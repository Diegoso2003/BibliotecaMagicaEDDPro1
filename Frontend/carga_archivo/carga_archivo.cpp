#include "carga_archivo.h"
#include "ui_carga_archivo.h"
#include <QFileDialog>
#include <QMessageBox>

#include "../../Backend/Biblioteca/Biblioteca.h"

CargaArchivo::CargaArchivo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CargaArchivo)
{
    ui->setupUi(this);
    ui->gridLayout->removeWidget(ui->descripcion);
    ui->gridLayout->removeWidget(ui->botonAgregarRuta);
    ui->gridLayout->removeWidget(ui->botonAnalizar);
    ui->gridLayout->removeWidget(ui->rutaArchivo);
    biblioteca = nullptr;
    ui->gridLayout->addWidget(ui->descripcion, 0, 0, 1, 1);
    ui->gridLayout->addWidget(ui->rutaArchivo, 1, 0, 1, 2);
    ui->gridLayout->addWidget(ui->botonAgregarRuta, 2, 0, 1,1);
    ui->gridLayout->addWidget(ui->botonAnalizar, 2, 1, 1, 1);
}

CargaArchivo::~CargaArchivo()
{
    delete ui;
}

void CargaArchivo::on_botonAgregarRuta_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(
        this,
        "Seleccione el archivo csv",
        "",
        "archivos CSV (*.csv);;Todos los archivos (*)");
    if (!filepath.isEmpty()) {
        ui->rutaArchivo->setText(filepath);
    }
}

void CargaArchivo::on_botonAnalizar_clicked()
{
    try {
        QString archivo = ui->rutaArchivo->text();
        std::string ruta = archivo.toStdString();
        biblioteca->analizarArchivo(ruta);
        QMessageBox::information(this, "exito", "libros agregados exitosamente");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "error", e.what());
    }
}

