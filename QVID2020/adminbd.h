#ifndef ADMINBD_H
#define ADMINBD_H



#define BD_STR "../bd/bd.sqlite"

//Clase base
#include <QObject>

//Clases SQL
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlResult>
#include <QVariant>  //Tipo devuelto por query.value
#include <QtSql>

//Clases auxiliares
#include <QFileInfo>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QDebug>

class AdminBD : public QObject
{
    Q_OBJECT
public:
    explicit AdminBD( QObject * parent = nullptr );
    ~AdminBD();

    int conectar( QString str_arch_bd );
    int conectar (QString host, QString base, QString user, QString pass, QString tipo, QString puerto);
    QVector< QStringList > consulta ( QString str_consulta);
    bool insertar(QString str_dato);

    bool is_conected();
    bool comprobar_tabla( QString tabla );
    void cerrar();


    bool actualizar_tabla(QString str_csv, QString str_tabla);
    QStringList getPaises();
    QStringList getRegiones(QString pais);
    QString get_id_pais(QString pais);
    QString get_id_region(QString region, QString id_pais);
    QVector<QStringList> obtener_datos(QString consulta);
    QVector<QStringList> acumular_datos(QVector<QStringList> orig);


private:
    QString * str_base;
    QSqlDatabase bd;

public slots:

private slots:

signals:

};

#endif // ADMINBD_H
