#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include <QTimer>
#include "logintipdialog.h"
#include <QDebug>
namespace Ui {
class CenterWidget;
}

/*!
 *  @className   : CenterWidget
 *  @brief       : 登录窗口的中心部件
 *  @description : Description
 *  @author      : ciyeer
 *  @date        : 2022-04-26 16:10:52
 */
class CenterWidget : public QWidget{
    Q_OBJECT

public:
    explicit CenterWidget(QWidget *parent = nullptr);
    ~CenterWidget();
signals:
    void loginSignal(int);

public slots:
    void slotLogin();
    void slotHideWarningLabel();

private:
    Ui::CenterWidget *ui;

    QString m_strUserName;
    QString m_strPassword;
    // 提示标签显示时间定时器
    QTimer *m_pWarningTimer;
    int m_nInputErrTimes;
    LoginTipDialog *m_pLoginTipDialog;
};

#endif // CENTERWIDGET_H
