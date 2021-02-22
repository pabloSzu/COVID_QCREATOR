#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>
#include <QPaintDevice>
#include <QPainter>
#include <QMouseEvent>
#include <QToolTip>
#include "csvtodb.h"
#include <QTimer>
#include <QEventLoop>


namespace Ui {
class Interfaz;
}

class Interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = nullptr);
    ~Interfaz();

private:
    Ui::Interfaz *ui;
//    CsvToDb *netcsv;
    AdminBD *netcsv;
    QString pais;
    QString region;
    QVector<QStringList> dat_recup;
    QVector<QStringList> dat_confir;
    QVector<QStringList> dat_muert;
    void delay(int millisecondsWait);


protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void listar_regiones(QString pais);
    void calcular_datos();
    void forzarAct();

public slots:

signals:
    void sRango(int,int);
    void sValor(int);
    void sTexto(QString);
    void sig_SIR(QString);

};

#endif // INTERFAZ_H
