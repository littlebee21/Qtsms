#ifndef DATASHOWSERVICE_H
#define DATASHOWSERVICE_H

#include <QList>
#include "mydatabase.h"

class DataShowService
{
public:
    DataShowService();

    QList<QList<QString>> getClassModel();   //获取class数据
    QList<QList<QString>> getStudentModel();   //获取学生数据

    //删除
    //int deletateStudentModel();  //删除学生数据
    int deletateStudentModelById(int id);

    int updateStudendNameModelById(int id,QString name);  //更新学生名字，通过id
    int insertStudentModel(QList<QString>);    //插入学生数据
private:
    MyDataBase *pmyDataBase;
};

#endif // DATASHOWSERVICE_H
