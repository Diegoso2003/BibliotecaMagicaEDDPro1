#include "dialogerrorarchivo.h"
#include "ui_dialogerrorarchivo.h"

DialogErrorArchivo::DialogErrorArchivo(QWidget *parent, std::string mensaje)
    : QDialog(parent)
    , ui(new Ui::DialogErrorArchivo)
{
    ui->setupUi(this);
    ui->mensajeError->setText(QString::fromUtf8(mensaje.c_str()));
}

DialogErrorArchivo::~DialogErrorArchivo()
{
    delete ui;
}
