#include "logintipdialog.h"
#include "ui_logintipdialog.h"
#include <QDebug>

LoginTipDialog::LoginTipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginTipDialog)
{
    ui->setupUi(this);
}

LoginTipDialog::~LoginTipDialog()
{
    delete ui;
}

//login success and login fail
void LoginTipDialog::showLoginResult(int result)
{
    this->show();
    QString labelText;
    switch (result) {
        case 1:labelText = "用户名空"; break;
    case 2:labelText = "没密码"; break;
    case 3:labelText = "成功"; break;
    case 4:labelText = "用户名错"; break;
    case 5:labelText = "密码错"; break;
    default:labelText = "****";break;
    }
    ui->label->setText(labelText);
}
