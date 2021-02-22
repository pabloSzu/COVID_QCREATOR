#include "Widget.h"
#include "ui_Widget.h"
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
#include <QProcessEnvironment>
#include <QObject>
#include <QMessageBox>
#include <QPainter>
#include <QImage>
#include <QFile>
#include <QDir>
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mProcess = new QProcess(this);
    //ui->argsListWidget->addActions({ ui->actionEliminar_argumento });

    connect(mProcess, &QProcess::readyReadStandardOutput, [&]()
    {
        auto data = mProcess->readAllStandardOutput();
    });

    connect(mProcess, &QProcess::readyReadStandardError, [&]()
    {
        auto data = mProcess->readAllStandardError();
    });


ui->slider_tmax->setRange(0,150);
ui->slider_tmax->setValue(0);
ui->slider_beta->setRange(10,70);
ui->slider_beta->setValue(0);
ui->slider_gamma->setRange(0,70);
ui->slider_gamma->setValue(0);

ui->lcd2->display("10");
ui->lcd0->display("0.");
ui->lcd00->display("0.");

connect(ui->slider_tmax, SIGNAL(valueChanged(int)), ui->lcd1, SLOT(display(int)));
connect(ui->slider_beta, SIGNAL(valueChanged(int)), ui->lcd2, SLOT(display(int)));
connect(ui->slider_gamma, SIGNAL(valueChanged(int)), ui->lcd3, SLOT(display(int)));


 ui->pbs1->setStyleSheet("* { background-color: rgb(74, 236, 196);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
 ui->pbs2->setStyleSheet("* { background-color: rgb(253, 243, 88);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
 ui->pbs3->setStyleSheet("* { background-color: rgb(255, 186, 252);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");

 ui->ejecutarPushButton->setStyleSheet("* { background-color: rgb(200, 255, 173);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
 ui->quitarPushButton->setStyleSheet("* { background-color: rgb(255, 26, 40);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
 ui->ejecutarPushButton->setDisabled(true);

connect(ui->pbs1, SIGNAL(pressed()), this, SLOT(slotSim1()));
connect(ui->pbs2, SIGNAL(pressed()), this, SLOT(slotSim2()));
connect(ui->pbs3, SIGNAL(pressed()), this, SLOT(slotSim3()));


ui->lcd2->setVisible(false);
ui->lcd0->setVisible(false);
ui->lcd00->setVisible(false);
ui->lcd1->setVisible(false);
ui->lcd3->setVisible(false);

ui->slider_tmax->setVisible(false);
ui->slider_beta->setVisible(false);
ui->slider_gamma->setVisible(false);

ui->label_2->setVisible(false);
ui->label_4->setVisible(false);
ui->label_5->setVisible(false);




ui->label_3->setVisible(false);
ui->programaLineEdit->setVisible(false);
ui->groupBox->setTitle("");
ui->groupBox_2->setVisible(false);
ui->pb_info1->setVisible(false);
ui->pb_info2->setVisible(false);
ui->pb_info3->setVisible(false);

connect(ui->info, SIGNAL(pressed()), this, SLOT(slotINFO()));


connect(ui->pb_info1, SIGNAL(pressed()), this, SLOT(slotINFOvar()));
connect(ui->pb_info2, SIGNAL(pressed()), this, SLOT(slotINFOvar1()));
connect(ui->pb_info3, SIGNAL(pressed()), this, SLOT(slotINFOvar2()));


QIcon icono;
icono.addFile(":/imagenes/icono1.ico");
this->setWindowIcon(icono);
}

Widget::~Widget()
{
    delete ui;
}






void Widget::on_ejecutarPushButton_clicked()
{
    auto program = ui->programaLineEdit->text();
    if (program.isEmpty()) {
        return;
    }

    QString a;
    a=ui->programaLineEdit->text();
if (ro_aux==0){
    a.append(" ");
    int aux_t_max=ui->slider_tmax->value();
    a.append(" ");
    float aux_beta=float(ui->slider_beta->value());
    a.append(" ");
    float aux_gamma=float(ui->slider_gamma->value());  //VALIDAR QUE GAMMA SEA MENOR A BETA
    a.append(QString("%1 %2 %3").arg(aux_t_max).arg(aux_beta/100).arg(aux_gamma/100));

    if(ui->slider_gamma->value() > ui->slider_beta->value() ){
        QMessageBox error;

        error.setText("El valor de Gamma debe ser mas chico que el de Beta");
        error.setWindowTitle("Error");
        error.exec();
    }
    else{


        system(a.toStdString().c_str());
        qDebug()<<a;

    }
}



else {

    a.append(" ");
    int aux_t_max=ui->slider_tmax->value();
    a.append(" ");
    float aux_beta=float(ui->slider_beta->value());
    a.append(" ");
    a.append(QString("%1 %2 %3").arg(aux_t_max).arg(aux_beta).arg(0));
        system(a.toStdString().c_str());
        qDebug()<<a;


}
}


void Widget::on_quitarPushButton_clicked()
{
    close();
}




void Widget::slotSim1()
{
    info_aux=1;
    ui->pb_info1->setVisible(true);
    ui->pb_info2->setVisible(true);
    ui->pb_info3->setVisible(true);
    disconnect(ui->pb_info2, SIGNAL(pressed()), this, SLOT(slotINFOvar2()));
    connect(ui->pb_info2, SIGNAL(pressed()), this, SLOT(slotINFOvar1()));

    ui->groupBox->setTitle("ARGUMENTOS");
    ui->label_3->setVisible(true);
    ui->programaLineEdit->setVisible(true);
    ui->groupBox_2->setVisible(true);

    ui->label_4->setText("BETA");
    ui->label_4->setStyleSheet("*{ font-size:10pt; font-weight:600; color:#00aa00;}");

    ui->lcd0->setStyleSheet("* {background-color:rgb(0, 0, 0 );}");
    ui->slider_tmax->setRange(0,150);
    ui->slider_tmax->setValue(0);
    ui->slider_beta->setRange(10,70);
    ui->slider_beta->setValue(0);
    ui->slider_gamma->setRange(0,70);
    ui->slider_gamma->setValue(0);

    ui->lcd2->display("10");
    ui->lcd0->display("0.");
    ui->lcd00->display("0.");

    connect(ui->slider_tmax, SIGNAL(valueChanged(int)), ui->lcd1, SLOT(display(int)));
    connect(ui->slider_beta, SIGNAL(valueChanged(int)), ui->lcd2, SLOT(display(int)));
    connect(ui->slider_gamma, SIGNAL(valueChanged(int)), ui->lcd3, SLOT(display(int)));
    disconnect(ui->slider_beta, SIGNAL(valueChanged(int)), ui->lcd0, SLOT(display(int)));
    ro_aux=0;
    ui->pbs1->setStyleSheet("* { background-color: rgb(74, 236, 196);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
    ui->pbs2->setStyleSheet("* { background-color: rgb(255, 255, 189);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;color: rgb(195, 195, 195);}");
    ui->pbs3->setStyleSheet("* { background-color: rgb(255, 231, 238);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;color: rgb(195, 195, 195);}");
    ui->ejecutarPushButton->setEnabled(true);
    ui->ejecutarPushButton->setStyleSheet("* { background-color: rgb(50, 245, 32);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");


    ui->lcd2->setVisible(true);
    ui->lcd1->setVisible(true);
    ui->lcd0->setVisible(true);
    ui->lcd3->setVisible(true);
    ui->lcd00->setVisible(true);


    ui->slider_tmax->setVisible(true);
    ui->slider_beta->setVisible(true);
    ui->slider_gamma->setVisible(true);

    ui->label_2->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);        

    auto filename = QFileDialog::getOpenFileName(this,
            "Abrir ejecutable", "../QVID2020/capacidad_sistema_de_salud.py", "Python files (*.py)");
    if (filename.isEmpty()) {
        return;
    }
    ui->programaLineEdit->setText(filename);



}
void Widget::slotSim2()
{
    info_aux=2;
    ui->pb_info1->setVisible(true);
    ui->pb_info2->setVisible(true);
    ui->pb_info3->setVisible(true);
    disconnect(ui->pb_info2, SIGNAL(pressed()), this, SLOT(slotINFOvar2()));
    connect(ui->pb_info2, SIGNAL(pressed()), this, SLOT(slotINFOvar1()));

    ui->groupBox_2->setVisible(true);



    ui->groupBox->setTitle("ARGUMENTOS");
    ui->label_3->setVisible(true);
    ui->programaLineEdit->setVisible(true);
    ui->label_4->setText("BETA");
    ui->label_4->setStyleSheet("*{ font-size:10pt; font-weight:600; color:#00aa00;}");
    ui->lcd0->setStyleSheet("* {background-color:rgb(0, 0, 0 );}");
    ui->slider_tmax->setRange(0,175);
    ui->slider_tmax->setValue(0);
    ui->slider_beta->setRange(10,70);
    ui->slider_beta->setValue(0);
    ui->slider_gamma->setRange(0,70);
    ui->slider_gamma->setValue(0);

    ui->lcd2->display("10");
    ui->lcd0->display("0.");
    ui->lcd00->display("0.");

    connect(ui->slider_tmax, SIGNAL(valueChanged(int)), ui->lcd1, SLOT(display(int)));
    connect(ui->slider_beta, SIGNAL(valueChanged(int)), ui->lcd2, SLOT(display(int)));
    connect(ui->slider_gamma, SIGNAL(valueChanged(int)), ui->lcd3, SLOT(display(int)));
    disconnect(ui->slider_beta, SIGNAL(valueChanged(int)), ui->lcd0, SLOT(display(int)));
    ro_aux=0;
    ui->pbs1->setStyleSheet("* { background-color: rgb(228, 255, 241);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;color: rgb(195, 195, 195);}");
    ui->pbs2->setStyleSheet("* { background-color: rgb(253, 243, 88);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
    ui->pbs3->setStyleSheet("* { background-color: rgb(255, 231, 238);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;color: rgb(195, 195, 195);}");
    ui->ejecutarPushButton->setEnabled(true);
    ui->ejecutarPushButton->setStyleSheet("* { background-color: rgb(50, 245, 32);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");


    ui->slider_tmax->setRange(0,175);
    ui->lcd2->setVisible(true);
    ui->lcd1->setVisible(true);
    ui->lcd0->setVisible(true);
    ui->lcd3->setVisible(true);
    ui->lcd00->setVisible(true);


    ui->slider_tmax->setVisible(true);
    ui->slider_beta->setVisible(true);
    ui->slider_gamma->setVisible(true);

    ui->label_2->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);

    auto filename = QFileDialog::getOpenFileName(this,
            "Abrir ejecutable", "../QVID2020/curvas_recuperados_e_infectados.py", "Python files (*.py)");
    if (filename.isEmpty()) {
        return;
    }
    ui->programaLineEdit->setText(filename);



}

void Widget::slotSim3()
{

    info_aux=3;
    ui->pb_info1->setVisible(true);
    ui->pb_info2->setVisible(true);
    ui->pb_info3->setVisible(false);
    disconnect(ui->pb_info2, SIGNAL(pressed()), this, SLOT(slotINFOvar1()));
    connect(ui->pb_info2, SIGNAL(pressed()), this, SLOT(slotINFOvar2()));


    ui->groupBox_2->setVisible(true);
    ui->groupBox->setTitle("ARGUMENTOS");
    ui->label_3->setVisible(true);
    ui->programaLineEdit->setVisible(true);
    ro_aux=1;
    ui->pbs1->setStyleSheet("* { background-color: rgb(228, 255, 241);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;color: rgb(195, 195, 195);}");
    ui->pbs2->setStyleSheet("* { background-color: rgb(255, 255, 189);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;color: rgb(195, 195, 195);}");
    ui->pbs3->setStyleSheet("* { background-color: rgb(255, 140, 201);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
    ui->ejecutarPushButton->setEnabled(true);
    ui->ejecutarPushButton->setStyleSheet("* { background-color: rgb(50, 245, 32);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");


    ui->lcd2->setVisible(true);
    ui->lcd1->setVisible(true);
    ui->lcd0->setVisible(true);
    ui->lcd3->setVisible(true);
    ui->lcd00->setVisible(true);


    ui->slider_tmax->setVisible(true);
    ui->slider_beta->setVisible(true);
    ui->slider_gamma->setVisible(true);

    ui->label_2->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);

    auto filename = QFileDialog::getOpenFileName(this,
            "Abrir ejecutable", "../QVID2020/simulacion_Ro_variable.py", "Python files (*.py)");


    ui->programaLineEdit->setText(filename);


    ui->slider_tmax->setRange(0,600);
    ui->slider_tmax->setValue(0);
    ui->slider_beta->setRange(1,10);
    ui->slider_beta->setValue(0);
    ui->slider_gamma->setVisible(false);
    ui->label_5->setVisible(false);
    ui->lcd3->setVisible(false);
    ui->lcd00->setVisible(false);
    ui->label_4->setText("Ro");
    ui->label_4->setStyleSheet("*{ font-size:10pt; font-weight:600; color:#00aa00;}");

    ui->lcd0->display("0");
    ui->lcd2->setVisible(false);

    connect(ui->slider_tmax, SIGNAL(valueChanged(int)), ui->lcd1, SLOT(display(int)));
    connect(ui->slider_beta, SIGNAL(valueChanged(int)), ui->lcd0, SLOT(display(int)));
    disconnect(ui->slider_beta, SIGNAL(valueChanged(int)), ui->lcd2, SLOT(display(int)));
//    connect(ui->slider_gamma, SIGNAL(valueChanged(int)), ui->lcd00, SLOT(display(int)));

 ui->lcd0->setGeometry(648,90,160,23);
 ui->lcd0->setStyleSheet("* {background-color:rgb(126, 7, 82 );}");

}
void Widget::slotINFO()
{
    QMessageBox error;
    error.setWindowTitle("INFORMACION");
    QIcon icono;
    icono.addFile(":/imagenes/icon.ico");
    error.setWindowIcon(icono);

    if (info_aux==1){
        error.setText("Se muestra la capacidad del sistema de salud en función de los días transcurridos. El eje vertical muestra el porcentaje de la población mundial y el eje horizontal los días desde el inicio de la epidemia.");
        error.exec();
    }
    if (info_aux==2){
        error.setText("Se muestra la curva de los recuperados y los infectados en función de los días transcurridos. El eje vertical muestra el porcentaje de la población mundial y el eje horizontal los días desde el inicio de la epidemia.");
        error.exec();
    }
    if (info_aux==3){
        error.setText("Se muestra la variabilidad de Ro con un Gamma fijo en función de los días transcurridos.");
        error.exec();
    }



qDebug()<<"--------------------"<<info_aux;
}


void Widget::slotINFOvar()
{
    QMessageBox error;
    error.setWindowTitle("TIEMPO MÁXIMO");

    QIcon icono;
    icono.addFile(":/imagenes/icon.ico");
    error.setWindowIcon(icono);
        error.setText("Representa los días transcurridos desde el inicio de la disperción del virus.");
        error.exec();
}
void Widget::slotINFOvar1()
{


    QMessageBox error;
    error.setWindowTitle("BETA");
    QIcon icono;
    icono.addFile(":/imagenes/icon.ico");
    error.setWindowIcon(icono);


        error.setText("Tasa de contagios (probabilidad de que una persona enferme al estar en contacto con un infectado).");
        error.exec();
}
void Widget::slotINFOvar2()
{
    QMessageBox error;
    error.setWindowTitle("GAMMA");
    QIcon icono;
    icono.addFile(":/imagenes/icon.ico");
    error.setWindowIcon(icono);
if (info_aux==1){
        error.setText("Tiempo promedio de infección (para un solo individuo).");
        error.exec();}
if (info_aux==2){
        error.setText("Tiempo promedio de infección (para un solo individuo).");
        error.exec();}
if (info_aux==3){
    error.setWindowTitle("RO");
        error.setText("Ritmo básico de reproducción (número promedio de casos nuevos que genera un caso dado a lo largo de un período infeccioso).");
        error.exec();}
}
