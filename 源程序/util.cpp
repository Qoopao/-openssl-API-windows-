#include "util.h"
#include <QFile>
#include <QDebug>
#include <string.h>
#include <QTextCodec>
#include <QStringConverter>

util::util()
{

}
bool util::fileread(QString url,QByteArray& data){
    url.toLocal8Bit().constData();
    QFile q=(url);
    qDebug()<<"-------读文件的url---------------"<<url;
    QTextStream in(&q);
    in.setEncoding(QStringConverter::Utf8);
    if(!q.open(QIODevice::ReadOnly)){
        qDebug()<<"fail to open READ file";
        return false;
    }
    else{
        qDebug()<<"file size:"<<q.size();
        //qDebug()<<"readall return :"<<q.readAll();
        data=q.read(q.size());
        q.close();
        return true;
    }
}
bool util::filewrite(QString url,unsigned char* data,int len){
    url.toLocal8Bit().constData();
    QFile c(url);
    qDebug()<<"-------写文件的url---------------"<<url;
    QTextStream in(&c);
    in.setEncoding(QStringConverter::Utf8);
    if(!c.open(QIODevice::WriteOnly)){
        qDebug()<<"fail to open WRITE file";
        return false;
    }
    else{
        char intmp[len];
        memcpy(intmp,data,len);
        qDebug()<<"write return :"<<c.write(intmp,len);
        c.close();
        return true;
    }
}
