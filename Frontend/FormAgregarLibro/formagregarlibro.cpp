#include "formagregarlibro.h"
#include "ui_formagregarlibro.h"

FormAgregarLibro::FormAgregarLibro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormAgregarLibro)
{
    ui->setupUi(this);
}

FormAgregarLibro::~FormAgregarLibro()
{
    delete ui;
}
