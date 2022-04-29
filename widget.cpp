#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

//登录界面的widget
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pMyDataBase = MyDataBase::getInstance();
    pDataShowWidget = new DataShowWidget;
    if(pMyDataBase == nullptr){
        qDebug() << "pMyDataBase get fail in Widget class";
        delete pMyDataBase;
    }
    if(pDataShowWidget == nullptr){
        qDebug() << "pDatashowWidget new fail in Widget class";
    }



    //建立连接
    //connect(ui->initDataBasePushButton,SIGNAL(clicked()),
    //        pMyDataBase,SLOT(insertFakeData()));
    connect(ui->loginPushButton,&QAbstractButton::clicked,
               this,&Widget::slotLogin);
    connect(ui->initDataBasePushButton,&QAbstractButton::clicked,
                // this,&Widget::slotLogin);
                pMyDataBase,&MyDataBase::insertFakeData);
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
    if(ui->passwordLineEdit->text().isEmpty()){
        qDebug() << "密码为空" ;
        ui->loginResultLabel->setText("密码为空");
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
        return;
    }
    switchDataShowWidget();
}


//跳转显示数据的界面
void Widget::switchDataShowWidget()
{
    qDebug() << "switch to Datashow";
    this->hide();
    pDataShowWidget->show();
}

