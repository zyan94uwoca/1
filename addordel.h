#ifndef ADDORDEL_H
#define ADDORDEL_H
/// @author  Xiangli Zhang,  Zheng Yan
/// @brief this is the head file of addordel.cpp
#include <QDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QString>
#include <QDebug>
namespace Ui {
class addordel;
}
/**
 * @brief The addordel class
 */
class addordel : public QDialog
{
    Q_OBJECT

public:
    explicit addordel(QWidget *parent = nullptr);
    ~addordel();

private slots:
    /**
     * @brief on_pushButton_clicked is to test if the add or delete in quantity and price is valid
     */
    void on_pushButton_clicked();

private:
    Ui::addordel *ui;
};

#endif // ADDORDEL_H
