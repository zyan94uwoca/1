#include "signup.h"
#include "ui_signup.h"

using namespace std;
///  @author Zheng Yan
/// @brief signup is take three or four input first is username, second and third is passoword and forth is a password to be the staff account
/// \param parent
///
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

}
/**
 * @brief signup::~signup
 */
signup::~signup()
{
    delete ui;

}

/**
 * @brief signup::on_pushButton_register_clicked
 */
void signup::on_pushButton_register_clicked()

{
   // get the username and two password
    int judge=1;
    QString username = ui->signup_username->text();
    QString password = ui->signup_password->text();
    QString repassword = ui->signup_typeagain->text();
    QString codes =ui->signup_typeagain_2->text();
    //no blank in username
    for (int i = 0;i<username.length();i++){
        if(username[i]==' '){
            QMessageBox::information(this, "failed to signin", "Username should not have space");
            return;
        }
    }
    // no blank in password
    for (int i = 0;i<password.length();i++){
        if(password[i]==' '){
            QMessageBox::information(this, "failed to signin", "Password should not have space");
            return;
        }
        // password is made with a-z A-Z and 0-9
        if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9')==false){
            QMessageBox::information(this, "failed to login", "Password should only make up with 0-9.a-z,A-Z");
            return;

        }
    }
    // password and username should not be empty
    if(username=="" || password==""){
        QMessageBox::information(this, "failed to signin", "Username and password can not be empty");
        return;
    }
    // length of username should not less than 5 and not longer than 15
    if(username.length()>15||username.length()<5){
        QMessageBox::information(this, "failed to signin", "Length of username should be less than 15 and greater than 6");
        return;
    }
    //password should not less than  6 and longer than 9
    if(password.length()>9||password.length()<6){
        QMessageBox::information(this, "failed to signin", "Length of password should be less than 10 and greater or equal to 6");
        return;
    }
    //open information .txt
    QFile file("information.txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
         QMessageBox::information(this, "login problem", "can not read information.txt");
    }
    //read everyline in file
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        str =str.trimmed();
        QStringList e  = str.split(" ");
        // if username is same, an another usernmae should be used
        if(e[0]==username){
              QMessageBox::information(this, "failed to signin", "The username had already be used, try another one.");
              return;
        }
}   // if the extra message is equal to 3307, then this new account is staff account
    if(codes=="4471"){
        judge = 0;
    }
    // if passoword is same
    if(password == repassword){
        //open information to write the information to the file
        QFile file("information.txt");
            if(!file.open(QIODevice::Append|QIODevice::ReadWrite)){
                 QMessageBox::information(this, "signup problem", " Can not read information.txt-2");
            }
          //with " " between each part
        QTextStream out(&file);
        out<<username;
        out<<" ";
        out<<password;
        out<<" ";
        out<<judge;
        out<<"\n";
        file.close();
    QMessageBox::information(this, "Sign up successfully", "Sign up sucessfully");

    }else{
        QMessageBox::warning(this, "Sign up Failed", "Two passwords should be same.");
    }


}


