#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  "signup.h"
/// @author Shihao Hu,Zheng Yan
/// \brief MainWindow::MainWindow
/// \param parent
/// @brief this is the first window to see and it has the method to login
///

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Welcome");


}
/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;

}
/**
 * @brief login clicked method will read the input of the message in two lineedit and judge if the username and passoword is right or not
 */
void MainWindow::on_pushButton_Login_clicked()
{   /**
     * get the input username and password
     */
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    //global variable name555 get the username to use in other window
     name555 = username;



      // username and passowrd shoul not be empty
      if(username=="" or password==""){
        QMessageBox::warning(this, "Login", " username or password should not be empty");
            return;
      }

    if(username != "" && password !="" ){
        //read the information.txt file
        QFile file("information.txt");
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
             QMessageBox::warning(this, "problem", " Problem in reading inforamtion.txt-1");
        }
        while(!file.atEnd())
        {   //read onr file and transfer to string and split by " "
            QByteArray line = file.readLine();
            QString str(line);
            str =str.trimmed();
            QStringList e  = str.split(" ");
            //if the username is equal to the first part in the file, and passoword is same as the second part in file
            if(e[0]==username){
                if(e[1]==password){
                 //login correctly
                QMessageBox::information(this, "Login", "Username and password is correct");
                //hide this window
                this->hide();

                //if the third part is 0 means this account is a staff,go to staff window
                if(e[2]=="0"){
                     Staff = new class staff;
                    Staff->show();
                    return;

                }
                // else go to customer page
                else{
                    Customer = new customer;

                    Customer->show();
                    this->hide();
                    return;


                }

            }

                }
            }


        }

    //wrong passoword or username
    QMessageBox::warning(this, "Login", "Please check your username or password");



    }





/**
 * @brief MainWindow::on_pushButton_signup_clicked is to the signup pages
 */
void MainWindow::on_pushButton_signup_clicked()
{
    Sign = new signup(this);
    Sign->show();

}
void customer::on_pushButton_3_clicked(){

}


