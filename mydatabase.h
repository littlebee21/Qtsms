#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class MyDataBase
{
public:
    MyDataBase();
    ~MyDataBase();
    void setDatabase(void);
    bool openDataBase(void);       //打开
    bool closeDataBase(void);    //关闭数据
    int operateDataBase(QString);   //操作数据库

    int insertFakeData(void);//插入假数据
    int executeSqlFile(const char *sqlFilePath); //执行sql脚本文件
private:
    QSqlDatabase *pdatabase;
};

#endif // MYDATABASE_H
