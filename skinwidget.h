#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <QWidget>

namespace Ui {
class SkinWidget;
}

class SkinWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SkinWidget(QWidget *parent = 0);
    ~SkinWidget();
protected:
    void mousePressEvent(QMouseEvent *e);

    void mouseMoveEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

signals:
    //void clicksignal(int index);
    void clickobj(int index);
private slots:
    //void changeskin(int index);
    void on_btnclicked();
    void on_btn_close_clicked();

private:
    Ui::SkinWidget *ui;
    bool m_Drag;    //鼠标是否点击
    QPoint m_point; //鼠标点击时相对于窗口左上角的位置


};

#endif // SKINWIDGET_H
