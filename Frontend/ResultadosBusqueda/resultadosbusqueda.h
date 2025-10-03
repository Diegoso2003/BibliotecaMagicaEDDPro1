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
    void agregarLista(ListaSimpleEnlazada *lista);
    void ajustarTabla();
    void agregarLibro(Libro *libro);
private:
    void agregarItemCentrado(int fila, int columna, QString valor);
    void agregarLibro(Libro *libro, int fila);
    Ui::ResultadosBusqueda *ui;
};

#endif // RESULTADOSBUSQUEDA_H
