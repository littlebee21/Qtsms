#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>


//数据库驱动类
class MyDataBase: public QObject
{
    Q_OBJECT
public:
    static MyDataBase *getInstance();

    virtual ~MyDataBase();
    void setDatabase(void);
    bool openDataBase(void);       //打开
    bool closeDataBase(void);    //关闭数据
    //int operateDataBase(QString);   //操作数据库

    int executeSqlFile(const char *sqlFilePath); //执行sql脚本文件

    int updateSql(); //更新数据
    int insertSql(); //新增数据
    int delelateSql(); //删除数据
    QSqlQueryModel searchSql(QString sqlCommand);   //搜索数据

public slots:
    int insertFakeData();//插入假数据
private:
    MyDataBase();
    static MyDataBase *mInstance;
    QSqlDatabase *pdatabase;
};

#endif // MYDATABASE_H
