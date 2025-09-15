#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
