#ifndef STAFF_H
#define STAFF_H
#include <QDialog>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <AddProduct.h>
#include <delprod.h>
#include <QTableWidget>
#include <other.h>
#include <addordel.h>
#include <QTimer>
#include <QDateTime>
#include "QTableWidget"
#include "QStandardItemModel"
#include "QHeaderView"
#include "QFile"
#include "QDebug"
#include "QWidget"
///
/// @author Zheng Yan
/// @brief this is the head file of staff.cpp
///
namespace Ui {
class staff;
}

class staff : public QDialog
{
    Q_OBJECT

public:
    explicit staff(QWidget *parent = nullptr);
    ~staff();
    QTableView *tbView1;
    void init_tableView(void);
private slots:
    /**
     * @brief on_pushButton_clicked is to add product
     */
    void on_pushButton_clicked();
    /**
     * @brief on_pushButton_2_clicked is to delete product
     */
    void on_pushButton_2_clicked();
    /**
     * @brief on_pushButton_6_clicked is to refresh the interface
     */
    void on_pushButton_6_clicked();
    /**
     * @brief on_pushButton_3_clicked is to directly change productname, price , quantity with the id
     */
    void on_pushButton_3_clicked();
    /**
     * @brief on_pushButton_4_clicked is to add or delete a product
     */
    void on_pushButton_4_clicked();
public slots:
    /**
     * @brief time_update is to set the current time
     */
    void time_update(void);
private:
    /**
     * @brief tableWidget
     */
    QTableWidget *tableWidget;
    /**
     * @brief ui
     */
    Ui::staff *ui;
    /**
     * @brief change
     */
    AddProduct *change;
    /**
     * @brief ot
     */
    other *ot;
    /**
     * @brief de
     */
    delprod *de;
    /**
     * @brief ade
     */
    addordel * ade;
    /**
     * @brief row
     */
    qint16 row = 0;
    /**
     * @brief col
     */
    qint16 col = 0;
};

#endif // STAFF_H
