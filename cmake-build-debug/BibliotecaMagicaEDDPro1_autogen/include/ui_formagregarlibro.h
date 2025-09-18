/********************************************************************************
** Form generated from reading UI file 'formagregarlibro.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMAGREGARLIBRO_H
#define UI_FORMAGREGARLIBRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormAgregarLibro
{
public:
    QLabel *label;

    void setupUi(QWidget *FormAgregarLibro)
    {
        if (FormAgregarLibro->objectName().isEmpty())
            FormAgregarLibro->setObjectName("FormAgregarLibro");
        FormAgregarLibro->resize(400, 300);
        label = new QLabel(FormAgregarLibro);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 170, 161, 18));

        retranslateUi(FormAgregarLibro);

        QMetaObject::connectSlotsByName(FormAgregarLibro);
    } // setupUi

    void retranslateUi(QWidget *FormAgregarLibro)
    {
        FormAgregarLibro->setWindowTitle(QCoreApplication::translate("FormAgregarLibro", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormAgregarLibro", "agregar libro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormAgregarLibro: public Ui_FormAgregarLibro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMAGREGARLIBRO_H
