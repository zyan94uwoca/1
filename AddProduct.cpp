#include "AddProduct.h"
#include "ui_AddProduct.h"
#include <QMessageBox>
#include <QPixmap>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QString>
#include <QDebug>
///
/// \brief AddProduct::AddProduct
/// \param parent
/// @author  Xiangli Zhang,Zheng Yan
/// @brief this is the file to add a new product into the system
AddProduct::AddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
{
    // set the instructor
    ui->setupUi(this);
    ui->ID->setPlaceholderText("ID should be six digits");
    ui->name->setPlaceholderText("Max length is 40");
    ui->price->setPlaceholderText("Double");
    ui->quantity->setPlaceholderText("Int");
}

AddProduct::~AddProduct()
{
    delete ui;
}
/**
 * @brief AddProduct::on_pushButton_clicked is to test if the information is vaild, if is, then add to the file
 */
void AddProduct::on_pushButton_clicked()
{
        //get the four information with string type
       QString id =  ui->ID->toPlainText();
       QString name =  ui->name->toPlainText();
       QString price =  ui->price->toPlainText();
       QString quantity =  ui->quantity->toPlainText();

       // read product.txt to find if there is a same id in product.txt
       QFile file("product.txt");
       if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           QMessageBox::information(this, "Problem", "Can not read product.txt in AddProduct");
       }
       while(!file.atEnd())
       {
           QByteArray line = file.readLine();
           QString str(line);
           str =str.trimmed();
           QStringList e  = str.split("&");
            //if the id is already in the txfile, stop;
           if(e[0]==id){
               QMessageBox::information(this, "Add", "A same Id had already be used");
               return;
           }
       }
       // if the length of the id is not equal to 6, return;
       if(id.length()!=6){
            QMessageBox::information(this, "Add", "ProductID should be six");
            return;
       }
       //if name is empty,return
       if(name==""){
            QMessageBox::information(this, "Add", "Name should not be empty");
            return;
       }
       //if name is longer than 50 ,return
        if(name.length()>50){
             QMessageBox::information(this, "Add", "Name length exteed 50");
             return;
        }
        bool flag =false;
        double p = -1;
        int q = -1;
        p = price.toDouble(&flag);
        //if the price is less than 0 ,return
        if(p<=0){
            QMessageBox::information(this, "Add", "price should greater than 0 ");
            return;
        }
        //if the price is not double, return
        if(flag==false){
            QMessageBox::information(this, "Add", "price should be double");
            return;
        }
        flag = false;
        q = quantity.toInt(&flag);
        //if quantity is less than 0 ,return
        if(q<0){
            QMessageBox::information(this, "Add", "quantity should greater than 0 ");
            return;
        }
        //if the quantity is not int type , return
        if(flag==false){
            QMessageBox::information(this, "Add", "quantity should be int");
            return;
        }
        //else add success/
        QMessageBox::information(this, "Add", "Add success!");
        this->hide();

        //open product.txt and write the product into it
        QFile file1("product.txt");
        if(!file1.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QMessageBox::information(this, "Problem", "Can not read write in product.txt -4");
        }
        QTextStream out(&file1);
        //write the information in with a & symbol
         out<<id<<"&"<<name<<"&"<<price<<"&"<<quantity<<"\n";


}

