#ifndef CSVTODB_H
#define CSVTODB_H

#define BD_HOST "ontecnologia.com.ar"
#define BD_USER "xfnfttiw_covid_admin"
#define BD_PASS "Cumbr3s2020."
#define BD_NAME "xfnfttiw_db_covid19"
#define BD_PORT "3306"
#define BD_TIPO "QMYSQL"

#define BD_STR "../bd/bd.sqlite"

//Clase base
#include <QObject>

//Clases de conectividad
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

//Clases auxiliares
#include <QDebug>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QTimer>
#include <QEventLoop>

//Clase de manejo de base de datos
#include "adminbd.h"

class CsvToDb : public QObject
{
    Q_OBJECT
public:
    explicit CsvToDb(QObject *parent = nullptr);
    ~CsvToDb();

    bool actualizar_tabla(QString str_csv, QString str_tabla);
    QStringList getPaises();
    QStringList getRegiones(QString pais);
    QString get_id_pais(QString pais);
    QString get_id_region(QString region, QString id_pais);
    QVector<QStringList> obtener_datos(QString consulta);
    QVector<QStringList> acumular_datos(QVector<QStringList> orig);



    bool getForzar_actualizacion() const;

private:
    QString tabla;
    QString csv_url_str;
    QList<QByteArray> *nombres_campos_csv;
    QList<QByteArray> *lineas_csv;
    AdminBD base;                                 //Clase Admin db para el manejo de base de datos


signals:
    void csv_cargado();
    void progreso(QString,int,int);

};

#endif // CSVTODB_H
