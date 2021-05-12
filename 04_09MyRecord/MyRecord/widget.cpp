#include "widget.h"
#include "ui_widget.h"
#include "QIcon"
#include "QSize"
#include "QDebug"
#include "QSqlError"
#include "QHeaderView"
#include "QDateTime"
#include "QMessageBox"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    sum_score=0;

    this->item=new ItemDialog;
    this->record=new RecordDialog;

    this->VLayout=new QVBoxLayout;
    //this->tableView=new QTableView;
    this->toolBar=new QToolBar("工具栏",this);
    this->action_record=new QWidgetAction(this);
    this->action_item=new QWidgetAction(this);
    this->action_delete=new QWidgetAction(this);
    this->action_modify=new QWidgetAction(this);
    this->action_return=new QWidgetAction(this);
    this->sum=new QWidgetAction(this);
    /*********************************工具栏*******************************/
    action_record->setText("添加记录");
    action_record->setToolTip("添加记录");
    action_record->setIcon(QIcon(":/item.png"));
    action_item->setText("添加项目");
    action_item->setToolTip("添加项目");
    action_item->setIcon(QIcon(":/recode.png"));
    action_delete->setText("删除记录");
    action_delete->setToolTip("删除记录");
    action_delete->setIcon(QIcon(":/delete.png"));
    action_modify->setText("保存修改");
    action_modify->setToolTip("保存修改");
    action_modify->setIcon(QIcon(":/modify.png"));
    action_return->setText("撤销修改");
    action_return->setToolTip("撤销修改");
    action_return->setIcon(QIcon(":/return.png"));
    sum->setText("分数合计");
    sum->setToolTip("分数合计");
    sum->setIcon(QIcon(":/sum.jpg"));
    toolBar->addAction(action_record);
    toolBar->addAction(action_delete);
    toolBar->addAction(action_modify);
//    toolBar->addAction(action_return);
    toolBar->addAction(action_item);
    toolBar->addAction(sum);
    toolBar->setIconSize(QSize(20,20));
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    /*********************************布局*******************************/
    VLayout->addWidget(toolBar);
    VLayout->addWidget(this->ui->tableView);
    VLayout->setSpacing(0);
    VLayout->setContentsMargins(0,0,0,0);
    /*********************************数据库*******************************/
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("information.db");
    db.open();
    this->model = new QSqlTableModel(this, db);
    model->setTable("record");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    this->ui->tableView->setModel(model);
    this->ui->tableView->verticalHeader()->hide();
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    //db.close();
    /*********************************信号与槽*******************************/
    connect(action_item,SIGNAL(triggered()),this,SLOT(showItem()));
    connect(action_record,SIGNAL(triggered()),this,SLOT(showRecord()));
    connect(action_delete,SIGNAL(triggered()),this,SLOT(doDelete()));
    connect(action_modify,SIGNAL(triggered()),this,SLOT(doModify()));
    connect(action_return,SIGNAL(triggered()),this,SLOT(doReturn()));
    connect(sum,SIGNAL(triggered()),this,SLOT(doSum()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showItem()
{
    //qDebug()<<"item";
    item->exec();
}

void Widget::showRecord()
{
    QDateTime date;
    record->exec();
    if(record->getOK()){
        QString time=date.currentDateTime().toString("yyyy-MM-dd");
        QString score= record->getScore();
        QString name=record->getName();
        QString tip=record->getTip();

        int row=model->rowCount();
        model->insertRow(row);
        QString row_text="记录"+QString::number(row+1);
        model->setData(model->index(row,0),row_text);
        model->setData(model->index(row,1),time);
        model->setData(model->index(row,2),name);
        model->setData(model->index(row,3),score);
        model->setData(model->index(row,4),tip);
        if(!model->submitAll()){
            qDebug()<<model->lastError().text();
        }
    }else {
        return;
    }
}

void Widget::doDelete()
{
    int curRow = ui->tableView->currentIndex().row();
    //获取选中的行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),"确定","取消");
    if(ok == 0)
    {
        model->removeRow(curRow);//删除该行
        //model->submitAll();
        model->setTable("record");   //重新关联表
        model->select();   //这样才能再次显示整个表的内容
    }else {
        return;//否则提交，在数据库中删除该行model->revertAll(); //如果不删除，则撤销
    }
//int curRow = ui->tableView->currentIndex().row();
//    //获取选中的行
//    model->removeRow(curRow);
//    //删除该行
//    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),
//                         QMessageBox::Yes,QMessageBox::No);
//    if(ok == QMessageBox::No)
//    {
//       model->revertAll(); //如果不删除，则撤销
//    }
//    else model->submitAll(); //否则提交，在数据库中删除该行
}

void Widget::doModify()
{
    model->submitAll();
}

void Widget::doReturn()
{
    model->revertAll();
}

void Widget::doSum()
{
    sum_score=0;
//    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("information.db");
//    db.open();
    QSqlQuery query;
    QString text="SELECT 分数 FROM record";
    query.prepare(text);
    query.exec();
    if(query.isActive()){
        while (query.next()) {
            sum_score += query.value(0).toInt();
        }
        QString sum_scoreText=QString::number(sum_score);
        QMessageBox::information(this,"总分查询","当前分数是"+sum_scoreText+"分","确定");
    }
}

