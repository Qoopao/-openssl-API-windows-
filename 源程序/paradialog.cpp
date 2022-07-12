#include "paradialog.h"
#include "ui_paradialog.h"
#include "crypto.h"
#include <QMessageBox>
ParaDialog::ParaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaDialog)
{
    ui->setupUi(this);
    ui->label_alg->setHidden(true);
    ui->label_alg->setHidden(true);
    ui->label_src->setHidden(true);
    ui->label_dest->setHidden(true);
    ui->label_usage->setHidden(true);
    ui->label_mode->setHidden(true);
    ui->label_iv->setHidden(true);
    ui->label_key->setHidden(true);

}

ParaDialog::~ParaDialog()
{
    delete ui;
}

void ParaDialog::getparas(QString alg,QString src,QString dest,QString usage){
    ui->label_alg->setText(alg);//密码算法
    ui->label_src->setText(src);//文件
    ui->label_dest->setText(dest);//目标目录
    ui->label_usage->setText(usage);//加密还是解密

    ui->show->setText(QString("当前密码算法：%1%2").arg(ui->label_alg->text()).arg(ui->label_usage->text()));

    //ecb模式没有iv
}

void ParaDialog::on_buttonBox_clicked(QAbstractButton *button){
        if(button == static_cast<QAbstractButton *>(ui->buttonBox->button(QDialogButtonBox::Ok))){
            qDebug() << R"(Button "OK" has been clicked.)";
            //接下来写加密/解密
            //现在已经把dialog上的标签作为不会被销毁的变量了
            //初始化标签
            ui->label_mode->setText(ui->comboBox->currentText());
            ui->label_iv->setText(ui->lineEdit->text());
            ui->label_key->setText(ui->lineEdit_2->text());

            qDebug()<<"alg:"<<ui->label_alg->text();
            qDebug()<<"MODE:"<< ui->label_mode->text();
            qDebug()<<"iv:"<< ui->label_iv->text();
            qDebug()<<"key:"<< ui->label_key->text();
            qDebug()<<"usage"<<ui->label_usage->text();

            Crypto* c=new Crypto();
            if(ui->label_alg->text().compare("AES")==0){
                if(ui->label_mode->text().compare("ECB模式")==0){
                    if(ui->label_usage->text().compare("加密")==0){
                        if(c->AES_ECB_ENCRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_key->text())){
                            qDebug() << R"(encrypt ok)";
                            QMessageBox::information(this,NULL,QString("加密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/AES_ecb_en"),QMessageBox::Cancel);
                        }
                        else{
                            qDebug() << R"(encrypt failed)";
                            QMessageBox::information(this,NULL,QString("加密失败"),QMessageBox::Close);
                        }
                    }
                    else{
                        if(c->AES_ECB_DECRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_key->text())){
                            qDebug() << R"(decrypt ok)";
                            QMessageBox::information(this,NULL,QString("解密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/AES_ecb_de"),QMessageBox::Cancel);
                        }
                        else{
                            qDebug() << R"(decrypt failed)";
                            QMessageBox::information(this,NULL,QString("解密失败"),QMessageBox::Close);
                        }
                    }
                }
                else{
                    //CBC
                    if(ui->label_usage->text().compare("加密")==0){
                        if(c->AES_CBC_ENCRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_iv->text(),ui->label_key->text())){
                            qDebug() << R"(encrypt ok)";
                            QMessageBox::information(this,NULL,QString("加密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/AES_cbc_en"),QMessageBox::Cancel);

                        }
                        else{
                            qDebug() << R"(encrypt failed)";
                            QMessageBox::information(this,NULL,QString("加密失败"),QMessageBox::Close);
                        }
                    }
                    else{
                       if(c->AES_CBC_DECRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_iv->text(),ui->label_key->text())){
                           qDebug() << R"(decrypt ok)";
                           QMessageBox::information(this,NULL,QString("解密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/AES_cbc_de"),QMessageBox::Cancel);
                       }
                       else{
                           qDebug() << R"(decrypt failed)";
                           QMessageBox::information(this,NULL,QString("解密失败"),QMessageBox::Close);
                       }
                    }
                }
            }
            else{
            //DES
                if(ui->label_mode->text().compare("ECB模式")==0){
                    if(ui->label_usage->text().compare("加密")==0){
                        if(c->DES_ECB_ENCRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_key->text())){
                            qDebug() << R"(encrypt ok)";
                            QMessageBox::information(this,NULL,QString("加密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/DES_ecb_en"),QMessageBox::Cancel);
                        }
                        else{
                            qDebug() << R"(encrypt failed)";
                            QMessageBox::information(this,NULL,QString("加密失败"),QMessageBox::Close);
                        }
                    }
                    else{
                        if(c->DES_ECB_DECRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_key->text())){
                            qDebug() << R"(decrypt ok)";
                            QMessageBox::information(this,NULL,QString("解密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/DES_ecb_de"),QMessageBox::Cancel);
                        }
                        else{
                            qDebug() << R"(decrypt failed)";
                            QMessageBox::information(this,NULL,QString("解密失败"),QMessageBox::Close);
                        }
                    }
                }
                else{
                    //CBC
                    if(ui->label_usage->text().compare("加密")==0){
                        if(c->DES_CBC_ENCRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_iv->text(),ui->label_key->text())){
                            qDebug() << R"(encrypt ok)";
                            QMessageBox::information(this,NULL,QString("加密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/DES_cbc_en"),QMessageBox::Cancel);
                        }
                        else{
                            qDebug() << R"(encrypt failed)";
                            QMessageBox::information(this,NULL,QString("加密失败"),QMessageBox::Close);
                        }
                    }
                    else{
                        if(c->DES_CBC_DECRYPT(ui->label_src->text(),ui->label_dest->text(),ui->label_iv->text(),ui->label_key->text())){
                            qDebug() << R"(encrypt ok)";
                            QMessageBox::information(this,NULL,QString("加密成功,文件保存在%1%2").arg(ui->label_dest->text()).arg("/DES_cbc_de"),QMessageBox::Cancel);
                        }
                        else{
                            qDebug() << R"(decrypt failed)";
                            QMessageBox::information(this,NULL,QString("解密失败"),QMessageBox::Close);
                        }
                    }
                }
            }

        }
        else if(button == ui->buttonBox->button(QDialogButtonBox::Cancel)){
            qDebug() << R"(Button "Cancle" has been clicked.)";
        }
        else {
             qDebug() << R"(Other Button has been clicked.)";
        }
}
