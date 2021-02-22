#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QImage>
#include "Widget.h"
#include "interfaz.h"


class Ventana : public QWidget  {
    Q_OBJECT

public:
    explicit Ventana( QWidget * parent = nullptr );
    ~Ventana();

protected:
    void paintEvent( QPaintEvent * event );

private:
    QGridLayout * layout;
    QPushButton * pb;
    QPushButton * pb2;
    QImage im;    
    Widget widget;
    Interfaz interfaz;

private slots:
void slotEmpezar();
void slotEmpezar2();

signals:

};

#endif // VENTANA_H
