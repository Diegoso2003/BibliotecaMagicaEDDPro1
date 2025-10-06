#include "dialogerrorarchivo.h"

#include <qdialogbuttonbox.h>

#include "ui_dialogerrorarchivo.h"

DialogErrorArchivo::DialogErrorArchivo(QWidget *parent, std::string mensaje)
    : QDialog(parent)
    , ui(new Ui::DialogErrorArchivo)
{
    ui->setupUi(this);
    ui->mensajeError->setText(QString::fromUtf8(mensaje.c_str()));
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok, this);
    qobject_cast<QGridLayout*>(layout())->addWidget(buttonBox, 1, 0);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
}

DialogErrorArchivo::~DialogErrorArchivo()
{
    delete ui;
}
