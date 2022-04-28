#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mydatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public  slots:
    void slotLogin();//登录

private:
    Ui::Widget *ui;
    MyDataBase *pMyDataBase;
};
#endif // WIDGET_H
