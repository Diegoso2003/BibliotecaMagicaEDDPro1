/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCargar_archivo_csv;
    QAction *actionAgregar_libro;
    QAction *actionEliminar_libro;
    QAction *actionpor_titulo;
    QAction *actionpor_ISBN;
    QAction *actionpor_genero;
    QAction *actionpor_fecha;
    QAction *actionListar_por_titulo;
    QAction *actionGrafico_de_arbol_AVL_ordenado_por_ISBN;
    QAction *actionGrafico_de_arbol_AVl_ordenado_por_titulo;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QMenuBar *menuBar;
    QMenu *menuhola;
    QMenu *menuLibro;
    QMenu *menuBuscar_libro;
    QMenu *menuGraficas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionCargar_archivo_csv = new QAction(MainWindow);
        actionCargar_archivo_csv->setObjectName("actionCargar_archivo_csv");
        actionAgregar_libro = new QAction(MainWindow);
        actionAgregar_libro->setObjectName("actionAgregar_libro");
        actionEliminar_libro = new QAction(MainWindow);
        actionEliminar_libro->setObjectName("actionEliminar_libro");
        actionpor_titulo = new QAction(MainWindow);
        actionpor_titulo->setObjectName("actionpor_titulo");
        actionpor_ISBN = new QAction(MainWindow);
        actionpor_ISBN->setObjectName("actionpor_ISBN");
        actionpor_genero = new QAction(MainWindow);
        actionpor_genero->setObjectName("actionpor_genero");
        actionpor_fecha = new QAction(MainWindow);
        actionpor_fecha->setObjectName("actionpor_fecha");
        actionListar_por_titulo = new QAction(MainWindow);
        actionListar_por_titulo->setObjectName("actionListar_por_titulo");
        actionGrafico_de_arbol_AVL_ordenado_por_ISBN = new QAction(MainWindow);
        actionGrafico_de_arbol_AVL_ordenado_por_ISBN->setObjectName("actionGrafico_de_arbol_AVL_ordenado_por_ISBN");
        actionGrafico_de_arbol_AVl_ordenado_por_titulo = new QAction(MainWindow);
        actionGrafico_de_arbol_AVl_ordenado_por_titulo->setObjectName("actionGrafico_de_arbol_AVl_ordenado_por_titulo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menuhola = new QMenu(menuBar);
        menuhola->setObjectName("menuhola");
        menuLibro = new QMenu(menuBar);
        menuLibro->setObjectName("menuLibro");
        menuBuscar_libro = new QMenu(menuLibro);
        menuBuscar_libro->setObjectName("menuBuscar_libro");
        menuGraficas = new QMenu(menuBar);
        menuGraficas->setObjectName("menuGraficas");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuhola->menuAction());
        menuBar->addAction(menuLibro->menuAction());
        menuBar->addAction(menuGraficas->menuAction());
        menuhola->addAction(actionCargar_archivo_csv);
        menuLibro->addAction(actionAgregar_libro);
        menuLibro->addAction(actionEliminar_libro);
        menuLibro->addAction(menuBuscar_libro->menuAction());
        menuLibro->addAction(actionListar_por_titulo);
        menuBuscar_libro->addAction(actionpor_titulo);
        menuBuscar_libro->addAction(actionpor_ISBN);
        menuBuscar_libro->addAction(actionpor_genero);
        menuBuscar_libro->addAction(actionpor_fecha);
        menuGraficas->addAction(actionGrafico_de_arbol_AVL_ordenado_por_ISBN);
        menuGraficas->addAction(actionGrafico_de_arbol_AVl_ordenado_por_titulo);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCargar_archivo_csv->setText(QCoreApplication::translate("MainWindow", "Cargar archivo csv", nullptr));
#if QT_CONFIG(tooltip)
        actionCargar_archivo_csv->setToolTip(QCoreApplication::translate("MainWindow", "Cargar nuevo archivo csv con info de libros", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAgregar_libro->setText(QCoreApplication::translate("MainWindow", "Agregar libro", nullptr));
        actionEliminar_libro->setText(QCoreApplication::translate("MainWindow", "Eliminar libro", nullptr));
        actionpor_titulo->setText(QCoreApplication::translate("MainWindow", "por titulo", nullptr));
        actionpor_ISBN->setText(QCoreApplication::translate("MainWindow", "por ISBN", nullptr));
        actionpor_genero->setText(QCoreApplication::translate("MainWindow", "por genero", nullptr));
        actionpor_fecha->setText(QCoreApplication::translate("MainWindow", "por fecha", nullptr));
        actionListar_por_titulo->setText(QCoreApplication::translate("MainWindow", "Listar por titulo", nullptr));
        actionGrafico_de_arbol_AVL_ordenado_por_ISBN->setText(QCoreApplication::translate("MainWindow", "Grafico de arbol AVL ordenado por ISBN", nullptr));
        actionGrafico_de_arbol_AVl_ordenado_por_titulo->setText(QCoreApplication::translate("MainWindow", "Grafico de arbol AVl ordenado por titulo", nullptr));
        menuhola->setTitle(QCoreApplication::translate("MainWindow", "Cargar archivo", nullptr));
        menuLibro->setTitle(QCoreApplication::translate("MainWindow", "Libro", nullptr));
        menuBuscar_libro->setTitle(QCoreApplication::translate("MainWindow", "Buscar libro", nullptr));
        menuGraficas->setTitle(QCoreApplication::translate("MainWindow", "Graficas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
