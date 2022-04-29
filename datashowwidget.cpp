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
    pmyDataBase = MyDataBase::getInstance();

    //设置comboBox
    ui->tableNameComboBox->addItem("student");
    ui->tableNameComboBox->addItem("teacher");
    ui->tableNameComboBox->addItem("admin");
    connect(ui->tableNameComboBox,&QComboBox::currentTextChanged,
            this,&DataShowWidget::comboxActiveSlots);

    //设置button
    //connect(ui->insertPushButton)
    connect(ui->selectPushButton,&QAbstractButton::clicked,
            this,&DataShowWidget::testfunction);//获取学生表格的数据 将查找按钮先作为测试按钮


    //设置tableview
    showAllTable();

    QStandardItemModel* model1 = new QStandardItemModel();
    QStringList labels1 = QObject::trUtf8("频率1,功率1,误差1").simplified().split(",");
    model1->setHorizontalHeaderLabels(labels1);
    ui->teacherTableView->setModel(model1);

    //connect(ui->tableNameComboBox,&QComboBox::activated(0)

}

DataShowWidget::~DataShowWidget()
{
    delete ui;
}

//显示表的信息
void DataShowWidget::showAllTable()
{
    QList<QList<QString>> returnData;
    returnData = getStudentModel();

    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("id,name,age").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

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
            model->setItem(i,j,item);
            qDebug() << "j number is" << j;
        }
        qDebug() << "i number is" << i;
    }
    ui->stuTableView->setModel(model);
    //ui->teacherTableView->setModel(model);
}



//查找学生数据
QList<QList<QString> > DataShowWidget::getStudentModel()
{
    QList<QList<QString>> returnData;
    returnData = pmyDataBase->searchSql("select * from student");
    qDebug() << returnData << "in sql serive";
    return returnData;
}


//测试功能按键
void DataShowWidget::testfunction()
{

}


void DataShowWidget::comboxActiveSlots()
{
    //让stackwidget切换到对应的页面
    int i = 0;
    i = ui->tableNameComboBox->currentIndex();
    qDebug() << i << "is the current combox index";
    ui->stackedWidget->setCurrentIndex(i);
    qDebug() << ui->stackedWidget->currentIndex()<< "is the current stackWidgetIndex";
}
