#include "wishlist.h"
#include "ui_wishlist.h"


/**!
 * @author Shihao Hu, Sean Joseph Friedrich
 * @brief the wishlist class is designed for displaying the wishlist user interface and providing some operations for users
 * @param parent create a parent as an instance var of qt widget, using for create the qt dialog box
 *
 * */
wishlist::wishlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wishlist)
{

    ui->setupUi(this);
    QFile files("transfer.txt");
    if(!files.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the fileddd!"<<endl;

    }

    QByteArray line = files.readLine();
    QString str(line);
    str =str.trimmed();
    QString wel = "Welcome---"+str;
    ui->label_3->setText(wel);

    this->setWindowTitle("Product-staff");
    tableWidget = new QTableWidget(100,4);
    QStringList header;
    header<<"ProductID"<<"Product Name"<<"Price"<<"Quantity"<<"ADD";
    tableWidget->setHorizontalHeaderLabels(header);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->setGeometry(20,200,700,300);
    tableWidget->setWindowTitle("Product in stock");
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QFile file("wishlist.txt");
    int row = 0; int col = 0;
    double totalPrice = 0;
    QString displayString;
    if(!file.open(QIODevice::ReadOnly ))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        str =str.trimmed();
        QStringList e  = str.split("&");
        double price = e[2].toDouble();
        double quantity = e[3].toInt();
        double currentprice = price*quantity;
        totalPrice += currentprice;

        tableWidget->setItem(row,col,new QTableWidgetItem(e[0]));

        tableWidget->setItem(row,col+1,new QTableWidgetItem(e[1]));

        tableWidget->setItem(row,col+2,new QTableWidgetItem(e[2]));

        if(e[3]!='0'){

             tableWidget->setItem(row,col+3,new QTableWidgetItem(e[3]));

        }

        row++;
    }
    file.close();

    QString s = QString::number(totalPrice);
     price555=s;

    //display the totalprice
    ui->totalprice->setText(s);
    tableWidget->setParent(this);
    tableWidget->show();

}
// @brief a deconstructor for the wishlist class
wishlist::~wishlist()
{
    delete ui;
}

// @brief clicking effect refer to pay button in wishlist.ui, turn to payment page once clicked
void wishlist::on_pushButton_5_clicked()

{

        pay *pays = new pay;
        pays->show();
}

// @brief clicking effect refer to clearall button in wishlist.ui, clear all products in your wishlist
void wishlist::on_deleteButton_clicked()
{
    // clear the wishlist

    QFile file("wishlist.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QTextStream out(&file);
    out<< "";
    file.close();

}

//@ brief clicking effect refer to refresh button in wishlist.ui, refresh the page to show new updated data
void wishlist::on_refreshButton_clicked()
{   int row =0, col = 0;
    double totalPrice = 0;
    tableWidget->clearContents();
    QFile file("wishlist.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"can not open the file!"<<endl;
    }
    //refresh all the line in wishlist.txt and get the new total price for latest update
    while(!file.atEnd()){
        QByteArray line = file.readLine();
        QString str(line);
        str =str.trimmed();
        QStringList e = str.split("&");
        tableWidget->setItem(row,col,new QTableWidgetItem(e[0]));
        tableWidget->setItem(row,col+1,new QTableWidgetItem(e[1]));
        tableWidget->setItem(row,col+2,new QTableWidgetItem(e[2]));
        tableWidget->setItem(row,col+3,new QTableWidgetItem(e[3]));
        row++;
        double price = e[2].toDouble();
        double quantity = e[3].toInt();
        qDebug()<<price;
        qDebug()<<quantity;
        totalPrice += price*quantity;
        qDebug()<<totalPrice;
    }
    qDebug()<<totalPrice;
    QString s = QString::number(totalPrice);
    //display the total price
    ui->totalprice->setText(s);

}
// @brief clicking effect refer to update button in wishlist.ui, pop up a new window for update once clicked
void wishlist::on_updateButton_clicked()
{
    // pop up an update windown if you click update
    update = new wishlistUpdate(this);
    update->show();


}





