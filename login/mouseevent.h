#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

class MouseEvent : public QWidget{
public:
    explicit MouseEvent(QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint m_point;
    bool m_bisPressed;  // 判断鼠标是否按下
};

#endif // MOUSEEVENT_H
