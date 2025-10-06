/********************************************************************************
** Form generated from reading UI file 'formeliminacionlibro.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMELIMINACIONLIBRO_H
#define UI_FORMELIMINACIONLIBRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormEliminacionLibro
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *isbnEliminar;
    QPushButton *botonEliminar;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormEliminacionLibro)
    {
        if (FormEliminacionLibro->objectName().isEmpty())
            FormEliminacionLibro->setObjectName("FormEliminacionLibro");
        FormEliminacionLibro->resize(549, 351);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormEliminacionLibro->sizePolicy().hasHeightForWidth());
        FormEliminacionLibro->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(FormEliminacionLibro);
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        label = new QLabel(FormEliminacionLibro);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 50));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        isbnEliminar = new QLineEdit(FormEliminacionLibro);
        isbnEliminar->setObjectName("isbnEliminar");
        isbnEliminar->setMinimumSize(QSize(300, 0));
        isbnEliminar->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, isbnEliminar);

        botonEliminar = new QPushButton(FormEliminacionLibro);
        botonEliminar->setObjectName("botonEliminar");
        botonEliminar->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, botonEliminar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(2, QFormLayout::ItemRole::FieldRole, verticalSpacer);


        retranslateUi(FormEliminacionLibro);

        QMetaObject::connectSlotsByName(FormEliminacionLibro);
    } // setupUi

    void retranslateUi(QWidget *FormEliminacionLibro)
    {
        FormEliminacionLibro->setWindowTitle(QCoreApplication::translate("FormEliminacionLibro", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormEliminacionLibro", "Ingrese el isbn del libro a eliminar", nullptr));
        isbnEliminar->setPlaceholderText(QString());
        botonEliminar->setText(QCoreApplication::translate("FormEliminacionLibro", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormEliminacionLibro: public Ui_FormEliminacionLibro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMELIMINACIONLIBRO_H
