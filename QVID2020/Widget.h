#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
namespace Ui
{
class Widget;
}

class QProcess;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:

    void on_ejecutarPushButton_clicked();
    void on_quitarPushButton_clicked();
    void slotSim1();
    void slotSim2();
    void slotSim3();
    void slotINFO();


    void slotINFOvar();
    void slotINFOvar1();
    void slotINFOvar2();

private:
    Ui::Widget *ui;
    QProcess *mProcess;
    int ro_aux=0;
    int info_aux=0;
};

#endif // WIDGET_H
