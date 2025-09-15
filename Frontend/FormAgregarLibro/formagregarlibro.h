#ifndef FORMAGREGARLIBRO_H
#define FORMAGREGARLIBRO_H

#include <QWidget>

class Biblioteca;

namespace Ui {
class FormAgregarLibro;
}

class FormAgregarLibro : public QWidget
{
    Q_OBJECT

public:
    explicit FormAgregarLibro(QWidget *parent = nullptr);
    ~FormAgregarLibro();
    void setBiblioteca(Biblioteca *biblioteca){this->biblioteca = biblioteca;}

private:
    Ui::FormAgregarLibro *ui;
    Biblioteca* biblioteca;
};

#endif // FORMAGREGARLIBRO_H
