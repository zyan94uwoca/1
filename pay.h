#ifndef PAY_H
#define PAY_H

#include <QDialog>
#include "QComboBox"
#include "QVBoxLayout"
#include "QDialog"
#include "string.h"
#include "QString"
#include "QDebug"
#include "QFile"
#include "findname.h"
#include "QMessageBox"
///
/// @author Zheng Yan
/// @brief this is the head file of pay.cpp
///
namespace Ui {
class pay;
}
/**
 * @brief The pay class
 */
class pay : public QDialog
{
    Q_OBJECT

public:
    explicit pay(QWidget *parent = nullptr);
    ~pay();
    bool judge(QString a);
private slots:
    /**
     * @brief on_comboBox_activated is when you choose something from the list of paying method
     * @param arg1
     */
    void on_comboBox_activated(const QString &arg1);


    /**
     * @brief this is the submit button
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui
     */
    Ui::pay *ui;

};

#endif // PAY_H
