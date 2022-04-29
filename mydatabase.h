#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardItemModel>


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

    int executeSqlFile(const char *sqlFilePath); //执行sql脚本文件

    int updateSql(QString sqlCommand); //更新数据
    int insertSql(QString sqlCommand); //新增数据
    int delelateSql(QString sqlCommand); //删除数据
    QList<QList<QString>> searchSql(QString sqlCommand);   //查找数据
    int operateDataBase(QString sqlCommand);   //操作数据库

public slots:
    int insertFakeData();//插入假数据
private:
    MyDataBase();
    static MyDataBase *mInstance;
    QSqlDatabase *pdatabase;
};

#endif // MYDATABASE_H
