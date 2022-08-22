
#include "customer.h"
#include "ui_customer.h"
#include "signup.h"
/// @author  Zheng Yan,Xiangli Zhang
/// \brief customer::customer is the interface of the customer, customer can see the products table and add to the wishlist
/// \param parent
///
///
customer::customer(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::customer)
{

    ui->setupUi(this);
    // time is to set the current time
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(time_update()));
    timer->start(1000);

    // this is to get the current username and print to a text
    QString wel = "Welcome---"+name555;
    ui->bar->setText(wel);
    // this is to clear a wishlist
    QFile tran("transfer.txt");
    if(!tran.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QMessageBox::warning(this, "customer problem", " Problem in reading wishlist.txt-1");

    }
    QTextStream out2(&tran);
    out2<<"";

    QFile f("wishlist.txt");
    if(!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QMessageBox::warning(this, "customer problem", " Problem in reading wishlist.txt-2");

    }
    this->setWindowTitle("Stock market");
    //set the table to 100 rows and 5 columns
    tableWidget = new QTableWidget(100,5);
    QStringList header;
    //set the name of each colnums
    header<<"StockID"<<"Company Name"<<"Price"<<"Quantity"<<"ADD";
    tableWidget->setHorizontalHeaderLabels(header);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //set size and location
    tableWidget->setGeometry(20,200,800,600);
    //
    tableWidget->setWindowTitle("Products in stock");
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QFile file("product.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "customer problem", " Problem in reading product.txt-1");
    }
    //read to the end of the file
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        str =str.trimmed();
        QStringList e  = str.split("&");
        //set each row with five item , productid productname price product quantity and an add button to add this product into the list
        //add id to first col
        tableWidget->setItem(row,col,new QTableWidgetItem(e[0]));
        //add name to second col
        tableWidget->setItem(row,col+1,new QTableWidgetItem(e[1]));
        //add price to third col
        tableWidget->setItem(row,col+2,new QTableWidgetItem(e[2]));
        //add quantity to forth col
        tableWidget->setItem(row,col+3,new QTableWidgetItem(e[3]));
        //create the button and show it
        QPushButton *but = new QPushButton();
        but->setText("Add to list");
        but->setParent(this);
        but->show();

        tableWidget->setCellWidget(row,col+4,but);
        //add each button to connect with this function
        connect(but, &QPushButton::clicked, this, [=]()mutable {

                //open a new txt wishlist2
                QFile filee("wishlist2.txt");
                if(!filee.open(QIODevice::ReadWrite| QIODevice::Append))
                {
                    QMessageBox::warning(this, "customer problem", " Problem in reading writing wishlist2.txt-2");
                }
                QFile FILE("wishlist.txt");

                if(!FILE.open(QIODevice::ReadOnly))
                {
                     QMessageBox::warning(this, "customer problem", " Problem in reading writing wishlist.txt-3");

                }
                QTextStream out(&filee);
                //if there are nothig in wishlist.txt ,then add the item to the list
                if(FILE.atEnd()){
                    out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<1<<endl;
                    FILE.remove();
                    filee.rename("wishlist.txt");
                    return;
                }
                //judge is to find if the product is the product in wishlist, if it is, then change quantity in wishlist and can not exceed the product in product.txt
                int judges= 0;
                while(!FILE.atEnd()){

                    QByteArray line = FILE.readLine();
                    QString str(line);
                    str =str.trimmed();
                    QStringList r  = str.split("&");
                    //if this product is in wishlist add one to the quantity if not exceed the quantity
                    if(r[0]==e[0]){
                        judges = 1;
                        int m = r[3].toInt()+1;
                        if(m>e[3].toInt()){
                             QMessageBox::information(this, "Can not add", "No enough goods");
                             return;
                        }
                        out<<r[0]<<"&"<<r[1]<<"&"<<r[2]<<"&"<<m<<endl;
                    }

                    else{

                        out<<r[0]<<"&"<<r[1]<<"&"<<r[2]<<"&"<<r[3]<<endl;
                    }
                }
                // if not in the wishlist, add one to the wishlist
                if(judges==0){
                    out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<"1"<<endl;
                }
                //change wishlist2 to wishlist
                FILE.remove();
                filee.rename("wishlist.txt");
        }
        );
        row++;
        }

        tableWidget->setParent(this);
        tableWidget->show();


        file.close();
        f.close();
}
/**
 * @brief customer::~customer
 */
customer::~customer()
{
    QTimer::singleShot(2, this, SLOT(quit));
    delete ui;
}

/**
 * @brief customer::on_pushButton_clicked is to create the wishlist interface
 */
void customer::on_pushButton_clicked()
{
     wishlist * wishli = new wishlist();
     wishli->show();
}

/**
 * @brief customer::time_update show the current time in computer
 */
void customer::time_update()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label->setText(str);
}
/**
 * @brief customer::on_pushButton_2_clicked isto refresh the window same as before
 */
void customer::on_pushButton_2_clicked()
{   tableWidget->clearContents();
    int row = 0;int col = 0;
    QFile file("product.txt");
    QString displayString;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        str =str.trimmed();
        QStringList e  = str.split("&");
        tableWidget->setItem(row,col,new QTableWidgetItem(e[0]));

        tableWidget->setItem(row,col+1,new QTableWidgetItem(e[1]));

        tableWidget->setItem(row,col+2,new QTableWidgetItem(e[2]));

        tableWidget->setItem(row,col+3,new QTableWidgetItem(e[3]));
        QPushButton *but = new QPushButton();


        but->setText("Add to chart");
        but->setParent(this);
        but->show();

        tableWidget->setCellWidget(row,col+4,but);

        connect(but, &QPushButton::clicked, this, [=]()mutable {


                QFile filee("wishlist2.txt");
                if(!filee.open(QIODevice::ReadWrite| QIODevice::Append))
                {
                    qDebug()<<"Can't open the file!"<<endl;
                }
                QFile FILE("wishlist.txt");

                if(!FILE.open(QIODevice::ReadOnly))
                {
                    qDebug()<<"Can't open the file!"<<endl;

                }
                QTextStream out(&filee);

                if(FILE.atEnd()){
                    out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<1<<endl;
                    FILE.remove();
                    filee.rename("wishlist.txt");
                    return;
                }
                int judges= 0;
                while(!FILE.atEnd()){
                    QByteArray line = FILE.readLine();
                    QString str(line);
                    str =str.trimmed();
                    QStringList r  = str.split("&");

                    if(r[0]==e[0]){
                        if(r[3].toInt()+1>e[3].toInt()){

                            QMessageBox::information(this, "Can not add", "No enough goods");
                            return;
                        }
                        qDebug()<<r[3]<<e[3];
                        judges = 1;
                        int m = r[3].toInt()+1;

                        out<<r[0]<<"&"<<r[1]<<"&"<<r[2]<<"&"<<m<<endl;

                    }
                    else{

                        out<<r[0]<<"&"<<r[1]<<"&"<<r[2]<<"&"<<r[3]<<endl;
                    }
                }
                if(judges==0){
                    out<<e[0]<<"&"<<e[1]<<"&"<<e[2]<<"&"<<"1"<<endl;

                }
                FILE.remove();
                filee.rename("wishlist.txt");
        }
        );
        row++;
        }

}
