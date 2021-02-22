#include "adminbd.h"

AdminBD::AdminBD(QObject *parent):QObject(parent)
{
    bd = QSqlDatabase::addDatabase( "QSQLITE" );

}

AdminBD::~AdminBD()
{
    if (bd.isOpen()){
        bd.close();
    }
}

int AdminBD::conectar(QString str_arch_bd)
{
    bool existe_bd = QFileInfo::exists(str_arch_bd);
    bd.setDatabaseName(str_arch_bd);
    if (!existe_bd){
        QMessageBox::warning(nullptr,"Nueva base","Se ha creado una nueva.");
        if (bd.open()){
            QSqlQuery query(bd);
            query.exec("CREATE TABLE paises (id integer primary key autoincrement, pais varchar(250))");
            query.exec("CREATE TABLE regiones (id integer primary key autoincrement, region varchar(250), id_pais int)");
            query.exec("CREATE TABLE confirmados (id integer primary key autoincrement, fecha varchar(250), id_pais int, id_region int, cant int)");
            query.exec("CREATE TABLE muertes (id integer primary key autoincrement, fecha varchar(250), id_pais int, id_region int, cant int)");
            query.exec("CREATE TABLE recuperados (id integer primary key autoincrement, fecha varchar(250), id_pais int, id_region int, cant int)");
            //bd.close();
            QMessageBox::information(nullptr,"Base creada","Finalizó la creación de la base de datos");
            return 2;
        }
        else {
            QMessageBox::critical(nullptr,"ERROR","No se pudo abrir la base de datos");
            return 0;
        }
    }
    if (!bd.open()){
        return 0;
    }
    return 1;
}

int AdminBD::conectar(QString host, QString base, QString user, QString pass, QString tipo, QString puerto)
{
    if (bd.isOpen()){
        bd.close();
    }

    bd = QSqlDatabase::addDatabase(tipo);
    bd.setHostName(host);
    bd.setPort(puerto.toInt());
    bd.setUserName(user);
    bd.setPassword(pass);
    bd.setDatabaseName(base);

    if (!bd.open()){
        QMessageBox::critical(nullptr,"ERROR CONEXION BD "+tipo,"Hubo un error en la conexión con la base "+base);
        return 0;
    }
    else {
        if (comprobar_tabla("paises")){
            return 1;
        }
        else {
            QSqlQuery query(bd);
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`paises` ( `id` INT NOT NULL AUTO_INCREMENT , `pais` VARCHAR(250) NOT NULL , PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`regiones` ( `id` INT NOT NULL AUTO_INCREMENT , `region` VARCHAR(250) NOT NULL , `id_pais` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`confirmados` ( `id` INT NOT NULL AUTO_INCREMENT , `fecha` VARCHAR(250) NOT NULL , `id_pais` INT, `id_region` INT, `cant` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`muertes` ( `id` INT NOT NULL AUTO_INCREMENT , `fecha` VARCHAR(250) NOT NULL , `id_pais` INT, `id_region` INT, `cant` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`recuperados` ( `id` INT NOT NULL AUTO_INCREMENT , `fecha` VARCHAR(250) NOT NULL , `id_pais` INT, `id_region` INT, `cant` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            QMessageBox::warning(nullptr,"Base de datos vacía","La base de datos se encuentra vacía. Debe actualizarla.");
            return 2;
        }
    }
}

QVector<QStringList> AdminBD::consulta(QString str_consulta)
{
    QVector< QStringList > resultado;
    QStringList aux;
    if (!this->is_conected()){
        bd.open();
    }
    if (this->is_conected()){
        QSqlQuery query (bd);
        QSqlRecord record;

        if (query.exec(str_consulta)){

            while (query.next()) {
                aux.clear();
                record = query.record();
                int campos = record.count();

                for (int i=0;i<campos;i++){
                    aux.append(record.value(i).toString());
                }

                resultado.append(aux);
            }
        }
    }

    return resultado;
}

bool AdminBD::insertar(QString str_dato)
{
    if (!this->is_conected()){
        bd.open();
    }
    QSqlQuery query(bd);
    return query.exec(str_dato);
}

bool AdminBD::is_conected()
{
    return bd.isOpen();
}

bool AdminBD::comprobar_tabla(QString tabla)
{
    if (!this->is_conected()){
        bd.open();
    }
    QStringList tablas = bd.tables();
    return tablas.contains(tabla);
}

void AdminBD::cerrar()
{
    if (bd.isOpen()){
        bd.close();
    }
}













QString AdminBD::get_id_pais(QString pais)
{
    QString id = "0";
    id = consulta("SELECT id FROM paises WHERE pais = '"+pais+"'").at(0).at(0);
    return id;
}

QString AdminBD::get_id_region(QString region, QString id_pais)
{
    QString id = "0";
    if (region != "" && region != "Sin región/Total país"){
        id = consulta("SELECT id FROM regiones WHERE region = '"+region+"' AND id_pais = '"+id_pais+"'").at(0).at(0);
    }
    return id;
}

QVector<QStringList> AdminBD::obtener_datos(QString consulta)
{
    return this->consulta(consulta);
}

QVector<QStringList> AdminBD::acumular_datos(QVector<QStringList> orig)
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






QStringList AdminBD::getPaises()
{
    QStringList r;
    QVector<QStringList> paises_bd = consulta("SELECT pais FROM paises ORDER BY pais");

    for (int i=0;i<paises_bd.size();i++){
        r.append(paises_bd.at(i));
    }
    return r;
}

QStringList AdminBD::getRegiones(QString pais)
{
    QStringList r;
    QString idPais = this->get_id_pais(pais);
    QVector<QStringList> regiones_bd;
    if (idPais != "0"){
        regiones_bd = consulta("SELECT region FROM regiones WHERE id_pais = '"+idPais+"' ORDER BY region");
        for (int i=0; i< regiones_bd.size();i++){
            r.append(regiones_bd.at(i));
        }
    }
    return r;
}

