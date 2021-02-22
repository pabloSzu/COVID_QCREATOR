#include "csvtodb.h"
#include <QWaitCondition>



CsvToDb::CsvToDb(QObject *parent):QObject(parent),
                                  nombres_campos_csv(new QList<QByteArray>),
                                  lineas_csv(new QList<QByteArray>)

{

    base.conectar(BD_STR);

}

CsvToDb::~CsvToDb()
{

    delete nombres_campos_csv;
    delete lineas_csv;
    base.cerrar();

}




QString CsvToDb::get_id_pais(QString pais)
{
    QString id = "0";
    id = base.consulta("SELECT id FROM paises WHERE pais = '"+pais+"'").at(0).at(0);
    return id;
}

QString CsvToDb::get_id_region(QString region, QString id_pais)
{
    QString id = "0";
    if (region != "" && region != "Sin región/Total país"){
        id = base.consulta("SELECT id FROM regiones WHERE region = '"+region+"' AND id_pais = '"+id_pais+"'").at(0).at(0);
    }
    return id;
}

QVector<QStringList> CsvToDb::obtener_datos(QString consulta)
{
    return base.consulta(consulta);
}

QVector<QStringList> CsvToDb::acumular_datos(QVector<QStringList> orig)
{
    QVector<QStringList> result,vaux;
    vaux = orig;
    int iaux;
    QString fecha;
    QString dato;
    QStringList laux;

    for (int i=0;i<vaux.size();i++){
        laux.clear();
        fecha = vaux.at(i).at(0);
        iaux = vaux.at(i).at(1).toInt();
        for (int j=i+1;j<vaux.size();j++){
            if (vaux.at(j).at(0)==fecha){
                iaux += vaux.at(j).at(1).toInt();
                vaux.remove(j);
                j--;
            }
        }
        dato = QString::number(iaux);
        laux.append(fecha);
        laux.append(dato);
        result.append(laux);
    }

    return result;
}






QStringList CsvToDb::getPaises()
{
    QStringList r;
    QVector<QStringList> paises_bd = base.consulta("SELECT pais FROM paises ORDER BY pais");

    for (int i=0;i<paises_bd.size();i++){
        r.append(paises_bd.at(i));
    }
    return r;
}

QStringList CsvToDb::getRegiones(QString pais)
{
    QStringList r;
    QString idPais = this->get_id_pais(pais);
    QVector<QStringList> regiones_bd;
    if (idPais != "0"){
        regiones_bd = base.consulta("SELECT region FROM regiones WHERE id_pais = '"+idPais+"' ORDER BY region");
        for (int i=0; i< regiones_bd.size();i++){
            r.append(regiones_bd.at(i));
        }
    }
    return r;
}

