#ifndef PARADIALOG_H
#define PARADIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class ParaDialog;
}

class ParaDialog : public QDialog
{
    Q_OBJECT

public:
    QString alg;
    QString src;
    QString dest;
    QString usage;


public:
    explicit ParaDialog(QWidget *parent = nullptr);
    ~ParaDialog();


public slots:
    void getparas(QString alg,QString src,QString dest,QString usage);
    void on_buttonBox_clicked(QAbstractButton *button);//这个槽对应的是paradialog的buttonbox

private:
    Ui::ParaDialog *ui;
};

#endif // PARADIALOG_H
