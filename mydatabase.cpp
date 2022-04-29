#include "mydatabase.h"
#include <QDebug>
#include <iostream>
#include <QFile>

//设计一个单例的数据库
MyDataBase::MyDataBase()
{
    pdatabase = new QSqlDatabase;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        *pdatabase = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        *pdatabase = QSqlDatabase::addDatabase("QSQLITE");
        //设置数据库
        this->setDatabase();
    }
}

//获取单例实例
MyDataBase *MyDataBase::getInstance()
{
    if(mInstance == nullptr){
        return new MyDataBase;
    }
    return mInstance;
}
MyDataBase* MyDataBase::mInstance =nullptr;

//析构
MyDataBase::~MyDataBase()
{
    //关闭数据库
    closeDataBase();
    delete this;
    delete pdatabase;
    pdatabase = nullptr;
}



//设置数据库
void MyDataBase::setDatabase()
{
    pdatabase->setDatabaseName("MyDataBase.db");
    pdatabase->setUserName("giao");
    pdatabase->setPassword("123456");
    qDebug() << "MyDataBase set success";
}

//关闭数据库
bool MyDataBase::closeDataBase()
{
    pdatabase->close();
    qDebug() << "database close";
    return true;
}




//执行sql脚本文件，用于插入假的数据
int MyDataBase::executeSqlFile(const char *sqlFilePath)
{
    int iRet = 0;
      QFile qfile(sqlFilePath);
      if (!qfile.exists()) {
          return -1;
      }
      if (!qfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
          qDebug() << "initDataBase open Fail";
          return -1;
      }
      QTextStream in(&qfile);
      in.setCodec("UTF-8");
      QString qstr_file_data = in.readAll();
      QSqlQuery qsql(*pdatabase);
      QStringList qstrlist_sql =  qstr_file_data.split(";");
      for (int i = 0; i < qstrlist_sql.size() - 1; i++) {
          QString qstr_sql_part = qstrlist_sql.at(i).toUtf8();
          bool sql_result = qsql.exec(qstr_sql_part);
          if (!sql_result) {
              QSqlError sql_error = qsql.lastError();
              std::cout << sql_error.text().toStdString() << std::endl;
              std::cout << sql_error.number() << std::endl;
              qDebug() << "initDataBase exe Fail";
              iRet = -1;
              break;
          }
      }
      return iRet;
}

//查找数据
//todo 查找数据的返回值是
QSqlQueryModel MyDataBase::searchSql(QString sqlCommand)
{
    QSqlQueryModel sqlQueryModel;
    openDataBase();

    QSqlQuery sql_query;
    QString select_all_sql = "select * from student";
    sql_query.prepare(select_all_sql);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString name = sql_query.value(1).toString();
            int age = sql_query.value(2).toInt();
            qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);

        }
    }

    closeDataBase();
}

//插入假的数据
int MyDataBase::insertFakeData()
{
    int result;
    openDataBase();
    result = this->executeSqlFile(":/initDataBase.sql");
    if(result != 0){
        qDebug() << "initDataBase Fail";
        closeDataBase();
        return -1;
    }
    closeDataBase();
    return 0;
}

//打开数据库
bool MyDataBase::openDataBase()
{
    if (!pdatabase->open())
    {
        qDebug() << "Error: Failed to connect database." << pdatabase->lastError();
        return false;
    }
    else
    {
        // do something
        qDebug() << "open success";
        return true;
    }
}


////操作数据库  todo
//int MyDataBase::operateDataBase(QString sqlcommand)
//{
//    QSqlQuery sql_query;
//    //QString create_sql = "create table student (id int primary key, name varchar(30), age int)";
//    sql_query.prepare(sqlcommand);
//    if(!sql_query.exec())
//    {
//        //todo
//    }
//    else
//    {
//        qDebug() << "Table created!";
//    }
//}

