#include "wishlistupdate.h"
#include "ui_wishlistupdate.h"

/**!
 * @author Shihao Hu
 * @brief the wishlistupdate class is designed for displaying the wishlistupdate window and allow users update the product quantity
 * @param parent create a parent as an instance var of qt widget, using for create the qt dialog box
 *
 * */
wishlistUpdate::wishlistUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wishlistUpdate)
{
    ui->setupUi(this);
}
// @brief a deconstructor for the wishlistUpdate class
wishlistUpdate::~wishlistUpdate()
{
    delete ui;
}
// @brief clicking effect refer to confirm button in wishlistUpdate.ui, update the quantity in database(wishlist.txt)
void wishlistUpdate::on_updateConfirm_clicked()
{      QString origin ;//temp var for saving quantity
       QString saveLine;//temp var for saving line

       QVector<QString> vector(200);
       QStringList e; //store the wishlist product information
       QString s; //store each new line updated waiting to be writtern in wishlist.txt
       QStringList l; //get the product quantity from product.txt to check

          qDebug()<<"YOU JUST CONFIRMED"<<endl;
         QString id =  ui->productUpdate->text();
         QString quantity = ui->quantityUpdate->text();

            //set the flag to identify if we are able to update the product quantity;
           int flag = 0;
           QFile product("product.txt");
          if(product.open(QIODevice::ReadOnly)){
              QTextStream get(&product);
              while(!get.atEnd()){
                  QString each = get.readLine();
                  each=each.trimmed();
                  l = each.split("&");
                  if(l[0]==id){
                      qDebug()<<l[3];
                      qDebug()<<quantity;
                      if(l[3]<quantity){
                           QMessageBox::information(this, "Can not add", "No enough goods");
                           flag=1; // not update the product quantity
                      }else{
                          flag = 0;
                          break;
                      }

                  }else{
                       flag=1;

                  }
              }


          }
          //if the flag equals to 0, update the quantity
          if(flag == 0){
              QFile inputFile("wishlist.txt");
              if (inputFile.open(QIODevice::ReadWrite))
              {
                 QTextStream in(&inputFile);
                 while (!in.atEnd())
                 {
                    QString line = in.readLine();
                    saveLine =line;
                    line =line.trimmed();
                    e  = line.split("&");
                    qDebug()<<"ready to find the product quantity"<<e[3]<<endl;
                    if(e[0]==id){
                        qDebug()<<"find it";
                        origin = e[3];
                        e[3]=quantity;
                        // if the quantity you entered is 0, then delete the product
                        if(e[3]=='0'){
                            s.append("");

                        }else{
                            s.append(e[0]);
                            s.append("&");
                            s.append(e[1]);
                            s.append("&");
                            s.append(e[2]);
                            s.append("&");
                            s.append(e[3]);
                            s.append("\n");

                        }

                    }else{
                         s.append(saveLine + "\n");
                    }

                  }
                 inputFile.resize(0);
                  qDebug()<<s;
                 in<<s;
              }
              inputFile.close();


          }

}











