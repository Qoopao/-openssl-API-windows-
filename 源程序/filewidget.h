#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>

namespace Ui {
class FileWidget;
}

class FileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileWidget(QWidget *parent = nullptr);
    ~FileWidget();


signals:
    void sendparas(QString alg,QString src,QString dest,QString usage);


private slots:
    //加密模块
    void on_BackButton_clicked();
    void on_choosefile_clicked();
    void on_choosefiletarget_clicked();
    void on_parabutton_clicked();

    //签名模块
    void on_privfile_clicked();
    void on_srcfile_clicked();
    void on_sign_clicked();

    void on_pem_clicked();
    void on_srcfile2_clicked();
    void on_signfile_clicked();
    void on_checksign_clicked();

private:
    Ui::FileWidget *ui;
};

#endif // FILEWIDGET_H
