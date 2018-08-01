#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QFile>
#include <QMouseEvent>
#include <QPainter>
#include <QtMath>
#include <QDebug>
double opacity1 = 0.0, opacity2 = 1.0;

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{

    ui->setupUi(this);
    init();
    toolbtn_list.append(ui->tbtn_serhome);
    toolbtn_list.append(ui->tbtn_syscheck);
    toolbtn_list.append(ui->toolButton_2);
    toolbtn_list.append(ui->toolButton_3);
    toolbtn_list.append(ui->toolButton_4);
    toolbtn_list.append(ui->toolButton_5);
    connect(&skinwidget,&SkinWidget::clickobj,this,&MainWidget::changeSkin);
}

MainWidget::~MainWidget()
{
    delete ui;
    delete trayicon;
}

void MainWidget::configWindow()
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowIcon(QIcon(":/img/main_icon.png"));
    for(int i = 0; i < ui->splitter->count(); i++)
    {
        ui->splitter->handle(i)->setEnabled(false);
    }


}

void MainWidget::init()
{
    m_Drag = false;
    location = this->geometry();

    timer1 = new QTimer;
    timer1->start(5);
    timer2 = new QTimer;
    connect(timer1, SIGNAL(timeout()), this, SLOT(slot_timer1()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(slot_timer2()));

    configWindow();
    trayicon = new QSystemTrayIcon();
    trayicon->setIcon(QIcon(":/img/main_icon.png"));
    trayicon->setToolTip(QString::fromLocal8Bit("图书管理系统"));
    trayicon->show();
}

void MainWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        m_Drag = true;
        m_point = e->pos();
        e->accept();
    }
}

void MainWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (m_Drag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - m_point);
        e->accept();
    }
}

void MainWidget::mouseReleaseEvent(QMouseEvent *)
{
    m_Drag = false;
}

void MainWidget::paintEvent(QPaintEvent *)
{
    QPixmap m_shadow(":/img/shadow.png");
    QPainter painter(this);
    QRect bottom(5, 136, 200, 7);
    QRect top(5, 0, 200, 3);
    QRect left(0, 3, 5, 133);
    QRect right(205, 3, 5, 133);
    QRect topRight(205, 0, 5, 3);
    QRect topLeft(0, 0, 5, 3);
    QRect bottomLeft(0, 136, 5, 7);
    QRect bottomRight(205, 136, 5, 7);
    QRect tBottom(5, this->height() - 7, this->width() - 10, 7);
    QRect tTop(5, 0, this->width() - 10, 3);
    QRect tLeft(0, 3, 5, this->height() - 10);
    QRect tRight(this->width() - 5, 3, 5, this->height() - 10);
    QRect tTopLeft(0, 0, 5, 3);
    QRect tTopRight(this->width() - 5, 0, 5, 3);
    QRect tBottomLeft(0, this->height() - 7, 5, 7);
    QRect tBottomRight(this->width() - 5, this->height() - 7, 5, 7);
    painter.drawPixmap(tBottom, m_shadow, bottom);
    painter.drawPixmap(tTop, m_shadow, top);
    painter.drawPixmap(tLeft, m_shadow, left);
    painter.drawPixmap(tRight, m_shadow, right);
    painter.drawPixmap(tTopRight, m_shadow, topRight);
    painter.drawPixmap(tTopLeft, m_shadow, topLeft);
    painter.drawPixmap(tBottomLeft, m_shadow, bottomLeft);
    painter.drawPixmap(tBottomRight, m_shadow, bottomRight);
}


void MainWidget::slot_timer1()
{
    if (opacity1 >= 1.0) {
        timer1->stop();
    }else{
        opacity1 += 0.01;
    }
    setWindowOpacity(opacity1);//设置窗口透明度
}

void MainWidget::slot_timer2()
{
    if (opacity2 <= 0.0) {
        timer2->stop();

        this->close();
    }else{
        opacity2 -= 0.01;
    }
    setWindowOpacity(opacity2);//设置窗口透明度
}

void MainWidget::on_tbtn_serhome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->tbtn_serhome->setStyleSheet("border-image:url(:/img/toolWidget/toolbar_hover.png)");
    for(int i=0; i<toolbtn_list.size(); i++)
    {
        if(toolbtn_list[i]!=ui->tbtn_serhome)
        {
            toolbtn_list[i]->setStyleSheet("");
        }
    }
}

void MainWidget::on_tbtn_syscheck_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tbtn_syscheck->setStyleSheet("border-image:url(:/img/toolWidget/toolbar_hover.png)");
    for(int i=0; i<toolbtn_list.size(); i++)
    {
        if(toolbtn_list[i]!=ui->tbtn_syscheck)
        {
            toolbtn_list[i]->setStyleSheet("");
        }
    }
}

void MainWidget::on_toolButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->toolButton_2->setStyleSheet("border-image:url(:/img/toolWidget/toolbar_hover.png)");
    for(int i=0; i<toolbtn_list.size(); i++)
    {
        if(toolbtn_list[i]!=ui->toolButton_2)
        {
            toolbtn_list[i]->setStyleSheet("");
        }
    }
}

void MainWidget::on_toolButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->toolButton_3->setStyleSheet("border-image:url(:/img/toolWidget/toolbar_hover.png)");
    for(int i=0; i<toolbtn_list.size(); i++)
    {
        if(toolbtn_list[i]!=ui->toolButton_3)
        {
            toolbtn_list[i]->setStyleSheet("");
        }
    }
}

void MainWidget::on_toolButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->toolButton_4->setStyleSheet("border-image:url(:/img/toolWidget/toolbar_hover.png)");
    for(int i=0; i<toolbtn_list.size(); i++)
    {
        if(toolbtn_list[i]!=ui->toolButton_4)
        {
            toolbtn_list[i]->setStyleSheet("");
        }
    }
}

void MainWidget::on_toolButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->toolButton_5->setStyleSheet("border-image:url(:/img/toolWidget/toolbar_hover.png)");
    for(int i=0; i<toolbtn_list.size(); i++)
    {
        if(toolbtn_list[i]!=ui->toolButton_5)
        {
            toolbtn_list[i]->setStyleSheet("");
        }
    }
}

void MainWidget::on_btn_close_clicked()
{
    skinwidget.close();
    timer2->start(5);
}

void MainWidget::on_btn_min_clicked()
{
    this->showMinimized();
}

void MainWidget::on_btn_skin_clicked()
{

    skinwidget.show();
}

void MainWidget::changeSkin(int index)
{
    QString background = QString(":/img/skin/") + QString::number(index) + QString("_big.png");
    qDebug()<<background;
    ui->topwidget->setStyleSheet("QWidget{background:transparent;");
    ui->topwidget->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(background);
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    ui->topwidget->setPalette(palette);
    skinwidget.setPalette(palette);
}
