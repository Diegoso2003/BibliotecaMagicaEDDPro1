/********************************************************************************
** Form generated from reading UI file 'resultadosbusqueda.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTADOSBUSQUEDA_H
#define UI_RESULTADOSBUSQUEDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ResultadosBusqueda
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tablaResultados;

    void setupUi(QDialog *ResultadosBusqueda)
    {
        if (ResultadosBusqueda->objectName().isEmpty())
            ResultadosBusqueda->setObjectName("ResultadosBusqueda");
        ResultadosBusqueda->resize(1037, 300);
        ResultadosBusqueda->setMinimumSize(QSize(1037, 300));
        ResultadosBusqueda->setMaximumSize(QSize(1037, 16777215));
        verticalLayout = new QVBoxLayout(ResultadosBusqueda);
        verticalLayout->setObjectName("verticalLayout");
        tablaResultados = new QTableWidget(ResultadosBusqueda);
        if (tablaResultados->columnCount() < 6)
            tablaResultados->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaResultados->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablaResultados->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablaResultados->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablaResultados->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tablaResultados->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tablaResultados->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tablaResultados->setObjectName("tablaResultados");
        tablaResultados->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);

        verticalLayout->addWidget(tablaResultados);


        retranslateUi(ResultadosBusqueda);

        QMetaObject::connectSlotsByName(ResultadosBusqueda);
    } // setupUi

    void retranslateUi(QDialog *ResultadosBusqueda)
    {
        ResultadosBusqueda->setWindowTitle(QCoreApplication::translate("ResultadosBusqueda", "Resultados", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablaResultados->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ResultadosBusqueda", "ISBN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablaResultados->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ResultadosBusqueda", "Titulo", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablaResultados->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ResultadosBusqueda", "Genero", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tablaResultados->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ResultadosBusqueda", "A\303\261o Pub.", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tablaResultados->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ResultadosBusqueda", "Autor", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tablaResultados->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ResultadosBusqueda", "Cantidad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultadosBusqueda: public Ui_ResultadosBusqueda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTADOSBUSQUEDA_H
