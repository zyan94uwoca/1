QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddProduct.cpp \
    addordel.cpp \
    customer.cpp \
    delprod.cpp \
    findname.cpp \
    main.cpp \
    mainwindow.cpp \
    other.cpp \
    pay.cpp \
    signup.cpp \
    staff.cpp \
    wishlist.cpp \
    wishlistupdate.cpp \


HEADERS += \
    AddProduct.h \
    addordel.h \
    customer.h \
    delprod.h \
    findname.h \
    mainwindow.h \
    other.h \
    pay.h \
    signup.h \
    staff.h \
    wishlist.h \
    wishlistupdate.h \


FORMS += \
    AddProduct.ui \
    addordel.ui \
    customer.ui \
    delprod.ui \
    mainwindow.ui \
    other.ui \
    pay.ui \
    signup.ui \
    staff.ui \
    wishlist.ui \
    wishlistupdate.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
CONFIG +=C++11

RESOURCES += \
    image.qrc
