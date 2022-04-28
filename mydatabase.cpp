#include "mydatabase.h"
#include <QDebug>
#include <QFile>


//构造数据库
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
        this->setDatabase();
    }
}

//析构数据库
MyDataBase::~MyDataBase()
{
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
}

//关闭数据库
bool MyDataBase::closeDataBase()
{
    pdatabase->close();
    return true;
}

//操作数据库
int MyDataBase::operateDataBase(QString sqlcommand)
{
    QSqlQuery sql_query;
    //QString create_sql = "create table student (id int primary key, name varchar(30), age int)";
    sql_query.prepare(sqlcommand);
    if(!sql_query.exec())
    {
        //todo
    }
    else
    {
        qDebug() << "Table created!";
    }
}

//插入基本数据
int MyDataBase::insertFakeData()
{
    int result;
    result = executeSqlFile("./initDataBase.sql");
    if(result != 0){
        qDebug() << "initDataBase Fail";
        return -1;
    }
    return 0;
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
              //std::cout << sql_error.text().toStdString() << std::endl;
              //std::cout << sql_error.number() << std::endl;
              iRet = -1;
              break;
          }
      }

      return iRet;
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
        return true;
    }
}

