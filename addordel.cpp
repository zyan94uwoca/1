#include "addordel.h"
#include "ui_addordel.h"
///
/// @brief addordel::addordel
/// @param parent
/// @author Xiangli Zhang, Zheng Yan
///

/**
*  @brief addordel::addordel
*  @param parent
*/
addordel::addordel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addordel)

{
    ui->setupUi(this);
}
/**
 * @brief addordel::~addordel
 */
addordel::~addordel()
{
    delete ui;
}
/**
 * @brief this is to check if the add or delete is vaild
 */
void addordel::on_pushButton_clicked()
{
    //read the three input
    QString id = ui->textEdit->toPlainText();
    QString price = ui->textEdit_2->toPlainText();
    QString quantity = ui->textEdit_3->toPlainText();
    bool flag =false;
    double p = 0;
    int q = 0;
    int judge=0;
    //test if price can be transfer to double
    p = price.toDouble(&flag);
    if(flag==false&&price!=""){
        QMessageBox::information(this, "Add", "price should be double");
        return;
    }
    //test if price can be transfered to int
    flag = false;
    q = quantity.toInt(&flag);
    if(flag==false&&quantity!=""){
        QMessageBox::information(this, "Add", "quantity should be int");
        return;
    }
    // read and create product.txt and product1.txt
    QFile file("product.txt");
    QFile file1("product1.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Problem", "can not read in addordel for product.txt-1");
    }
    if(!file1.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Problem", "can not write in addordel for product1.txt-1");
    }
    //same to split the line in product
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        str =str.trimmed();
        QStringList e  = str.split("&");
         QTextStream out(&file1);
         //if the same id
        if(e[0]==id){
            //means at least we find the id
                judge = 1;
             // if the price do not need change
            if(price==""){
                price = e[2];
            }
            //if the quantity do not need to change
            if(quantity==""){
                quantity= e[3];
            }
            // if p is  0 do not need to change
            if(p==0.0){
                p = e[2].toDouble();
            }
            //if p >0 ,add p to the original p
            if(p>0){
                p = e[2].toDouble()+p;
            }
            //if p < 0; test if it will below than 0
            if(p<0){
                if(p+e[2].toDouble()<0){
                    QMessageBox::information(this, "Problem", "price will reduce below 0");
                    return;
                }
                else{
                    p = e[2].toDouble()+p;

                }
            }
            // same operation to q
            if(q>0){
                q = e[3].toInt()+q;
            }
            if(q==0){
                q = e[3].toInt();
            }
            if(q<0){
                if(q+e[3].toInt()<0){
                    QMessageBox::information(this, "Problem", "product will reduce below 0");
                    return;
                }
                else{
                    q = e[3].toInt()+q;
                }
            }
            //write this to the product1.txt
            out<<e[0]<<"&"<<e[1]<<"&"<<p<<"&"<<q<<"\n";


        }
        //else keep the same
        else{
             out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<e[3]<<"\n";
        }
    }
    //remove product.txt and change the product1.txt to product.txt
    file.remove();
    file1.rename("product.txt");
    //if judge is 0 means the entered id is wrong, return
    if(judge==0){
        QMessageBox::information(this, "Failed", "NO such product");
        return;
    }
     QMessageBox::information(this, "Success", "change Success");
     this->hide();
}
