/********************************************************************************
** Form generated from reading UI file 'dialogerrorarchivo.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGERRORARCHIVO_H
#define UI_DIALOGERRORARCHIVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogErrorArchivo
{
public:
    QGridLayout *gridLayout;
    QTextEdit *mensajeError;

    void setupUi(QDialog *DialogErrorArchivo)
    {
        if (DialogErrorArchivo->objectName().isEmpty())
            DialogErrorArchivo->setObjectName("DialogErrorArchivo");
        DialogErrorArchivo->resize(700, 500);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogErrorArchivo->sizePolicy().hasHeightForWidth());
        DialogErrorArchivo->setSizePolicy(sizePolicy);
        DialogErrorArchivo->setMinimumSize(QSize(700, 500));
        DialogErrorArchivo->setMaximumSize(QSize(700, 500));
        DialogErrorArchivo->setModal(true);
        gridLayout = new QGridLayout(DialogErrorArchivo);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 20, 20, 20);
        mensajeError = new QTextEdit(DialogErrorArchivo);
        mensajeError->setObjectName("mensajeError");
        mensajeError->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        mensajeError->setLineWrapMode(QTextEdit::LineWrapMode::NoWrap);
        mensajeError->setReadOnly(true);

        gridLayout->addWidget(mensajeError, 0, 0, 1, 1);


        retranslateUi(DialogErrorArchivo);

        QMetaObject::connectSlotsByName(DialogErrorArchivo);
    } // setupUi

    void retranslateUi(QDialog *DialogErrorArchivo)
    {
        DialogErrorArchivo->setWindowTitle(QCoreApplication::translate("DialogErrorArchivo", "Error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogErrorArchivo: public Ui_DialogErrorArchivo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGERRORARCHIVO_H
