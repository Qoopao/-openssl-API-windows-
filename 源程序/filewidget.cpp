#include "filewidget.h"
#include "ui_filewidget.h"
#include "mainwindow.h"
#include <QFileDialog>
#include "paradialog.h"
#include <QMessageBox>
#include "crypto.h"

QString srcfileName=nullptr;
QString destdir=nullptr;

QString privfile=nullptr;
QString srcfile=nullptr;


QString pem=nullptr;
QString srcfile2=nullptr;
QString signfile=nullptr;
QString checksign=nullptr;

FileWidget::FileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileWidget)
{
    ui->setupUi(this);

    //设置框内标题的字体，“对文件的操作”
    QPalette label_pe;
    QFont ft;
    ft.setPointSize(20);
    label_pe.setColor(QPalette::WindowText, Qt::black);
    ui->labeltodisplay->setPalette(label_pe);
    ui->labeltodisplay->setFont(ft);
    ui->graphicsView->backgroundBrush();

}

FileWidget::~FileWidget()
{
    delete ui;
}

void FileWidget::on_BackButton_clicked(){
    this->close();
    MainWindow* m=new MainWindow();
    m->show();
}

void FileWidget::on_choosefile_clicked(){
    srcfileName = QFileDialog::getOpenFileName(this,"选择需要加密的文件","C:","所有文件(*)");
    qDebug()<<"srcfilename : "<<srcfileName;
}

void FileWidget::on_choosefiletarget_clicked(){
    destdir = QFileDialog::getExistingDirectory(this,"选择存放目录","C:");
    qDebug()<<"destdir : "<<destdir;
}

void FileWidget::on_parabutton_clicked(){
    //检查是否选择了需要加密/解密的文件
    if(srcfileName==nullptr){
        QMessageBox::critical(this,"参数不完整","文件没选",QMessageBox::Close);
        return;
    }

    //检查是否选择了输出目录
    if(destdir==nullptr){
        QMessageBox::critical(this,"参数不完整","输出路径没选",QMessageBox::Close);
        return;
    }

    //检测是否选择了加密还是解密
    QString usage;
    if(ui->radioButton->isChecked()){
        usage="加密";
    }
    else if(ui->radioButton_2->isChecked()){
        usage="解密";
    }
    else{
        QMessageBox::critical(this,"参数不完整","加密还是解密呢？",QMessageBox::Close);
        return;
    }
    //connect
    ParaDialog* p=new ParaDialog();
    connect(this,SIGNAL(sendparas(QString,QString,QString,QString)),p,SLOT(getparas(QString,QString,QString,QString)));
    //这句connect函数的参数分别为:发送者，信号，接收者，接收者的槽。槽不用谢所属的类，因为接收者已经在第三个参数给了，不需要再告诉编译器哪里找这个槽
    //信号如果带参数，信号的参数会按顺序复制给槽函数，严格的情况下，信号与槽的参数个数和类型需要一致，至少信号的参数不能少于槽的参数。如果不匹配，会出现编译错误或运行错误。
    emit sendparas(ui->comboBox->currentText(),srcfileName,destdir,usage);

    //设置空是为了下次加密/解密的检查
    srcfileName=nullptr;
    destdir=nullptr;
    p->show();
}

void FileWidget::on_privfile_clicked(){
    privfile = QFileDialog::getOpenFileName(this,"选择私钥文件","C:","pem文件(*.pem)");
    qDebug()<<"privfilename : "<<privfile;
}
void FileWidget::on_srcfile_clicked(){
    srcfile = QFileDialog::getOpenFileName(this,"选择需要签名的文件","C:","所有文件(*)");
    qDebug()<<"srcfilename : "<<srcfile;
}
void FileWidget::on_sign_clicked(){
    //检查是否选择了私钥文件
    if(privfile==nullptr){
        QMessageBox::critical(this,"参数不完整","私钥文件没选",QMessageBox::Close);
        return;
    }

    //检查是否选择了待签名的文件
    if(srcfile==nullptr){
        QMessageBox::critical(this,"参数不完整","需要签名的文件没选",QMessageBox::Close);
        return;
    }

    Crypto* c=new Crypto();
    QFileInfo fileinfo;
    fileinfo=QFileInfo(srcfile);
    if(c->RSA_SIGN(privfile,srcfile)){
        qDebug() << R"(sign ok)";
        QMessageBox::information(this,NULL,QString("签名成功,文件保存在%1").arg(fileinfo.filePath()+".sign"),QMessageBox::Cancel);
    }
    else{
        qDebug() << R"(sign failed)";
        QMessageBox::information(this,NULL,QString("签名失败"),QMessageBox::Cancel);
    }

}

void FileWidget::on_pem_clicked(){
    pem = QFileDialog::getOpenFileName(this,"选择公钥文件","C:","pem文件(*.pem)");
    qDebug()<<"pem : "<<pem;
}
void FileWidget::on_srcfile2_clicked(){
    srcfile2 = QFileDialog::getOpenFileName(this,"选择验签的文件","C:","所有文件(*)");
    qDebug()<<"srcfile2name : "<<srcfile2;
}
void FileWidget::on_signfile_clicked(){
    signfile = QFileDialog::getOpenFileName(this,"选择需要签名的文件","C:","sign文件(*.sign)");
    qDebug()<<"signfile : "<<signfile;
}
void FileWidget::on_checksign_clicked(){
    //检查是否选择了公钥文件
    if(pem==nullptr){
        QMessageBox::critical(this,"参数不完整","需要签名的文件没选",QMessageBox::Close);
        return;
    }

    //检查是否选择了需要验签的文件
    if(srcfile2==nullptr){
        QMessageBox::critical(this,"参数不完整","需要签名的文件没选",QMessageBox::Close);
        return;
    }

    //检查是否选择了签名文件
    if(signfile==nullptr){
        QMessageBox::critical(this,"参数不完整","需要签名的文件没选",QMessageBox::Close);
        return;
    }

    Crypto* c=new Crypto();
    if(c->RSA_VERIFY(pem,srcfile2,signfile)){
        qDebug() << R"(VERIFY success)";
        QMessageBox::information(this,NULL,QString("验证通过"),QMessageBox::Cancel);
    }
    else{
        qDebug() << R"(VERIFY failed)";
        QMessageBox::information(this,NULL,QString("验证失败"),QMessageBox::Cancel);
    }

}

