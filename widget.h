#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mydatabase.h"
#include "datashowwidget.h"
#include "QStackedWidget"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void switchDataShowWidget();

public  slots:
    void slotLogin();//登录

private:
    Ui::Widget *ui;
    MyDataBase *pMyDataBase;
    DataShowWidget *pDataShowWidget;

    QStackedWidget *pQStackedWidget; //多层显示界面
};
#endif // WIDGET_H
