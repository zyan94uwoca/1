#include "delprod.h"
#include "ui_delprod.h"

///
/// \brief delprod::delprod
/// \param parent
/// @author  Xiangli Zhang, Zheng Yan
/// @brief this is to delet a product by it's id
///

/**
 * @brief delprod::delprod
 * @param parent
 */
delprod::delprod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delprod)
{
    ui->setupUi(this);


}
/**
 * @brief delprod::~delprod
 */
delprod::~delprod()
{
    delete ui;
}
/**
 * @brief delprod::on_pushButton_clicked check the input id
 */
void delprod::on_pushButton_clicked()
{
           int judge = 0;
           QFile file("product.txt");
           QFile file1("product1.txt");
           //create and read product1 and product
           QString id = ui->textEdit->toPlainText();
           if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
           {
               QMessageBox::information(this, "Problem", "Problem in reading product.txt in delpord-1");
           }
           if(!file1.open(QIODevice::WriteOnly | QIODevice::Text))
           {
              QMessageBox::information(this, "Problem", "Problem in writing product1.txt in delpord-1");
           }
           //keep reading
           while(!file.atEnd())
           {
               QByteArray line = file.readLine();
               QString str(line);
               str =str.trimmed();
               QStringList e  = str.split("&");
               //if the id is different, then we just need to write it to product1.txt
               if(e[0]!=id){
                   QTextStream out(&file1);
                   out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<e[3]<<"\n";

               }
               //if id is find, just do not write it to the file
               if(e[0]==id){
                   judge = 1;
               }
           }
           // if judge is 0 means we do not find a same productid in the product
           if(judge==0){
                QMessageBox::information(this, "Add", "Product id do not find");
                return;
           }
           //remove product.txt and change product1.txt to product.txt
           file.remove();
           file1.rename("product.txt");
            QMessageBox::information(this, "Add", "Delete Success");
            //hide this window
            this->hide();
}
