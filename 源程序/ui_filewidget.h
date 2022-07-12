/********************************************************************************
** Form generated from reading UI file 'filewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWIDGET_H
#define UI_FILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileWidget
{
public:
    QPushButton *BackButton;
    QGraphicsView *graphicsView;
    QLabel *labeltodisplay;
    QComboBox *comboBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label;
    QPushButton *choosefile;
    QPushButton *choosefiletarget;
    QPushButton *parabutton;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;
    QLabel *label_2;
    QLabel *label_3;
    QGraphicsView *graphicsView_4;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QLabel *label_4;
    QGraphicsView *graphicsView_7;
    QLabel *label_5;
    QPushButton *privfile;
    QPushButton *sign;
    QPushButton *pem;
    QPushButton *srcfile2;
    QPushButton *checksign;
    QPushButton *srcfile;
    QPushButton *signfile;

    void setupUi(QWidget *FileWidget)
    {
        if (FileWidget->objectName().isEmpty())
            FileWidget->setObjectName(QString::fromUtf8("FileWidget"));
        FileWidget->resize(884, 735);
        BackButton = new QPushButton(FileWidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(0, 0, 81, 91));
        BackButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/pictures/face.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	\n"
"	border-image: url(:/pictures/left.png);\n"
"}"));
        graphicsView = new QGraphicsView(FileWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(120, 30, 681, 61));
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicView{\n"
"background-color:rgb(0, 0, 0)\n"
"}"));
        labeltodisplay = new QLabel(FileWidget);
        labeltodisplay->setObjectName(QString::fromUtf8("labeltodisplay"));
        labeltodisplay->setGeometry(QRect(160, 39, 581, 41));
        labeltodisplay->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(FileWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 150, 151, 41));
        QFont font;
        font.setPointSize(11);
        comboBox->setFont(font);
        radioButton = new QRadioButton(FileWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(310, 220, 161, 81));
        QFont font1;
        font1.setPointSize(16);
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(FileWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(430, 240, 120, 41));
        radioButton_2->setFont(font1);
        label = new QLabel(FileWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 130, 181, 81));
        QFont font2;
        font2.setPointSize(18);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        choosefile = new QPushButton(FileWidget);
        choosefile->setObjectName(QString::fromUtf8("choosefile"));
        choosefile->setGeometry(QRect(380, 150, 171, 41));
        choosefile->setFont(font);
        choosefiletarget = new QPushButton(FileWidget);
        choosefiletarget->setObjectName(QString::fromUtf8("choosefiletarget"));
        choosefiletarget->setGeometry(QRect(640, 150, 171, 41));
        choosefiletarget->setFont(font);
        parabutton = new QPushButton(FileWidget);
        parabutton->setObjectName(QString::fromUtf8("parabutton"));
        parabutton->setGeometry(QRect(300, 300, 221, 61));
        parabutton->setFont(font2);
        graphicsView_2 = new QGraphicsView(FileWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(0, 370, 951, 16));
        graphicsView_3 = new QGraphicsView(FileWidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(0, 130, 901, 16));
        label_2 = new QLabel(FileWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 100, 301, 20));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        label_2->setFont(font3);
        label_3 = new QLabel(FileWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 420, 301, 20));
        label_3->setFont(font3);
        graphicsView_4 = new QGraphicsView(FileWidget);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(0, 710, 911, 20));
        graphicsView_5 = new QGraphicsView(FileWidget);
        graphicsView_5->setObjectName(QString::fromUtf8("graphicsView_5"));
        graphicsView_5->setGeometry(QRect(0, 390, 971, 16));
        graphicsView_6 = new QGraphicsView(FileWidget);
        graphicsView_6->setObjectName(QString::fromUtf8("graphicsView_6"));
        graphicsView_6->setGeometry(QRect(30, 450, 341, 241));
        label_4 = new QLabel(FileWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 470, 211, 20));
        QFont font4;
        font4.setPointSize(12);
        label_4->setFont(font4);
        graphicsView_7 = new QGraphicsView(FileWidget);
        graphicsView_7->setObjectName(QString::fromUtf8("graphicsView_7"));
        graphicsView_7->setGeometry(QRect(475, 450, 351, 241));
        label_5 = new QLabel(FileWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(630, 460, 101, 20));
        label_5->setFont(font4);
        privfile = new QPushButton(FileWidget);
        privfile->setObjectName(QString::fromUtf8("privfile"));
        privfile->setGeometry(QRect(100, 510, 171, 41));
        privfile->setFont(font);
        sign = new QPushButton(FileWidget);
        sign->setObjectName(QString::fromUtf8("sign"));
        sign->setGeometry(QRect(100, 610, 171, 41));
        sign->setFont(font);
        pem = new QPushButton(FileWidget);
        pem->setObjectName(QString::fromUtf8("pem"));
        pem->setGeometry(QRect(570, 490, 171, 41));
        pem->setFont(font);
        srcfile2 = new QPushButton(FileWidget);
        srcfile2->setObjectName(QString::fromUtf8("srcfile2"));
        srcfile2->setGeometry(QRect(570, 540, 171, 41));
        srcfile2->setFont(font);
        checksign = new QPushButton(FileWidget);
        checksign->setObjectName(QString::fromUtf8("checksign"));
        checksign->setGeometry(QRect(570, 640, 171, 41));
        checksign->setFont(font);
        srcfile = new QPushButton(FileWidget);
        srcfile->setObjectName(QString::fromUtf8("srcfile"));
        srcfile->setGeometry(QRect(100, 560, 171, 41));
        srcfile->setFont(font);
        signfile = new QPushButton(FileWidget);
        signfile->setObjectName(QString::fromUtf8("signfile"));
        signfile->setGeometry(QRect(570, 590, 171, 41));
        signfile->setFont(font);

        retranslateUi(FileWidget);

        QMetaObject::connectSlotsByName(FileWidget);
    } // setupUi

    void retranslateUi(QWidget *FileWidget)
    {
        FileWidget->setWindowTitle(QCoreApplication::translate("FileWidget", "FILE", nullptr));
        BackButton->setText(QString());
        labeltodisplay->setText(QCoreApplication::translate("FileWidget", "\345\257\271\346\226\207\344\273\266\347\232\204\346\223\215\344\275\234", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("FileWidget", "AES", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("FileWidget", "DES", nullptr));

        radioButton->setText(QCoreApplication::translate("FileWidget", "\345\212\240\345\257\206", nullptr));
        radioButton_2->setText(QCoreApplication::translate("FileWidget", "\350\247\243\345\257\206", nullptr));
        label->setText(QCoreApplication::translate("FileWidget", "\345\257\206\347\240\201\347\256\227\346\263\225:", nullptr));
        choosefile->setText(QCoreApplication::translate("FileWidget", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        choosefiletarget->setText(QCoreApplication::translate("FileWidget", "\351\200\211\346\213\251\347\233\256\346\240\207\344\275\215\347\275\256", nullptr));
        parabutton->setText(QCoreApplication::translate("FileWidget", "\345\241\253\345\206\231\345\217\202\346\225\260\345\210\227\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("FileWidget", "\345\212\240\350\247\243\345\257\206\346\250\241\345\235\227", nullptr));
        label_3->setText(QCoreApplication::translate("FileWidget", "\347\255\276\345\220\215\346\250\241\345\235\227", nullptr));
        label_4->setText(QCoreApplication::translate("FileWidget", "\347\255\276\345\220\215(\350\276\223\345\207\272\345\234\250\345\220\214\350\267\257\345\276\204\344\270\213)", nullptr));
        label_5->setText(QCoreApplication::translate("FileWidget", "\351\252\214\347\255\276", nullptr));
        privfile->setText(QCoreApplication::translate("FileWidget", "\351\200\211\346\213\251\347\247\201\351\222\245\346\226\207\344\273\266", nullptr));
        sign->setText(QCoreApplication::translate("FileWidget", "execute", nullptr));
        pem->setText(QCoreApplication::translate("FileWidget", "\351\200\211\346\213\251\345\205\254\351\222\245\346\226\207\344\273\266", nullptr));
        srcfile2->setText(QCoreApplication::translate("FileWidget", "\351\234\200\350\246\201\351\252\214\350\257\201\347\255\276\345\220\215\347\232\204\346\226\207\344\273\266", nullptr));
        checksign->setText(QCoreApplication::translate("FileWidget", "execute", nullptr));
        srcfile->setText(QCoreApplication::translate("FileWidget", "\351\234\200\350\246\201\347\255\276\345\220\215\347\232\204\346\226\207\344\273\266", nullptr));
        signfile->setText(QCoreApplication::translate("FileWidget", "\351\200\211\346\213\251\347\255\276\345\220\215\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileWidget: public Ui_FileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWIDGET_H
