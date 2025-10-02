#ifndef FORMBUSQUEDALIBRO_H
#define FORMBUSQUEDALIBRO_H

#include <QWidget>

class Biblioteca;
enum class EnumBusqueda;

namespace Ui {
class FormBusquedaLibro;
}

class FormBusquedaLibro : public QWidget
{
    Q_OBJECT

public:
    explicit FormBusquedaLibro(Biblioteca *biblioteca, QWidget *parent = nullptr);
    ~FormBusquedaLibro() override;
    void limpiarValores(EnumBusqueda tipo);

private slots:

    void on_botonBuscar_clicked();

private:
    Ui::FormBusquedaLibro *ui;
    EnumBusqueda tipo;
    Biblioteca *biblioteca;
    void obtenerPlaceHolder();
};

#endif // FORMBUSQUEDALIBRO_H
