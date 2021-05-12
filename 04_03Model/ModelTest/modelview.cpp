#include "modelview.h"
#include "ui_modelview.h"
#include "QDebug"
#include "QSqlError"
#include "QHeaderView"
#include "QDateTime"
ModelView::ModelView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModelView)
{
    ui->setupUi(this);
    this->item=new AddItem;
    this->record=new AddRecord;

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("information.db");
    qDebug()<<db.open();


        this->model = new QSqlTableModel(this, db);
        model->setTable("record");
        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        model->select();
        this->ui->tableView->setModel(model);
        this->ui->tableView->verticalHeader()->hide();
        this->ui->tableView->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
}

ModelView::~ModelView()
{
    delete ui;
}


void ModelView::on_action_addItem_triggered()
{
    item->exec();
}

void ModelView::on_action_addRecord_triggered()
{
    QDateTime date;
    record->exec();
    QString time=date.currentDateTime().toString("yyyy-MM-dd");
    QString score= record->getScore();
    QString name=record->getName();
    QString tip=record->getTip();

    int row=model->rowCount();
    model->insertRow(row);
    model->setData(model->index(row,0),time);
    model->setData(model->index(row,1),name);
    model->setData(model->index(row,2),score);
    model->setData(model->index(row,3),tip);
    if(!model->submitAll()){
        qDebug()<<model->lastError().text();
    }

}
