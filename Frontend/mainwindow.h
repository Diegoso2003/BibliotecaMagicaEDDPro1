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

private:
    Ui::MainWindow *ui;
    Biblioteca *biblioteca;
    void crearGrafica(const std::string& grafica = "", bool r = false, std::string nombre = "");
};

#endif // MAINWINDOW_H
