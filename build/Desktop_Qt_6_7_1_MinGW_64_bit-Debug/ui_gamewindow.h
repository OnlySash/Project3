/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamewindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *gamewindow)
    {
        if (gamewindow->objectName().isEmpty())
            gamewindow->setObjectName("gamewindow");
        gamewindow->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Hunter.png"), QSize(), QIcon::Normal, QIcon::Off);
        gamewindow->setWindowIcon(icon);
        label = new QLabel(gamewindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        label_2 = new QLabel(gamewindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 35, 35));
        label_3 = new QLabel(gamewindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(35, 0, 35, 35));

        retranslateUi(gamewindow);

        QMetaObject::connectSlotsByName(gamewindow);
    } // setupUi

    void retranslateUi(QWidget *gamewindow)
    {
        gamewindow->setWindowTitle(QCoreApplication::translate("gamewindow", "Maze Knights Game Window", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gamewindow: public Ui_gamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
