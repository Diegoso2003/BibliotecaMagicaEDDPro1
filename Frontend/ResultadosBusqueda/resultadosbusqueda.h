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
    ~ResultadosBusqueda() override;
    void agregarLibro(Libro *libro, int fila = 0);
    void agregarLista(ListaSimpleEnlazada *lista);
private:
    Ui::ResultadosBusqueda *ui;
};

#endif // RESULTADOSBUSQUEDA_H
