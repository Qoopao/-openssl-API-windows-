#include "MyButton.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QBitmap>

MyButton::MyButton(QWidget *parent):
    QPushButton(parent)
{
    QPixmap pixmap(":\\pictures\\background.jpg");

    resize(pixmap.size());
    /* 设置按钮的有效区域 */
    setMask(QBitmap(pixmap.mask()));
    setStyleSheet("QPushButton{border-image: url(:/init.png);}");
}

void MyButton::enterEvent(QEvent *)
{
    setStyleSheet("QPushButton{border-image: url(:/click.png);}");
}

void MyButton::leaveEvent(QEvent *)
{
    setStyleSheet("QPushButton{border-image: url(:/init.png);}");
}
