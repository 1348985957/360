#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "skinwidget.h"

#include <QWidget>
#include <QTimer>
#include <QStatusBar>
#include <QList>
#include <QToolButton>
#include <QSystemTrayIcon>
namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void configWindow();
    void init();
protected:
    void mousePressEvent(QMouseEvent *e);

    void mouseMoveEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

    void paintEvent(QPaintEvent *e);
private slots:
    void slot_timer1();

    void slot_timer2();

    void on_tbtn_serhome_clicked();

    void on_tbtn_syscheck_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_btn_close_clicked();

    void on_btn_min_clicked();

    void on_btn_skin_clicked();

    void changeSkin(int index);
private:
    SkinWidget skinwidget;
    Ui::MainWidget *ui;
    bool m_Drag;    //鼠标是否点击
    QPoint m_point; //鼠标点击时相对于窗口左上角的位置
    QRect location;
    QTimer *timer1, *timer2;
    QList <QToolButton *> toolbtn_list;
    QSystemTrayIcon *trayicon;
};

#endif // MAINWIDGET_H
