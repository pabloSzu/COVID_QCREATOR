/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QAction *actionEliminar_argumento;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pbs1;
    QPushButton *pbs2;
    QPushButton *pbs3;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QPushButton *info;
    QLabel *label_3;
    QLineEdit *programaLineEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSlider *slider_gamma;
    QLCDNumber *lcd2;
    QLCDNumber *lcd3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLCDNumber *lcd00;
    QSlider *slider_beta;
    QLabel *label_4;
    QLCDNumber *lcd0;
    QLabel *label_2;
    QLCDNumber *lcd1;
    QSlider *slider_tmax;
    QPushButton *pb_info1;
    QPushButton *pb_info2;
    QPushButton *pb_info3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ejecutarPushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *quitarPushButton;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::WindowModal);
        Widget->resize(876, 738);
        Widget->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR:rgb(255, 254, 212)"));
        actionEliminar_argumento = new QAction(Widget);
        actionEliminar_argumento->setObjectName(QString::fromUtf8("actionEliminar_argumento"));
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Tw Cen MT Condensed Extra Bold"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setMargin(-4);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        pbs1 = new QPushButton(Widget);
        pbs1->setObjectName(QString::fromUtf8("pbs1"));
        pbs1->setCursor(QCursor(Qt::ClosedHandCursor));

        verticalLayout->addWidget(pbs1);

        pbs2 = new QPushButton(Widget);
        pbs2->setObjectName(QString::fromUtf8("pbs2"));
        pbs2->setCursor(QCursor(Qt::ClosedHandCursor));

        verticalLayout->addWidget(pbs2);

        pbs3 = new QPushButton(Widget);
        pbs3->setObjectName(QString::fromUtf8("pbs3"));
        pbs3->setCursor(QCursor(Qt::ClosedHandCursor));

        verticalLayout->addWidget(pbs3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        info = new QPushButton(groupBox_2);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(380, 25, 71, 28));
        info->setCursor(QCursor(Qt::ClosedHandCursor));
        info->setStyleSheet(QString::fromUtf8("background-color:rgb(48, 255, 176);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        info->setIcon(icon);

        verticalLayout->addWidget(groupBox_2);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        programaLineEdit = new QLineEdit(Widget);
        programaLineEdit->setObjectName(QString::fromUtf8("programaLineEdit"));
        programaLineEdit->setEnabled(true);
        programaLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));

        verticalLayout->addWidget(programaLineEdit);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        slider_gamma = new QSlider(groupBox);
        slider_gamma->setObjectName(QString::fromUtf8("slider_gamma"));
        slider_gamma->setCursor(QCursor(Qt::ClosedHandCursor));
        slider_gamma->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_gamma, 5, 2, 1, 1);

        lcd2 = new QLCDNumber(groupBox);
        lcd2->setObjectName(QString::fromUtf8("lcd2"));
        lcd2->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));
        lcd2->setSmallDecimalPoint(false);

        gridLayout->addWidget(lcd2, 4, 4, 1, 1);

        lcd3 = new QLCDNumber(groupBox);
        lcd3->setObjectName(QString::fromUtf8("lcd3"));
        lcd3->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));
        lcd3->setSmallDecimalPoint(false);

        gridLayout->addWidget(lcd3, 5, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        lcd00 = new QLCDNumber(groupBox);
        lcd00->setObjectName(QString::fromUtf8("lcd00"));
        lcd00->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));

        gridLayout->addWidget(lcd00, 5, 3, 1, 1);

        slider_beta = new QSlider(groupBox);
        slider_beta->setObjectName(QString::fromUtf8("slider_beta"));
        slider_beta->setCursor(QCursor(Qt::ClosedHandCursor));
        slider_beta->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_beta, 4, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        lcd0 = new QLCDNumber(groupBox);
        lcd0->setObjectName(QString::fromUtf8("lcd0"));
        lcd0->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));
        lcd0->setInputMethodHints(Qt::ImhNone);
        lcd0->setMidLineWidth(0);

        gridLayout->addWidget(lcd0, 4, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        lcd1 = new QLCDNumber(groupBox);
        lcd1->setObjectName(QString::fromUtf8("lcd1"));
        lcd1->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"color:rgb(0, 0, 0)"));

        gridLayout->addWidget(lcd1, 3, 3, 1, 2);

        slider_tmax = new QSlider(groupBox);
        slider_tmax->setObjectName(QString::fromUtf8("slider_tmax"));
        slider_tmax->setCursor(QCursor(Qt::ClosedHandCursor));
        slider_tmax->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_tmax, 3, 2, 1, 1);

        pb_info1 = new QPushButton(groupBox);
        pb_info1->setObjectName(QString::fromUtf8("pb_info1"));
        pb_info1->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR:rgb(255, 254, 212)"));
        pb_info1->setIcon(icon);
        pb_info1->setFlat(true);

        gridLayout->addWidget(pb_info1, 3, 0, 1, 1);

        pb_info2 = new QPushButton(groupBox);
        pb_info2->setObjectName(QString::fromUtf8("pb_info2"));
        pb_info2->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR:rgb(255, 254, 212)"));
        pb_info2->setIcon(icon);
        pb_info2->setFlat(true);

        gridLayout->addWidget(pb_info2, 4, 0, 1, 1);

        pb_info3 = new QPushButton(groupBox);
        pb_info3->setObjectName(QString::fromUtf8("pb_info3"));
        pb_info3->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR:rgb(255, 254, 212)"));
        pb_info3->setIcon(icon);
        pb_info3->setIconSize(QSize(20, 20));
        pb_info3->setFlat(true);

        gridLayout->addWidget(pb_info3, 5, 0, 1, 1);

        slider_gamma->raise();
        slider_beta->raise();
        label_4->raise();
        slider_tmax->raise();
        label_5->raise();
        label_2->raise();
        lcd2->raise();
        lcd3->raise();
        lcd1->raise();
        lcd00->raise();
        lcd0->raise();
        pb_info1->raise();
        pb_info2->raise();
        pb_info3->raise();

        verticalLayout->addWidget(groupBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);

        ejecutarPushButton = new QPushButton(Widget);
        ejecutarPushButton->setObjectName(QString::fromUtf8("ejecutarPushButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Rockwell"));
        font2.setPointSize(16);
        ejecutarPushButton->setFont(font2);
        ejecutarPushButton->setCursor(QCursor(Qt::ClosedHandCursor));

        verticalLayout->addWidget(ejecutarPushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        quitarPushButton = new QPushButton(Widget);
        quitarPushButton->setObjectName(QString::fromUtf8("quitarPushButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Rockwell"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        quitarPushButton->setFont(font3);
        quitarPushButton->setCursor(QCursor(Qt::ClosedHandCursor));

        horizontalLayout->addWidget(quitarPushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout_4->addLayout(verticalLayout_2);

        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);


        retranslateUi(Widget);

        pb_info3->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        actionEliminar_argumento->setText(QApplication::translate("Widget", "Eliminar argumento", nullptr));
        label->setText(QApplication::translate("Widget", "                                 SIMULADOR", nullptr));
        pbs1->setText(QApplication::translate("Widget", "CURVAS DE LA CAPACIDAD DEL SISTEMA DE SALUD", nullptr));
        pbs2->setText(QApplication::translate("Widget", "CURVAS DE RECUPERADOS E INFECTADOS", nullptr));
        pbs3->setText(QApplication::translate("Widget", "CURVAS DE LA VARIABILIDAD DE RO", nullptr));
        groupBox_2->setTitle(QString());
        info->setText(QString());
        label_3->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Ruta del c\303\263digo del programa simulador a ejecutar:</span></p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "     ARGUMENTOS:", nullptr));
        label_5->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#0055ff;\">GAMMA</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#00aa00;\">BETA</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#aa0000;\">Tiempo m\303\241ximo a mostrar</span></p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        slider_tmax->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>T-MAX</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pb_info1->setText(QString());
        pb_info2->setText(QString());
        pb_info3->setText(QString());
        ejecutarPushButton->setText(QApplication::translate("Widget", "SIMULAR", nullptr));
        quitarPushButton->setText(QApplication::translate("Widget", "CERRAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
