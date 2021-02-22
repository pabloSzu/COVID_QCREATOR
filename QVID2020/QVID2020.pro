QT += sql network widgets

HEADERS += \
    adminbd.h \
    Widget.h \
    ventana.h \
    grafico.h \
    interfaz.h

SOURCES += \
 ventana.cpp\
 Widget.cpp\
    adminbd.cpp \
    grafico.cpp \
    interfaz.cpp \
    main.cpp

FORMS += \
    Widget.ui\
    interfaz.ui

CONFIG += static

RESOURCES += \
    recursos.qrc
