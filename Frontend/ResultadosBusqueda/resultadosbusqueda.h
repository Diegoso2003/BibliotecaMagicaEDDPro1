#ifndef RESULTADOSBUSQUEDA_H
#define RESULTADOSBUSQUEDA_H

#include <QDialog>

class Libro;
class ListaSimpleEnlazada;

namespace Ui {
class ResultadosBusqueda;
}

class ResultadosBusqueda : public QDialog
{
    Q_OBJECT

public:
    explicit ResultadosBusqueda(QWidget *parent = nullptr);
    ~ResultadosBusqueda();
    void agregarLibro(Libro *libro, int fila = 1);
    void agregarLista(ListaSimpleEnlazada *lista);
private:
    Ui::ResultadosBusqueda *ui;
};

#endif // RESULTADOSBUSQUEDA_H
