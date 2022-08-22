#ifndef OTHER_H
#define OTHER_H

#include <QDialog>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QString>
#include <QDebug>
#include <QMessageBox>

///
///@author Zheng Yan  Shichao Wang
///@brief this is the head file of other.cpp
namespace Ui {
class other;
}

class other : public QDialog
{
    Q_OBJECT

public:
    explicit other(QWidget *parent = nullptr);
    ~other();

private slots:
    /**
     * @brief on_pushButton_clicked is to check the input
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui
     */
    Ui::other *ui;
};

#endif // OTHER_H
