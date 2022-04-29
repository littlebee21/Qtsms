#include "datashowwidget.h"
#include "ui_datashowwidget.h"
#include "QVBoxLayout"
#include "QStandardItemModel"
#include <QDebug>
#include "QStandardItem"



DataShowWidget::DataShowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataShowWidget)
{
    ui->setupUi(this);
    //数据库设置
    pDataShowService = new DataShowService;

    //设置comboBox
    ui->tableNameComboBox->addItem("student");
    ui->tableNameComboBox->addItem("class");
    ui->tableNameComboBox->addItem("admin");

    //设置button
    //connect()

    //设置tableview
    pmodel = new QStandardItemModel[10];
    showAllTable(pmodel,10);

    //槽
    //combox切换页面
    connect(ui->tableNameComboBox,&QComboBox::currentTextChanged,
            this,&DataShowWidget::comboxActiveSlots);

    //测试
    connect(ui->selectPushButton,&QAbstractButton::clicked,
            this,&DataShowWidget::testfunction);

    //点击查找按钮，查看所有的数据库表
    //connect(ui->selectPushButton,&QAbstractButton::clicked,
    //            this,&DataShowWidget::showAllTable);
}

DataShowWidget::~DataShowWidget()
{
    delete [] pmodel;
    delete ui;
}

//view让stackwidget切换到对应的页面
void DataShowWidget::comboxActiveSlots()
{
    int i = 0;
    i = ui->tableNameComboBox->currentIndex();
    qDebug() << i << "is the current combox index";
    ui->stackedWidget->setCurrentIndex(i);
    qDebug() << ui->stackedWidget->currentIndex()<< "is the current stackWidgetIndex";
}


//显示表的信息
void DataShowWidget::showAllTable(QStandardItemModel *pmodel,
                                  int length)
{
    QList<QList<QString>> returnData;
    returnData = pDataShowService->getStudentModel();

    buildModelHead(pmodel,"student");
    buildModel(pmodel,returnData);
    ui->stuTableView->setModel(pmodel);

    returnData = pDataShowService->getClassModel();
    buildModelHead(pmodel+1,"class");
    buildModel(pmodel+1,returnData);
    ui->teacherTableView->setModel(pmodel+1);
}



//构建数据模型头
QStandardItemModel *DataShowWidget::buildModelHead(QStandardItemModel *pmodel,
                                                   QString tableName)
{   QStringList labels;
    if(tableName == "student")
    labels = QObject::trUtf8("id,name,age").simplified().split(",");
    if(tableName == "class")
    labels = QObject::trUtf8("id,object,teacher").simplified().split(",");

    pmodel->setHorizontalHeaderLabels(labels);
    return pmodel;
}


//view构建数据模型：
QStandardItemModel *DataShowWidget::buildModel(QStandardItemModel *pmodel,
                                               QList<QList<QString>> returnData)
{
    //定义item
    int i = 0;
    int j = 0;
    QStandardItem* item = 0;
    QList<QList<QString>>::iterator ior;
    QList<QString>::iterator jor;

    for(ior=returnData.begin();ior != returnData.end();ior++,i++){
        j = 0;
        for(jor=ior->begin();jor !=ior->end();jor++,j++){
            item = new QStandardItem(*jor);
            pmodel->setItem(i,j,item);
            //qDebug() << "j number is" << j;
        }
        //qDebug() << "i number is" << i;
    }
    return pmodel;
}


//测试功能按键
void DataShowWidget::testfunction()
{

}



