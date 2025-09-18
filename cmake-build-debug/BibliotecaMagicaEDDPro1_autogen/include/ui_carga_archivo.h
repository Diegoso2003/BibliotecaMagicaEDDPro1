/********************************************************************************
** Form generated from reading UI file 'carga_archivo.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGA_ARCHIVO_H
#define UI_CARGA_ARCHIVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CargaArchivo
{
public:
    QGridLayout *gridLayout;
    QPushButton *botonAnalizar;
    QPushButton *botonAgregarRuta;
    QLineEdit *rutaArchivo;
    QLabel *descripcion;

    void setupUi(QWidget *CargaArchivo)
    {
        if (CargaArchivo->objectName().isEmpty())
            CargaArchivo->setObjectName("CargaArchivo");
        CargaArchivo->resize(587, 154);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CargaArchivo->sizePolicy().hasHeightForWidth());
        CargaArchivo->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CargaArchivo);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        gridLayout->setContentsMargins(20, 20, 20, 20);
        botonAnalizar = new QPushButton(CargaArchivo);
        botonAnalizar->setObjectName("botonAnalizar");

        gridLayout->addWidget(botonAnalizar, 6, 0, 1, 1);

        botonAgregarRuta = new QPushButton(CargaArchivo);
        botonAgregarRuta->setObjectName("botonAgregarRuta");

        gridLayout->addWidget(botonAgregarRuta, 4, 0, 1, 1);

        rutaArchivo = new QLineEdit(CargaArchivo);
        rutaArchivo->setObjectName("rutaArchivo");
        rutaArchivo->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        rutaArchivo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(rutaArchivo, 1, 0, 1, 1);

        descripcion = new QLabel(CargaArchivo);
        descripcion->setObjectName("descripcion");
        descripcion->setMaximumSize(QSize(200, 50));
        descripcion->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        descripcion->setAlignment(Qt::AlignmentFlag::AlignCenter);
        descripcion->setWordWrap(false);
        descripcion->setMargin(0);
        descripcion->setIndent(-1);

        gridLayout->addWidget(descripcion, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignBottom);

        QWidget::setTabOrder(rutaArchivo, botonAgregarRuta);
        QWidget::setTabOrder(botonAgregarRuta, botonAnalizar);

        retranslateUi(CargaArchivo);

        QMetaObject::connectSlotsByName(CargaArchivo);
    } // setupUi

    void retranslateUi(QWidget *CargaArchivo)
    {
        CargaArchivo->setWindowTitle(QCoreApplication::translate("CargaArchivo", "Form", nullptr));
        botonAnalizar->setText(QCoreApplication::translate("CargaArchivo", "Iniciar analisis", nullptr));
        botonAgregarRuta->setText(QCoreApplication::translate("CargaArchivo", "Seleccionar archivo", nullptr));
        descripcion->setText(QCoreApplication::translate("CargaArchivo", "Seleccione la ruta del archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CargaArchivo: public Ui_CargaArchivo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGA_ARCHIVO_H
