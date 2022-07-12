/********************************************************************************
** Form generated from reading UI file 'stringwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRINGWIDGET_H
#define UI_STRINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StringWidget
{
public:
    QLabel *label;
    QPushButton *BackButton;

    void setupUi(QWidget *StringWidget)
    {
        if (StringWidget->objectName().isEmpty())
            StringWidget->setObjectName(QString::fromUtf8("StringWidget"));
        StringWidget->resize(890, 589);
        label = new QLabel(StringWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 180, 401, 181));
        BackButton = new QPushButton(StringWidget);
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

        retranslateUi(StringWidget);

        QMetaObject::connectSlotsByName(StringWidget);
    } // setupUi

    void retranslateUi(QWidget *StringWidget)
    {
        StringWidget->setWindowTitle(QCoreApplication::translate("StringWidget", "Crypto For String", nullptr));
        label->setText(QCoreApplication::translate("StringWidget", "hahahah", nullptr));
        BackButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StringWidget: public Ui_StringWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRINGWIDGET_H
