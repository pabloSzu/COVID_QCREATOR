#include "ventana.h"
#include <QDebug>
#include <QPainter>
#include <QImage>



Ventana::Ventana( QWidget * parent ) : QWidget( parent ),
                                       layout( new QGridLayout ),
                                       pb( new QPushButton( "SIMULACIÓN PYTHON" ) ),
                                       pb2( new QPushButton( "SIMULACIÓN DATOS REALES" ) )


{
  layout->addWidget( pb, 1, 0, 1, 2 );
  layout->addWidget( pb2, 2, 0, 1, 2 );
  this->setLayout( layout );
  im.load( ":/imagenes/imagen.png" );
  pb->setStyleSheet("* { background-color: rgb(202,255,138);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");
  pb2->setStyleSheet("* { background-color: rgb(177, 234, 227);border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 15px,15px;}");

  connect(pb, SIGNAL(pressed()), this, SLOT(slotEmpezar()));
  connect(pb2, SIGNAL(pressed()), this, SLOT(slotEmpezar2()));


  QIcon icono;
  icono.addFile(":/imagenes/icono1.ico");
  this->setWindowIcon(icono);

}

Ventana::~Ventana()  {}

void Ventana::paintEvent( QPaintEvent * )
{
    QPainter lapiz( this );
    QImage imEscalado = im.scaled( this->width() , this->height()  );
    lapiz.drawImage( 0, 0, imEscalado );
}

void Ventana::slotEmpezar()
{
        this->hide();
        widget.show();
        widget.setWindowTitle("Simulación de COVID-19");
        //widget.setGeometry(450,350,450,450)

}
void Ventana::slotEmpezar2()
{
        this->hide();
        interfaz.show();
        interfaz.setWindowTitle("Simulación de COVID-19");
        //widget.setGeometry(450,350,450,450)

}
