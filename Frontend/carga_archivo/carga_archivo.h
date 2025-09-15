#ifndef CARGA_ARCHIVO_H
#define CARGA_ARCHIVO_H

#include <QWidget>

class Biblioteca;

namespace Ui {
class CargaArchivo;
}

class CargaArchivo : public QWidget
{
    Q_OBJECT

public:
    explicit CargaArchivo(QWidget *parent = nullptr);
    ~CargaArchivo() override;
    void setBiblioteca(Biblioteca *biblioteca){this->biblioteca = biblioteca;}

private slots:
    void on_botonAgregarRuta_clicked();
    void on_botonAnalizar_clicked();
private:
    Ui::CargaArchivo *ui;
    Biblioteca *biblioteca;
};

#endif // CARGA_ARCHIVO_H
