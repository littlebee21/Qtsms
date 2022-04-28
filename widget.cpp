#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

//登录界面的widget
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->loginPushButton,&QAbstractButton::clicked,
               this,&Widget::slotLogin);
}

Widget::~Widget()
{
    delete ui;
}

//进行登录和密码判定
//将登录结果发送到label
void Widget::slotLogin()
{
    if(ui->userNameLineEdit->text().isEmpty()){
        qDebug() << "用户名为空" ;
        ui->loginResultLabel->setText("用户名为空");
        return;
    }
    if(ui->userNameLineEdit->text() != "gao"){
        qDebug() << "用户名不对" ;
        ui->loginResultLabel->setText("用户名不对");
        return;
    }
    if(ui->passwordLineEdit->text() != "123"){
        qDebug() << "密码不对" ;
        ui->loginResultLabel->setText("密码不对");
    }
    //todo
}

