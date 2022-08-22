#ifndef WISHLISTUPDATE_H
#define WISHLISTUPDATE_H

#include <QDialog>
#include "QFile"
#include <QTextStream>
#include "QDebug"
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
///
///@author Shihao Hu
///@brief this is the head file of wishlistupdate.cpp
namespace Ui {
class wishlistUpdate;
}

class wishlistUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit wishlistUpdate(QWidget *parent = nullptr);
    ~wishlistUpdate();

private slots:
    void on_updateConfirm_clicked();



private:
    Ui::wishlistUpdate *ui;
};

#endif // WISHLISTUPDATE_H
