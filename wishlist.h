#ifndef WISHLIST_H
#define WISHLIST_H

#include <QDialog>
#include <QTableWidget>
#include <pay.h>
#include "wishlistupdate.h"
#include "findname.h"
#include "QTimer"
#include "QTableWidget"
#include "QStandardItemModel"
#include "QHeaderView"
#include "QFile"
#include "QDebug"
#include "QPushButton"
#include <QMessageBox>
#include <QMainWindow>
#include <QSignalMapper>
#include <QTextStream>
///
///@author Shihao Hu, Sean Joseph Friedrich
/// @brief this is the head file of wishlist.cpp
namespace Ui {
class wishlist;
}

class wishlist : public QDialog
{
    Q_OBJECT

public:
    explicit wishlist(QWidget *parent = nullptr);
    ~wishlist();

private slots:


    void on_pushButton_5_clicked();
    
    void on_deleteButton_clicked();

    void on_refreshButton_clicked();

    void on_updateButton_clicked();

 //   void on_textBrowser_anchorClicked(const QUrl &arg1);

private:
    Ui::wishlist *ui;
    QTableWidget *tableWidget;
    pay *pays;
    wishlistUpdate *update;
};

#endif // WISHLIST_H
