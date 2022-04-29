#include "datashowwidget.h"
#include "ui_datashowwidget.h"
#include "QVBoxLayout"
#include "QStandardItemModel"
#include <QDebug>



DataShowWidget::DataShowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataShowWidget)
{
    ui->setupUi(this);
    //设置comboBox
    ui->tableNameComboBox->addItem("student");
    ui->tableNameComboBox->addItem("teacher");
    ui->tableNameComboBox->addItem("admin");
    connect(ui->tableNameComboBox,&QComboBox::currentTextChanged,
            this,&DataShowWidget::comboxActiveSlots);

    //设置button
    //connect(ui->insertPushButton)

    //设置tableview
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("频率0,功率0,误差0").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->stuTableView->setModel(model);


    QStandardItemModel* model1 = new QStandardItemModel();
    QStringList labels1 = QObject::trUtf8("频率1,功率1,误差1").simplified().split(",");
    model1->setHorizontalHeaderLabels(labels1);
    ui->teacherTableView->setModel(model1);

    //connect(ui->tableNameComboBox,&QComboBox::activated(0)

    //数据库设置
    pmyDataBase = MyDataBase::getInstance();
    //pmyDataBase->searchSql("11");
}

DataShowWidget::~DataShowWidget()
{
    delete ui;
}


//获取学生数据 // todo
QItemSelectionModel DataShowWidget::getStudentModel()
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
