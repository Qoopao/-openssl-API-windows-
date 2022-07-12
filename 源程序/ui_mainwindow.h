/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *FileButton;
    QLabel *giflabel;
    QLabel *giflabel2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(872, 682);
        MainWindow->setMinimumSize(QSize(872, 0));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FileButton = new QPushButton(centralwidget);
        FileButton->setObjectName(QString::fromUtf8("FileButton"));
        FileButton->setGeometry(QRect(350, 250, 151, 151));
        FileButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 11pt \"Script\";\n"
"background-color:rgb(25, 25 ,112);\n"
"color:white;\n"
"border-radius:75px;\n"
"border:5px groove gray;\n"
"border-style:outset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	font: 11pt \"Script\";\n"
"background-color:rgb(0,0,0);\n"
"color:white;\n"
"border-radius:75px;\n"
"border:5px groove gray;\n"
"border-style:outset;\n"
"}"));
        giflabel = new QLabel(centralwidget);
        giflabel->setObjectName(QString::fromUtf8("giflabel"));
        giflabel->setGeometry(QRect(220, 20, 161, 171));
        giflabel->setStyleSheet(QString::fromUtf8(""));
        giflabel2 = new QLabel(centralwidget);
        giflabel2->setObjectName(QString::fromUtf8("giflabel2"));
        giflabel2->setGeometry(QRect(540, 20, 161, 171));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 872, 25));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CryptoSystem Based On OpenSSL", nullptr));
        FileButton->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        giflabel->setText(QString());
        giflabel2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
