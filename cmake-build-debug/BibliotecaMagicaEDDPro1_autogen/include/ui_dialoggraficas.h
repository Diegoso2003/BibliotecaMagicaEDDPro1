/********************************************************************************
** Form generated from reading UI file 'dialoggraficas.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGRAFICAS_H
#define UI_DIALOGGRAFICAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DialogGraficas
{
public:

    void setupUi(QDialog *DialogGraficas)
    {
        if (DialogGraficas->objectName().isEmpty())
            DialogGraficas->setObjectName("DialogGraficas");
        DialogGraficas->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogGraficas->sizePolicy().hasHeightForWidth());
        DialogGraficas->setSizePolicy(sizePolicy);

        retranslateUi(DialogGraficas);

        QMetaObject::connectSlotsByName(DialogGraficas);
    } // setupUi

    void retranslateUi(QDialog *DialogGraficas)
    {
        DialogGraficas->setWindowTitle(QCoreApplication::translate("DialogGraficas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogGraficas: public Ui_DialogGraficas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGRAFICAS_H
