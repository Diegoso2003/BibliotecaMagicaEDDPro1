#ifndef FORMELIMINACIONLIBRO_H
#define FORMELIMINACIONLIBRO_H

#include <QWidget>

class Libro;
class Biblioteca;

namespace Ui {
class FormEliminacionLibro;
}

class FormEliminacionLibro : public QWidget
{
    Q_OBJECT

public:
    explicit FormEliminacionLibro(Biblioteca *biblioteca, QWidget *parent = nullptr);
    ~FormEliminacionLibro() override;
    void limpiarEntrada();

private slots:
    void on_botonEliminar_clicked();

private:
    Ui::FormEliminacionLibro *ui;
    Biblioteca *biblioteca;
    QString obtenerInfoLibro(Libro *libro);
};

#endif // FORMELIMINACIONLIBRO_H
