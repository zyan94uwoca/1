

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <customer.h>
#include <signup.h>
#include <string>
#include <staff.h>
#include <QMainWindow>
#include <AddProduct.h>
#include <QMessageBox>
#include <QPixmap>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QTimer>
#include <QThread>
#include "findname.h"
/// @author Shihao Hu Zheng Yan
/// @brief this is the head file of mainwindow.cppbrief
///
///
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * @param parent
     *
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief login button clicked event
     *
     */
    void on_pushButton_Login_clicked();
    /**
     * @brief signup button clicked event
     */
    void on_pushButton_signup_clicked();

private:
    /**
     * @briefui is this winodw
     */
    Ui::MainWindow *ui;
    /**
     * @brief Customer is for customer window
     */
    customer * Customer;
    /**
     * @brief sign in is to create a new account
     */
    signup *Sign;
    /**
     * @brief Staff is for staff use method
     */
    staff *Staff;




};
#endif // MAINWINDOW_H
