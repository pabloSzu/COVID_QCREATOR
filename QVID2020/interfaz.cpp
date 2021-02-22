

#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interfaz)
    ,netcsv(new AdminBD)
{
    ui->setupUi(this);
    this->setWindowTitle("Covid datos actualizados");

    netcsv->conectar("../bd/bd.sqlite");



    ui->listPaises->addItems(netcsv->getPaises());


    QIcon icono;
    icono.addFile(":/imagenes/icono1.ico");
    this->setWindowIcon(icono);
}

Interfaz::~Interfaz()
{
    delete ui;
    delete netcsv;
}

void Interfaz::delay(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}

void Interfaz::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPoint esquin_arriba_izq(10,80);
    QPoint esquin_abajo_der(this->width() - 70, this->height() - 75);
    QPen lapiz;
    lapiz.setColor(QColor(0,0,0));
    painter.setPen(lapiz);
    painter.fillRect(QRect(0,0,this->width(),this->height()),QColor(255,255,255));
    painter.drawRect(QRect(esquin_arriba_izq,esquin_abajo_der));
    painter.fillRect(QRect(esquin_arriba_izq,esquin_abajo_der),QColor(255,255,255));
    QFont serifFont("Times", 10, QFont::Bold);
    lapiz.setColor(QColor(255,255,0));
    lapiz.setWidth(5);
    painter.setPen(lapiz);




    //Busco el número más grande de contagios/recuperados/muertos para realizar la escala
    int maxCant=0;
    for (int i=0;i<dat_confir.size();i++){
        if (maxCant < dat_confir.at(i).at(1).toInt()){
            maxCant = dat_confir.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_muert.size();i++){
        if (maxCant < dat_muert.at(i).at(1).toInt()){
            maxCant = dat_muert.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_recup.size();i++){
        if (maxCant < dat_recup.at(i).at(1).toInt()){
            maxCant = dat_recup.at(i).at(1).toInt();
        }
    }

    //Calculo los pasos para las distancias de puntos
    float pasoy = float(esquin_arriba_izq.y() - esquin_abajo_der.y()) / float(maxCant);
    float pasox = float(esquin_abajo_der.x() - esquin_arriba_izq.x()) / float(dat_confir.size());
    float x1 = esquin_arriba_izq.x();
    float y1 = esquin_abajo_der.y();
    float x2 = x1;
    float y2 = y1;

    lapiz.setWidth(5);
    if (ui->chkConfir->isChecked()){
        lapiz.setColor(QColor(0,0,255));
        painter.setPen(lapiz);
        for (int i=0;i<dat_confir.size();i++){
            x2 = x1 + pasox;
            y2 = esquin_abajo_der.y() + (dat_confir.at(i).at(1).toFloat() * pasoy);
            painter.drawLine(QLineF(x1,y1,x2,y2));
            x1 = x2;
            y1 = y2;
        }
            ui->label_3->show();
    }
                else {
                        ui->label_3->hide();
                     }

    x1 = esquin_arriba_izq.x();
    y1 = esquin_abajo_der.y();
    x2 = x1;
    y2 = y1;
    if (ui->chkRecup->isChecked()){
        lapiz.setColor(QColor(0,175,0));
        painter.setPen(lapiz);
        for (int i=0;i<dat_recup.size();i++){
            x2 = x1 + pasox;
            y2 = esquin_abajo_der.y() + (dat_recup.at(i).at(1).toFloat() * pasoy);
            painter.drawLine(QLineF(x1,y1,x2,y2));
            x1 = x2;
            y1 = y2;
        }
        ui->label->show();
    }
    else {
            ui->label->hide();
         }

    x1 = esquin_arriba_izq.x();
    y1 = esquin_abajo_der.y();
    x2 = x1;
    y2 = y1;
    if (ui->chkMuert->isChecked()){
        lapiz.setColor(QColor(250,0,0));
        painter.setPen(lapiz);
        for (int i=0;i<dat_muert.size();i++){
            x2 = x1 + pasox;
            y2 = esquin_abajo_der.y() + (dat_muert.at(i).at(1).toFloat() * pasoy);
            painter.drawLine(QLineF(x1,y1,x2,y2));
            x1 = x2;
            y1 = y2;
        }
        ui->label_2->show();
    }else {
        ui->label_2->hide();
         }


}

void Interfaz::listar_regiones(QString pais)
{
    QStringList reg = netcsv->getRegiones(pais);
    ui->listRegiones->clear();
    if (reg.size()!=0){
        ui->listRegiones->addItems(reg);
    }
    ui->listRegiones->addItem("Sin región/Total país");
}

void Interfaz::calcular_datos()
{
    ui->chkMuert->setChecked(true);
    ui->chkRecup->setChecked(true);
    ui->chkConfir->setChecked(true);


    this->dat_muert.clear();
    this->dat_recup.clear();
    this->dat_confir.clear();
    this->pais = ui->listPaises->currentText();
    this->region = ui->listRegiones->currentText();

    QString id_pais = netcsv->get_id_pais(pais);
    QString id_region = netcsv->get_id_region(region,id_pais);

    if (id_region!="0"){
        dat_muert = netcsv->obtener_datos("SELECT fecha,cant FROM muertes WHERE id_pais = '"
                                            +id_pais+"' AND id_region = '"+id_region+"'");
        dat_recup = netcsv->obtener_datos("SELECT fecha,cant FROM recuperados WHERE id_pais = '"
                                            +id_pais+"' AND id_region = '"+id_region+"'");
        dat_confir = netcsv->obtener_datos("SELECT fecha,cant FROM confirmados WHERE id_pais = '"
                                           +id_pais+"' AND id_region = '"+id_region+"'");
    }
    else {
        dat_muert = netcsv->obtener_datos("SELECT fecha,cant FROM muertes WHERE id_pais = '"
                                            +id_pais+"'");
        dat_recup = netcsv->obtener_datos("SELECT fecha,cant FROM recuperados WHERE id_pais = '"
                                            +id_pais+"'");
        dat_confir = netcsv->obtener_datos("SELECT fecha,cant FROM confirmados WHERE id_pais = '"
                                           +id_pais+"'");
    }
    dat_confir = netcsv->acumular_datos(dat_confir);
    dat_muert = netcsv->acumular_datos(dat_muert);
    dat_recup = netcsv->acumular_datos(dat_recup);

    int maxCant=0;
    for (int i=0;i<dat_confir.size();i++){
        if (maxCant < dat_confir.at(i).at(1).toInt()){
            maxCant = dat_confir.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_muert.size();i++){
        if (maxCant < dat_muert.at(i).at(1).toInt()){
            maxCant = dat_muert.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_recup.size();i++){
        if (maxCant < dat_recup.at(i).at(1).toInt()){
            maxCant = dat_recup.at(i).at(1).toInt();
        }
    }
    ui->lTotalCant->setText("Total:"+QString::number(maxCant));
    ui->lTotalCant->setAlignment(Qt::AlignRight);


    ui->lPriFecha->setText("Día 0");
    ui->lUltFecha->setText("Día "+QString::number(dat_confir.size()));


    ui->label_4->setStyleSheet("color:rgb(179, 179, 179);BACKGROUND-COLOR:rgb(255, 255, 255)");
    ui->label_5->setStyleSheet("color:rgb(179, 179, 179);BACKGROUND-COLOR:rgb(255, 255, 255)");


    ui->label_5->setText("Primera fecha registrada: "+ dat_confir.at(0).at(0));
    ui->label_4->setText("Última fecha registrada: "+ dat_confir.last().at(0));



    ui->label->setStyleSheet("BACKGROUND-COLOR:rgb(255, 254, 212);color:rgb(8, 159, 0)");
    ui->label_2->setStyleSheet("BACKGROUND-COLOR:rgb(255, 254, 212);color:rgb(238, 21, 18 )");
    ui->label_3->setStyleSheet("BACKGROUND-COLOR:rgb(255, 254, 212);color:rgb(2, 95, 154)");


    ui->label->setText("  RECUPERADOS:  "+dat_recup.last().at(1));
    ui->label_2->setText("  FALLECIDOS:  "+dat_muert.last().at(1));
    ui->label_3->setText("  CONFIRMADOS:  "+dat_confir.last().at(1));
}








