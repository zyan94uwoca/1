#include "staff.h"
#include "ui_staff.h"
///  @brief staff will show the interface for the staff
/// \brief staff::staff
/// \param parent
/// @author Zheng Yan
staff::staff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staff)
{   //
    ui->setupUi(this);
    // set the time
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(time_update()));
    timer->start(1000);
    this->setWindowTitle("Product-staff");
    // create the tablewidget
    tableWidget = new QTableWidget(100,4);
    //set the header
    QStringList header;
    header<<"ProductID"<<"Product Name"<<"Price"<<"Quantity";
    tableWidget->setHorizontalHeaderLabels(header);
    //can choose te row
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //set the location and size
    tableWidget->setGeometry(0,200,821,300);
    tableWidget->setWindowTitle("Product in stock");
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);





    // open the product.txt file
    QFile file("product.txt");

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
         QMessageBox::information(this, "problem", "can not read the file product.txt in staff.cpp-1");
    }
    //read each line and separate them with & to get information to add in
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
        row++;

        }

        tableWidget->setParent(this);
        tableWidget->show();



}
/**
 * @brief staff::~staff
 */
staff::~staff()
{
    delete ui;
}
/**
 * @brief staff::on_pushButton_clicked create the add interface to staff
 */
void staff::on_pushButton_clicked(){
        AddProduct  *change = new AddProduct;
        change->show();

}
/**
 * @brief staff::on_pushButton_2_clicked create the delproduct to staff
 */
void staff::on_pushButton_2_clicked()
{
        delprod * de = new delprod;
        de->show();
}
/**
 * @brief staff::on_pushButton_6_clicked refresh the table
 */
void staff::on_pushButton_6_clicked()

{
    //clean the tablewidget
    tableWidget->clearContents();
    // same as before
     row=0; col=0;
    QFile file("product.txt");

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
        row++;

        }

        tableWidget->setParent(this);
        tableWidget->show();



}









/**
 * @brief staff::on_pushButton_3_clicked create the other interface
 */
void staff::on_pushButton_3_clicked()
{
    other * ot = new other;
    ot->show();
}
/**
 * @brief staff::on_pushButton_4_clicked create add or delete interface
 */
void staff::on_pushButton_4_clicked()
{
    addordel * ade = new addordel;
    ade->show();
}
/**
 * @brief staff::time_update set the current time of this computer
 */
void staff::time_update()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label->setText(str);
}
