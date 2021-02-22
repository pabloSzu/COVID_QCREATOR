/********************************************************************************
** Form generated from reading UI file 'interfaz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZ_H
#define UI_INTERFAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interfaz
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbSalir;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *lTotalCant;
    QLabel *label_4;
    QLabel *label;
    QGridLayout *gridLayout_7;
    QCheckBox *chkRecup;
    QCheckBox *chkConfir;
    QCheckBox *chkMuert;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_6;
    QComboBox *listPaises;
    QComboBox *listRegiones;
    QPushButton *pbCalcular;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_4;
    QLabel *lUltFecha;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QGridLayout *gridLayout_3;
    QLabel *lPriFecha;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *Interfaz)
    {
        if (Interfaz->objectName().isEmpty())
            Interfaz->setObjectName(QString::fromUtf8("Interfaz"));
        Interfaz->resize(747, 633);
        Interfaz->setMinimumSize(QSize(640, 480));
        Interfaz->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR:rgb(255, 254, 212)"));
        gridLayout = new QGridLayout(Interfaz);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pbSalir = new QPushButton(Interfaz);
        pbSalir->setObjectName(QString::fromUtf8("pbSalir"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Black"));
        font.setBold(true);
        font.setWeight(75);
        pbSalir->setFont(font);

        gridLayout_9->addWidget(pbSalir, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_9, 19, 8, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 9, 8, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 8, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_5, 12, 8, 1, 1);

        label_2 = new QLabel(Interfaz);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(107, 3, 115);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_2, 12, 0, 1, 1);

        label_5 = new QLabel(Interfaz);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_5, 13, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 15, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 7, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        lTotalCant = new QLabel(Interfaz);
        lTotalCant->setObjectName(QString::fromUtf8("lTotalCant"));
        lTotalCant->setMinimumSize(QSize(100, 20));
        lTotalCant->setMaximumSize(QSize(100, 20));
        lTotalCant->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(lTotalCant, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 8, 2, 1);

        label_4 = new QLabel(Interfaz);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_4, 14, 0, 1, 1);

        label = new QLabel(Interfaz);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(56, 106, 4);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label, 9, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        chkRecup = new QCheckBox(Interfaz);
        chkRecup->setObjectName(QString::fromUtf8("chkRecup"));
        chkRecup->setFont(font);

        gridLayout_7->addWidget(chkRecup, 0, 1, 1, 1);

        chkConfir = new QCheckBox(Interfaz);
        chkConfir->setObjectName(QString::fromUtf8("chkConfir"));
        chkConfir->setFont(font);

        gridLayout_7->addWidget(chkConfir, 0, 0, 1, 1);

        chkMuert = new QCheckBox(Interfaz);
        chkMuert->setObjectName(QString::fromUtf8("chkMuert"));
        chkMuert->setFont(font);

        gridLayout_7->addWidget(chkMuert, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_7, 1, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));

        gridLayout->addLayout(gridLayout_8, 19, 0, 1, 3);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        listPaises = new QComboBox(Interfaz);
        listPaises->setObjectName(QString::fromUtf8("listPaises"));
        listPaises->setMinimumSize(QSize(125, 20));
        listPaises->setMaximumSize(QSize(125, 20));
        listPaises->setFont(font);

        gridLayout_6->addWidget(listPaises, 0, 0, 1, 1);

        listRegiones = new QComboBox(Interfaz);
        listRegiones->setObjectName(QString::fromUtf8("listRegiones"));
        listRegiones->setMinimumSize(QSize(136, 20));
        listRegiones->setMaximumSize(QSize(163, 20));
        listRegiones->setFont(font);

        gridLayout_6->addWidget(listRegiones, 0, 1, 1, 1);

        pbCalcular = new QPushButton(Interfaz);
        pbCalcular->setObjectName(QString::fromUtf8("pbCalcular"));
        pbCalcular->setFont(font);
        pbCalcular->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 255);"));

        gridLayout_6->addWidget(pbCalcular, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_6, 0, 0, 1, 4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 4, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lUltFecha = new QLabel(Interfaz);
        lUltFecha->setObjectName(QString::fromUtf8("lUltFecha"));
        lUltFecha->setMinimumSize(QSize(85, 25));
        lUltFecha->setMaximumSize(QSize(85, 20));
        lUltFecha->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_4->addWidget(lUltFecha, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 16, 8, 1, 1);

        label_3 = new QLabel(Interfaz);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI Black"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lPriFecha = new QLabel(Interfaz);
        lPriFecha->setObjectName(QString::fromUtf8("lPriFecha"));
        lPriFecha->setMinimumSize(QSize(85, 25));
        lPriFecha->setMaximumSize(QSize(85, 20));
        lPriFecha->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(lPriFecha, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 16, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 8, 8, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 9, 1, 1, 1);


        retranslateUi(Interfaz);
        QObject::connect(pbSalir, SIGNAL(released()), Interfaz, SLOT(close()));
        QObject::connect(listPaises, SIGNAL(highlighted(QString)), Interfaz, SLOT(listar_regiones(QString)));
        QObject::connect(pbCalcular, SIGNAL(pressed()), Interfaz, SLOT(calcular_datos()));
        QObject::connect(pbCalcular, SIGNAL(pressed()), Interfaz, SLOT(repaint()));
        QObject::connect(chkConfir, SIGNAL(clicked()), Interfaz, SLOT(repaint()));
        QObject::connect(chkRecup, SIGNAL(clicked()), Interfaz, SLOT(repaint()));
        QObject::connect(chkMuert, SIGNAL(clicked()), Interfaz, SLOT(repaint()));

        QMetaObject::connectSlotsByName(Interfaz);
    } // setupUi

    void retranslateUi(QWidget *Interfaz)
    {
        Interfaz->setWindowTitle(QApplication::translate("Interfaz", "Form", nullptr));
        pbSalir->setText(QApplication::translate("Interfaz", "Salir", nullptr));
        label_2->setText(QString());
        label_5->setText(QString());
        lTotalCant->setText(QString());
        label_4->setText(QString());
        label->setText(QString());
        chkRecup->setText(QApplication::translate("Interfaz", "Recuperados", nullptr));
        chkConfir->setText(QApplication::translate("Interfaz", "Confirmados", nullptr));
        chkMuert->setText(QApplication::translate("Interfaz", "Muertes", nullptr));
        pbCalcular->setText(QApplication::translate("Interfaz", "Calcular Gr\303\241ficas", nullptr));
        lUltFecha->setText(QString());
        label_3->setText(QString());
        lPriFecha->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Interfaz: public Ui_Interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
