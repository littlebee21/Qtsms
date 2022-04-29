#ifndef DATASHOWWIDGET_H
#define DATASHOWWIDGET_H

#include <QWidget>
#include <QString>
#include <QItemSelectionModel>
#include "mydatabase.h"

namespace Ui {
class DataShowWidget;
}


//第二个主要布局
class DataShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataShowWidget(QWidget *parent = nullptr);
    ~DataShowWidget();

    //view
    void switchTableWidget(QString tableName); //切换表显示不刷新
    void refreshShow(); //刷新表格显示
    void showAllTable(); //显示所有表内容
    //controller sig and slots

    //service get data from database
    QList<QList<QString>> getTeacherModel();   //获取老师数据
    QList<QList<QString>> getStudentModel();   //获取学生数据

    void testfunction(); //测试
public slots:
    void comboxActiveSlots();
private:
    Ui::DataShowWidget *ui;
    MyDataBase *pmyDataBase;
};

#endif // DATASHOWWIDGET_H
