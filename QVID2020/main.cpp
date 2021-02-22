
#include <QApplication>
#include "interfaz.h"
#include "ventana.h"

//    ConfirmedCases_raw = pd.read_csv('https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_confirmed_global.csv')
//    Deaths_raw = pd.read_csv('https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_deaths_global.csv')
//    Recoveries_raw = pd.read_csv('https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv')


int main ( int argc, char ** argv ){
//    QApplication app( argc, argv );
//    Interfaz i;

//    i.show();


    QApplication a( argc, argv );
   a.setStyle("fusion");
       Ventana ventana;
       ventana.show();
       ventana.resize( 1000, 700 );
       ventana.setWindowTitle("UBP   -   COVID-19") ;
       ventana.setGeometry(300,200,1000,700) ;

    return a.exec();
}
