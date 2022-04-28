#include "mouseevent.h"

MouseEvent::MouseEvent(QWidget *parent) : QWidget(parent){}

void MouseEvent::mousePressEvent(QMouseEvent *event){
    // 左键按下
    if(event->button() == Qt::LeftButton){
        m_point = event->pos(); // 这个是鼠标相对于窗口坐标。
        m_bisPressed = true;    // true表示按下
    }
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event)         // 用来处理声明了但没有使用的闲置参数,使其不报警告
    m_bisPressed = false;   // 鼠标释放
}

void MouseEvent::mouseMoveEvent(QMouseEvent *event){
    // 移动界面需要调用move函数
    if(m_bisPressed){
        move(event->globalPos() - m_point);
    }
}
