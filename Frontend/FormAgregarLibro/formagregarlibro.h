#ifndef FORMAGREGARLIBRO_H
#define FORMAGREGARLIBRO_H

#include <QWidget>

namespace Ui {
class FormAgregarLibro;
}

class FormAgregarLibro : public QWidget
{
    Q_OBJECT

public:
    explicit FormAgregarLibro(QWidget *parent = nullptr);
    ~FormAgregarLibro();

private:
    Ui::FormAgregarLibro *ui;
};

#endif // FORMAGREGARLIBRO_H
