

#ifndef signin_H
#define signin_H

#include <QDialog>
#include <string>
#include <QMessageBox>
#include <stdlib.h>
#include <QtDebug>
#include<QFile>
/// @author Shihao Hu Zheng Yan
/// @brief this is the head file of signin.cpp


namespace Ui {
class signup;
}
/**
 * @brief The signup class
 */
class signup : public QDialog
{
    Q_OBJECT


public:
    /**
     * @brief signup
     * @param parent
     */
    explicit signup(QWidget *parent = nullptr);
    ~signup();


private slots:
    /**
     * @brief on_pushButton_register_clicked
     */
    void on_pushButton_register_clicked();

private:
    /**
     * @brief ui
     */
    Ui::signup *ui;




};

#endif // signin_H
