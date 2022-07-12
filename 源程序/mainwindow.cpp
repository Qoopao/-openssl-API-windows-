#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "MyButton.h"
#include <QMovie>
#include <QLabel>
#include <QPixmap>
#include "stringwidget.h"
#include "filewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //显示MainWndow的两只动物
    QMovie *movie = new QMovie(":/pictures/dog1.gif");
    ui->giflabel->setScaledContents(true);
    ui->giflabel->resize(100,100);  //不加这一句动不起来
    ui->giflabel->setMovie(movie);
    movie->start();

    QMovie *movie2 = new QMovie(":/pictures/cat1.gif");
    ui->giflabel2->setScaledContents(true);
    ui->giflabel2->resize(100,100);
    ui->giflabel2->setMovie(movie2);
    movie2->start();



    //connect槽函数与信号
}

MainWindow::~MainWindow()
{
    delete ui;
}

//槽函数的实现

void MainWindow::on_FileButton_clicked(){
    this->close();
    FileWidget* filewidget=new FileWidget();
    filewidget->show();

}

