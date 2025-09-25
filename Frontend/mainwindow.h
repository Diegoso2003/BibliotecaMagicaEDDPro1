#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Backend/Biblioteca/Biblioteca.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionCargar_archivo_csv_triggered();
    void on_actionAgregar_libro_triggered();

    void on_actionGrafico_de_arbol_AVL_ordenado_por_ISBN_triggered();

    void on_actionGrafico_de_arbol_AVl_ordenado_por_titulo_triggered();

    void on_actionGrafico_arbol_B_ordenado_por_a_o_triggered();

private:
    Ui::MainWindow *ui;
    Biblioteca *biblioteca;
    void crearGrafica(std::string &nombre,const std::string& grafica, bool r = false);
};

#endif // MAINWINDOW_H
