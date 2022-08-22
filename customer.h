#ifndef customer_H
#define customer_H
/// @author  Xiangli Zhang,  Zheng Yan
/// @brief this is the head file of customer.cpp
#include <QDialog>
#include "wishlist.h"
#include <QTimer>
#include <QDateTime>
#include <QTableWidget>
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
#include "findname.h"
namespace Ui {
/**
 *
 */
class customer;

}
/**
 * @brief The customer class
 */
class customer : public QDialog
{
    Q_OBJECT
class mainwindow;
public:

    explicit customer(QWidget *parent = nullptr);
    ~customer();
/**
       * @brief OnButton
       */





private slots:
      /**
       * @brief on_pushButton_clicked is to go to wishlist interface
       */
      void on_pushButton_clicked();
      /**
       * @brief on_pushButton_2_clicked refresh the interface
       */
      void on_pushButton_2_clicked();

      void on_pushButton_3_clicked();
public slots:
      /**
     * @brief time_update is to show the  current time
     */
    void time_update(void);
private:
    /**
     * @brief ui
     */
    Ui::customer *ui;
    /**
     * @brief row and col is the position in the table of the product
     */
    int row = 0;
    int col = 0;
    /**
     * @brief wishli is the wishlist
     */
    wishlist * wishli;
    /**
     * @brief tableWidget is the table in customer
     */
    QTableWidget *tableWidget;

    mainwindow *mainWindow;


};

#endif // SECDIALOG_H
