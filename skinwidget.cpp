#include "skinwidget.h"
#include "ui_skinwidget.h"

#include <QDebug>
#include <QStringList>
#include <QMouseEvent>

SkinWidget::SkinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SkinWidget)
{
    m_Drag = false;
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->btn_0,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    connect(ui->btn_1,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    connect(ui->btn_2,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    connect(ui->btn_3,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    connect(ui->btn_4,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    connect(ui->btn_5,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    connect(ui->btn_6,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
    connect(ui->btn_7,SIGNAL(clicked()),this,SLOT(on_btnclicked()));
}

SkinWidget::~SkinWidget()
{
    delete ui;
}

void SkinWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        m_Drag = true;
        m_point = e->pos();
        e->accept();
    }
}

void SkinWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (m_Drag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - m_point);
        e->accept();
    }
}

void SkinWidget::mouseReleaseEvent(QMouseEvent *)
{
    m_Drag = false;
}

void SkinWidget::on_btnclicked()
{
    ui->topwidget->setStyleSheet("");
    QChar ch;
    QString objName = this->sender()->objectName();
    QStringList list = objName.split("_");
    int index = QString(list.last()).toInt();
    qDebug() << objName;
    qDebug() << index;
    emit clickobj(index);
}

void SkinWidget::on_btn_close_clicked()
{
    this->close();
}
