#include "datashowservice.h"
#include <QDebug>

DataShowService::DataShowService()
{
    pmyDataBase = MyDataBase::getInstance();
}

DataShowService::~DataShowService()
{
    delete pmyDataBase;
}

//查找class数据
QList<QList<QString> > DataShowService::getClassModel()
{
    return pmyDataBase->searchSql("select * from class");
}

//查找学生数据
QList<QList<QString> > DataShowService::getStudentModel()
{
    return pmyDataBase->searchSql("select * from student");
}

//根据id删除
int DataShowService::deletateStudentModelById(int id)
{
    QString str;
    str ="delete from student where id = " +
            QString::number(id);
    qDebug() << str << "in deletate byid service";
    return pmyDataBase->delelateSql(str);
}

//通过id修改名字
int DataShowService::updateStudendNameModelById(int id, QString name)
{
    QString str;
    str = "update student set name = '"+ name +
            "' where id = " +QString::number(id);
    qDebug() << str << "in update service";
    return pmyDataBase->updateSql(str);
}

//插入学生数据
int DataShowService::insertStudentModel(QList<QString> list)
{
    /*QString str = "insert into student values"
            " ('"+list[0]+"'," +
            " '"+list[1]+"',"+
            " '"+list[2]+"')";*/
    QString str = "INSERT INTO `student` VALUES ('"+list[0]+"', '张三', '男', '19', '计科', '162', '上海', '15925637846', '学生', '123456', '304', '1', '无', '记过')";
    qDebug() << str << "in insert service";
    return pmyDataBase->insertSql(str);
}
