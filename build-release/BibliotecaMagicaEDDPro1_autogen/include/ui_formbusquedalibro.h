/********************************************************************************
** Form generated from reading UI file 'formbusquedalibro.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMBUSQUEDALIBRO_H
#define UI_FORMBUSQUEDALIBRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormBusquedaLibro
{
public:
    QFormLayout *formLayout;
    QLabel *descripcion;
    QLineEdit *valorBusqueda;
    QPushButton *botonBuscar;
    QSpacerItem *verticalSpacer_2;
    QLabel *etiqueta1;
    QLabel *etiqueta2;
    QLabel *etiqueta3;

    void setupUi(QWidget *FormBusquedaLibro)
    {
        if (FormBusquedaLibro->objectName().isEmpty())
            FormBusquedaLibro->setObjectName("FormBusquedaLibro");
        FormBusquedaLibro->resize(518, 152);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormBusquedaLibro->sizePolicy().hasHeightForWidth());
        FormBusquedaLibro->setSizePolicy(sizePolicy);
        FormBusquedaLibro->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        formLayout = new QFormLayout(FormBusquedaLibro);
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignTop);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        descripcion = new QLabel(FormBusquedaLibro);
        descripcion->setObjectName("descripcion");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, descripcion);

        valorBusqueda = new QLineEdit(FormBusquedaLibro);
        valorBusqueda->setObjectName("valorBusqueda");
        valorBusqueda->setMinimumSize(QSize(400, 0));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, valorBusqueda);

        botonBuscar = new QPushButton(FormBusquedaLibro);
        botonBuscar->setObjectName("botonBuscar");
        botonBuscar->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, botonBuscar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(6, QFormLayout::ItemRole::LabelRole, verticalSpacer_2);

        etiqueta1 = new QLabel(FormBusquedaLibro);
        etiqueta1->setObjectName("etiqueta1");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, etiqueta1);

        etiqueta2 = new QLabel(FormBusquedaLibro);
        etiqueta2->setObjectName("etiqueta2");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, etiqueta2);

        etiqueta3 = new QLabel(FormBusquedaLibro);
        etiqueta3->setObjectName("etiqueta3");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, etiqueta3);


        retranslateUi(FormBusquedaLibro);

        QMetaObject::connectSlotsByName(FormBusquedaLibro);
    } // setupUi

    void retranslateUi(QWidget *FormBusquedaLibro)
    {
        FormBusquedaLibro->setWindowTitle(QCoreApplication::translate("FormBusquedaLibro", "Form", nullptr));
        descripcion->setText(QCoreApplication::translate("FormBusquedaLibro", "Buscar libro", nullptr));
        valorBusqueda->setPlaceholderText(QString());
        botonBuscar->setText(QCoreApplication::translate("FormBusquedaLibro", "Buscar", nullptr));
        etiqueta1->setText(QString());
        etiqueta2->setText(QString());
        etiqueta3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormBusquedaLibro: public Ui_FormBusquedaLibro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMBUSQUEDALIBRO_H
