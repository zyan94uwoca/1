#ifndef DELPROD_H
#define DELPROD_H
/// @author  Xiangli Zhang,  Zheng Yan
/// @brief this is the head file of delprod.cpp
#include <QDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QString>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class delprod;
}
/**
 * @brief The delprod class
 */
class delprod : public QDialog
{
    Q_OBJECT

public:
    explicit delprod(QWidget *parent = nullptr);
    ~delprod();

private slots:
    /**
     * @brief check if we can delete a product by it's id
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui
     */
    Ui::delprod *ui;
};

#endif // DELPROD_H
