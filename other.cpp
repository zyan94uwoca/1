
#include "other.h"
#include "ui_other.h"
/// @author ZhengYan,Shichao Wang
/// \brief other::other
/// \param parent
///
other::other(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::other)
{
    ui->setupUi(this);
}
/**
 * @brief other::~other
 */
other::~other()
{
    delete ui;
}
//

/**
 * @brief other::on_pushButton_clicked checked the four input, it's like a directly change
 */
void other::on_pushButton_clicked()
{   //get the four message
    QString id = ui->textEdit->toPlainText();
    QString productname = ui->textEdit_2->toPlainText();
    QString price = ui->textEdit_3->toPlainText();
    QString quantity= ui->textEdit_4->toPlainText();
    //if all of the data is empty, change nothig
    if(productname==""&&price==""&&quantity==""){
        QMessageBox::information(this, "change", "Change nothing");
        return;
    }
    // if the new product name's length is greater than 50
     if(productname.length()>50){
          QMessageBox::information(this, "change", "Name length exteed 50");
          return;
     }
     bool flag =false;
     double p = 0;
     int q = 0;
     //tets if the price can be transfered to double
     p = price.toDouble(&flag);
     if(flag==false&&price!=""){
         QMessageBox::information(this, "change", "price should be double");
         return;
     }
     //test if the price is less than 0
    if(p<0){
        QMessageBox::information(this, "change", "price can not less than 0");
        return;
    }
    q = quantity.toInt(&flag);
    // test if the quantity is less than 0
    if(q<0){
        QMessageBox::information(this, "change", "quantity can not less than 0");
        return;
    }
    // test if the quantity can be transfered int
    if(flag==false&&quantity!=""){
        QMessageBox::information(this, "change", "Quantity should be int");
        return;
    }
     flag = false;

    int judge = 0;

    // read product.txt and product1.txt
     QFile file("product.txt");
     QFile file1("product1.txt");
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
          QMessageBox::information(this, "problem", "Problem in reading product.txt in other.cpp-1");
     }
     if(!file1.open(QIODevice::WriteOnly | QIODevice::Text))
     {
         QMessageBox::information(this, "problem", "Problem in writing product1.txt in other.cpp-2");
     }
     while(!file.atEnd())
     {
         QByteArray line = file.readLine();
         QString str(line);
         str =str.trimmed();
         QStringList e  = str.split("&");
          QTextStream out(&file1);
          //if e is equal to id
         if(e[0]==id){
                judge = 1;
              // if any of the things is empty, means we do not need to change that part
             if(productname==""){
                 productname=e[1];
             }
             if(price==""){
                 price = e[2];
             }
             if(quantity==""){
                 quantity= e[3];
             }
             out<<e[0]<<"&"<<productname<<"&"<<price<<"&"<<quantity<<"\n";


         }
         // for other product, just add to the txt file
         else{
              out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<e[3]<<"\n";
         }
     }
     // remove the product.txt and change the product1.txt name to product.txt
     file.remove();
     file1.rename("product.txt");
     //if judge = 0 means we do not find the id
     if(judge == 0){
         QMessageBox::information(this, "change other", "Do not find the product iD");
         return;
     }
      QMessageBox::information(this, "change other", "change Success");
      this->hide();
}
