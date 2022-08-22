#include "mainwindow.h"
#include "QFile"
#include <QApplication>
#include<QTextStream>
#include<QDebug>
/// @author
/// @brief the start of the program
/// \brief qMain
/// \param argc
/// \param argv
/// \return
///
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
