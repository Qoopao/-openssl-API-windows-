/********************************************************************************
** Form generated from reading UI file 'paradialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARADIALOG_H
#define UI_PARADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ParaDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_alg;
    QLabel *label_src;
    QLabel *label_dest;
    QLabel *label_usage;
    QLabel *label_mode;
    QLabel *label_iv;
    QLabel *label_key;
    QLabel *label_3;
    QLabel *show;

    void setupUi(QDialog *ParaDialog)
    {
        if (ParaDialog->objectName().isEmpty())
            ParaDialog->setObjectName(QString::fromUtf8("ParaDialog"));
        ParaDialog->resize(508, 333);
        buttonBox = new QDialogButtonBox(ParaDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-20, 270, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(ParaDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(190, 110, 111, 31));
        lineEdit = new QLineEdit(ParaDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 170, 271, 27));
        lineEdit_2 = new QLineEdit(ParaDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 220, 271, 27));
        label = new QLabel(ParaDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 170, 69, 20));
        label_2 = new QLabel(ParaDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 220, 69, 20));
        label_alg = new QLabel(ParaDialog);
        label_alg->setObjectName(QString::fromUtf8("label_alg"));
        label_alg->setGeometry(QRect(60, 110, 69, 20));
        label_src = new QLabel(ParaDialog);
        label_src->setObjectName(QString::fromUtf8("label_src"));
        label_src->setGeometry(QRect(150, 130, 69, 20));
        label_dest = new QLabel(ParaDialog);
        label_dest->setObjectName(QString::fromUtf8("label_dest"));
        label_dest->setGeometry(QRect(320, 100, 69, 20));
        label_usage = new QLabel(ParaDialog);
        label_usage->setObjectName(QString::fromUtf8("label_usage"));
        label_usage->setGeometry(QRect(350, 140, 69, 20));
        label_mode = new QLabel(ParaDialog);
        label_mode->setObjectName(QString::fromUtf8("label_mode"));
        label_mode->setGeometry(QRect(420, 300, 69, 20));
        label_iv = new QLabel(ParaDialog);
        label_iv->setObjectName(QString::fromUtf8("label_iv"));
        label_iv->setGeometry(QRect(390, 300, 69, 20));
        label_key = new QLabel(ParaDialog);
        label_key->setObjectName(QString::fromUtf8("label_key"));
        label_key->setGeometry(QRect(40, 90, 69, 20));
        label_3 = new QLabel(ParaDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 0, 261, 101));
        show = new QLabel(ParaDialog);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(260, 20, 241, 51));

        retranslateUi(ParaDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ParaDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ParaDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ParaDialog);
    } // setupUi

    void retranslateUi(QDialog *ParaDialog)
    {
        ParaDialog->setWindowTitle(QCoreApplication::translate("ParaDialog", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ParaDialog", "CBC\346\250\241\345\274\217", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ParaDialog", "ECB\346\250\241\345\274\217", nullptr));

        label->setText(QCoreApplication::translate("ParaDialog", "iv", nullptr));
        label_2->setText(QCoreApplication::translate("ParaDialog", "key", nullptr));
        label_alg->setText(QString());
        label_src->setText(QString());
        label_dest->setText(QString());
        label_usage->setText(QString());
        label_mode->setText(QString());
        label_iv->setText(QString());
        label_key->setText(QString());
        label_3->setText(QCoreApplication::translate("ParaDialog", "<html><head/><body><p>AES iv:16Byte key:16/24/32Byte</p><p>DES iv:8Byte   key:8Byte</p><p>\346\263\250:ECB\346\250\241\345\274\217\344\270\213\344\270\215\351\234\200\350\246\201iv</p></body></html>", nullptr));
        show->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ParaDialog: public Ui_ParaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARADIALOG_H
