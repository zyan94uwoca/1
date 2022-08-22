#ifndef AddProduct_H
#define AddProduct_H
/// @author  Xiangli Zhang,  Zheng Yan
/// @brief this is the head file of AddProduct.cpp
#include <QDialog>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QMessageBox>
#include <QPixmap>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QString>
#include <QDebug>

namespace Ui {
class AddProduct;
}
/**
 * @brief The AddProduct class
 */
class AddProduct : public QDialog
{
    Q_OBJECT

public:

    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

private slots:
    /**
     * @brief on_pushButton_clicked, a clicked to add the new product in or may not
     */
    void on_pushButton_clicked();



private:
    /**
     * @brief ui
     */
    Ui::AddProduct *ui;

};

#endif // AddProduct_H
