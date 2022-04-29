#ifndef DATASHOWWIDGET_H
#define DATASHOWWIDGET_H

#include <QWidget>
#include <QString>
#include <QItemSelectionModel>
#include "mydatabase.h"

namespace Ui {
class DataShowWidget;
}


//数据操作界面
class DataShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataShowWidget(QWidget *parent = nullptr);
    ~DataShowWidget();

    //view
    void switchTableWidget(QString tableName); //切换表显示不刷新todo
    void refreshShow(); //刷新表格显示todo
    void showAllTable(QStandardItemModel *pmodel,int length); //显示所有表内容
    QStandardItemModel *buildModelHead(QStandardItemModel *pmodel,QString tableName);
    QStandardItemModel *buildModel(QStandardItemModel *pmodel,QList<QList<QString>> returnData); //构建数据模型

    //controller sig and slots

    //service
    //database
    QList<QList<QString>> getClassModel();   //获取class数据
    QList<QList<QString>> getStudentModel();   //获取学生数据
    int deletateStudentModel();  //删除学生数据
    int updateStudendModel();  //更新学生数据
    int insertStudentModel();    //插入学生数据

    //test
    void testfunction(); //测试
public slots:
    void comboxActiveSlots();
private:
    Ui::DataShowWidget *ui;
    MyDataBase *pmyDataBase;
    QStandardItemModel *pmodel;
};

#endif // DATASHOWWIDGET_H
