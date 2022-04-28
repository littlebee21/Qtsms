#include "centerwidget.h"
#include "ui_centerwidget.h"

CenterWidget::CenterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterWidget),
    m_nInputErrTimes(1),
    m_pLoginTipDialog(new LoginTipDialog)
{
    ui->setupUi(this);

    m_strUserName = "zhangsan";
    m_strPassword = "abc123";
    // 提示
    ui->usrnameLineEdit->setPlaceholderText("用户名");
    ui->passwdLineEdit->setPlaceholderText("密码");
    // 居中
    ui->usrnameLineEdit->setAlignment(Qt::AlignCenter);
    ui->passwdLineEdit->setAlignment(Qt::AlignCenter);
    // 密码只写
    ui->passwdLineEdit->setEchoMode(QLineEdit::Password);

    connect(ui->loginBtn, &QAbstractButton::clicked,
            this, &CenterWidget::slotLogin);

    //登录进行窗口提示
    connect(this,SIGNAL(loginSignal(int)),
            m_pLoginTipDialog,SLOT(showLoginResult(int)));

    m_pWarningTimer = new QTimer(this);
    // 关联定时器的槽函
    connect(m_pWarningTimer, &QTimer::timeout, this, &CenterWidget::slotHideWarningLabel);
}

// 如果输入三次以上，则退出应用程序
void CenterWidget::slotLogin(){
    if(m_nInputErrTimes > 2){
        this->close();
    }
    // 用户名为空
    if(ui->usrnameLineEdit->text().isEmpty()){
        // ui->warningLabel->setText("请输入用户名");
        emit loginSignal(1);
        qDebug() << "1";
        m_pWarningTimer->start(3000);      // 启动定时器,3s之后结束
        // m_pWarningTimer->start();             // 启动定时器
        // m_pWarningTimer->setInterval(3000);   // 设置计时器的长度
        return;
    }
    // 未输入密码
    if(ui->passwdLineEdit->text().isEmpty()){
        // ui->warningLabel->setText("请输入密码");
        emit loginSignal(2);
        qDebug() << "1";
        m_pWarningTimer->start(3000);      // 启动定时器,3s之后结束
        return;
    }
    if(ui->usrnameLineEdit->text() == m_strUserName){
        if(ui->passwdLineEdit->text() == m_strPassword){
            // ui->warningLabel->setText("登录成功");
            emit loginSignal(3);
            qDebug() << "1";
            m_pWarningTimer->start(3000);      // 启动定时器,3s之后结束
        }
        else{
            // 密码输入错误
            emit loginSignal(4);
            qDebug() << "1";
            // ui->warningLabel->setText(QString("密码错误,登录失败,还剩%1次机会").arg(3-m_nInputErrTimes));
            m_nInputErrTimes++;
            m_pWarningTimer->start(3000);      // 启动定时器,3s之后结束
            ui->passwdLineEdit->clear();
        }
    }
    else{
        // 用户名输入错误
        // ui->warningLabel->setText(QString("用户名输入错误,登录失败,还剩%1次机会").arg(3-m_nInputErrTimes));
        emit loginSignal(5);
        qDebug() << "1";
        m_nInputErrTimes++;
        m_pWarningTimer->start(3000);      // 启动定时器,3s之后结束
        ui->usrnameLineEdit->clear();
        ui->passwdLineEdit->clear();
    }
}

void CenterWidget::slotHideWarningLabel(){
    // ui->warningLabel->clear();   // 暂时不能用
}

CenterWidget::~CenterWidget(){
    delete ui;
    delete m_pWarningTimer;
    m_pWarningTimer = nullptr;
}
