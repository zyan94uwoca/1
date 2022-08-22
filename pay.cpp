#include "pay.h"
#include "ui_pay.h"

/// @author Zheng Yan
/// \brief pay::pay
/// \param parent
/// @brief this class have the function to change the paying method, pay the bill and change the quantity of the product
///
pay::pay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pay)
{
    ui->setupUi(this);
    ui->comboBox_2->hide();
    ui->label_5->hide();
    ui->lineEdit_5->hide();
    ui->label_4->hide();
    ui->lineEdit_4->hide();
    QString to = "Hello, the total price is :"+price555;
    ui->label_6->setText(to);
}

pay::~pay()
{
    delete ui;
}

///
/// \brief pay::on_comboBox_activated
/// \param arg1
/// @return nothing
void pay::on_comboBox_activated(const QString &arg1)

{
         // With different choice of the paying method, this widge will show different platform

       ui->label_4->hide();
       ui->lineEdit_4->hide();
       ui->comboBox_2->hide();
       ui->label_5->hide();
       ui->lineEdit_5->hide();

        // this is for debit card which have three text to show

    if(arg1=="Pay by debit card"){
        ui->lineEdit->show();
        ui->label->setText("Card Number:");
        ui->label_2->setText("Enter code:");
        ui->lineEdit_2->setPlaceholderText("");
        ui->label_3->setText("Enter Expire day:");
        ui->label_4->hide();
        ui->lineEdit_4->hide();



    }
        // this is for credit card which have three texts to show

    if(arg1=="Pay by credit card"){
        ui->lineEdit->show();
        ui->label->setText("Card Number:");
        ui->label_2->setText("Enter Expire day:");
        ui->lineEdit_2->setPlaceholderText("YY/MM");
        ui->label_3->setText("Enter security code:");
        ui->label_4->hide();
        ui->lineEdit_4->hide();
    }

            //if this delivery and pay, five things should provide and a list of provinces of Canada will show

    if(arg1=="Cash on delivery"){
        ui->lineEdit_2->setPlaceholderText("");
        ui->comboBox_2->show();
        ui->lineEdit->hide();
        ui->label->setText("Province");
        ui->label_2->setText("Enter the street:");
        ui->label_3->setText("Enter PostCode:");
        ui->label_4->setText("Enter the phone number:");
        ui->label_4->show();
        ui->lineEdit_4->show();
        ui->label_5->show();
        ui->lineEdit_5->show();



}
}
///
/// \brief pay::on_pushButton_clicked
/// @return Nothing
/// @brief This will have a sample test if you enter the information and do not leave the blank but will not
/// test if you provide the right informaition

void pay::on_pushButton_clicked()
{   /**
      if it is delivery, then five place should all have number
      */

    if(ui->label_5->isVisible()){
        if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""||ui->lineEdit_3->text()==""||ui->lineEdit_4->text()!=""||ui->lineEdit_5){
             QMessageBox::information(this, "Pay", "Please fill the blank!");
        }
        /**
          else only need three
          */
        if(!ui->label_5->isVisible()){
            if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""||ui->lineEdit_3->text()==""){
                 QMessageBox::information(this, "Pay", "Please fill the blank!");
            }
    }

        /**
     * @brief hold is to test if you have any things in your wishlist to pay.
     */
    int hold = 0;
     //wishlist and new txt product2 are created
    QFile file1("wishlist.txt");
    QFile file2("product2.txt");
    QFile samefile("product2.txt");
    //try to open and read the three files
    if(!samefile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
       QMessageBox::information(this, "Problem", "Problem in reading product2.txt in pay.cpp");
    }

    if(!file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "Problem", "Problem in reading wishlist.txt in pay.cpp");
    }

    if(!file2.open(QIODevice::ReadWrite | QIODevice::Append))
    {
       QMessageBox::information(this, "Problem", "Problem in reading product2.txt in pay.cpp-2");
    }
    //one is for writing in
    QTextStream out(&file2);
    //keep reading
    while(!file1.atEnd()){
        //if the program came into this part,means wishlist is not empty
        hold = 1;
        //read a line from the file
        QByteArray line = file1.readLine();
        //change to string type
        QString str(line);
        //delet the /n at the end of the line
        str =str.trimmed();
        //split it with &
        QStringList e  = str.split("&");
        //for every line in wishlist, it will go through the product to test
        QFile file("product.txt");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
             QMessageBox::information(this, "Problem", "Problem in reading product.txt in pay.cpp-2");
        }
        //read the product file
        while(!file.atEnd()){
            //do the things as before
            QByteArray line1 = file.readLine();
            QString str1(line1);
            str1 =str1.trimmed();
            QStringList e1  = str1.split("&");
            //if the product in wishlist have the same id with one in product
            if(e1[0]==e[0]){
                //claculate how many quantity they need
                int a = e[3].toInt();
                int b = e1[3].toInt();
                int final = b-a;
                // this means customers bought every products which means the product is out of Stock now
                if(final==0){
                     out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<"OUT OF STOCK"<<endl;
                }
                //else write the product to the product2.txt
                else{
                    out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<final<<endl;
                }
            }
        }
    }
    if(hold==0){
        QMessageBox::information(this, "Pay", "Empty wishlist");
        return;
    }
     //read from product txt file
    QFile file("product.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         QMessageBox::information(this, "Problem", "Problem in reading product.txt in pay.cpp-2");
    }
    //while not reach the end of the file
    while(!file.atEnd()){
        int judge = 0;
        QTextStream oue(&file2);
        QByteArray line2 = file.readLine();
        QString str2(line2);
        str2 =str2.trimmed();
        QStringList e2  = str2.split("&");
        qDebug()<<e2;
        //reopen the product2.txt
        QFile samefile("product2.txt");
        if(!samefile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
             QMessageBox::information(this, "Problem", "Problem in reading product2.txt in pay.cpp3");
        }
        //compare each line in product with every line in product2.txt now
        while(!samefile.atEnd()){
            QByteArray line3 = samefile.readLine();
            QString str3(line3);
            str3 =str3.trimmed();
            QStringList e3  = str3.split("&");
            //if is same just skip it, because it already in the product2.txt
            if(e2[0]==e3[0]){
                    judge = 1;
                    continue;
                }



            }
        //else add it to the prodcut2.txt
        if(judge==0){
            oue<<e2[0]<<"&"<<e2[1]<<"&"<<e2[2]<<"&"<<e2[3]<<endl;
        }
        }
    //remove wishlist.txt and product,txt, change produt2.txt to product.txt
    file.remove();
    file2.rename("producteee.txt");
    samefile.rename("product.txt");
    file1.remove();



     QMessageBox::information(this, "Pay", "Thanks for purchasing!");
    }



}
