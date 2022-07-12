#include "mainwindow.h"
#include <QSplashScreen>
#include <QDateTime>
#include <QLabel>
#include <QMovie>
#include <QApplication>
#include <windows.h>
#include <openssl/aes.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPixmap pic(":\\pictures\\dong.gif");   //   :表示qrc目录

    QSplashScreen screen(pic);      //QSplashScreen提供启动画面
    QLabel label(&screen);          //标签类，用screen作为宿主构造一个标签label
    QMovie mv(":\\pictures\\dong.gif");  //用一张gif构造一个QMovie对象

    label.setMovie(&mv);            //将标签的内容设置成movie
    mv.start();                     //movie开始播放
    screen.show();                  //加载启动画面

//背景是screen，在screen上创建一个标签，标签上有一个mv，mv是动态图，开始播放动态图，接着开始加载背景screen

    QDateTime t=QDateTime::currentDateTime();       //获取当前时间
    while(t.secsTo(QDateTime::currentDateTime())<1){ //启动画面展示5秒左右
        a.processEvents(); //使程序在显示启动画面的同时仍能响应鼠标等其他事件
    }

    w.show();
    screen.finish(&w);

    return a.exec();
}
