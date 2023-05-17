/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBoxControls;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayoutConrtols;
    QGroupBox *groupBoxLevel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutLevel;
    QLabel *bloodyFrame;
    QGroupBox *groupBoxStatus;
    QLabel *labelStrength;
    QProgressBar *progressBarHp;
    QMenuBar *menubar;
    QMenu *menuLol;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 749);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBoxControls = new QGroupBox(centralwidget);
        groupBoxControls->setObjectName(QString::fromUtf8("groupBoxControls"));
        groupBoxControls->setGeometry(QRect(940, 370, 211, 211));
        gridLayoutWidget_2 = new QWidget(groupBoxControls);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 211, 211));
        gridLayoutConrtols = new QGridLayout(gridLayoutWidget_2);
        gridLayoutConrtols->setObjectName(QString::fromUtf8("gridLayoutConrtols"));
        gridLayoutConrtols->setContentsMargins(0, 0, 0, 0);
        groupBoxLevel = new QGroupBox(centralwidget);
        groupBoxLevel->setObjectName(QString::fromUtf8("groupBoxLevel"));
        groupBoxLevel->setGeometry(QRect(60, 90, 821, 541));
        gridLayoutWidget = new QWidget(groupBoxLevel);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 821, 541));
        gridLayoutLevel = new QGridLayout(gridLayoutWidget);
        gridLayoutLevel->setObjectName(QString::fromUtf8("gridLayoutLevel"));
        gridLayoutLevel->setContentsMargins(0, 0, 0, 0);
        bloodyFrame = new QLabel(centralwidget);
        bloodyFrame->setObjectName(QString::fromUtf8("bloodyFrame"));
        bloodyFrame->setGeometry(QRect(0, 0, 1200, 700));
        bloodyFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        bloodyFrame->setPixmap(QPixmap(QString::fromUtf8("../textures/bloody_frame.png")));
        bloodyFrame->setScaledContents(true);
        groupBoxStatus = new QGroupBox(centralwidget);
        groupBoxStatus->setObjectName(QString::fromUtf8("groupBoxStatus"));
        groupBoxStatus->setGeometry(QRect(940, 210, 211, 91));
        groupBoxStatus->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(78, 80, 79);"));
        labelStrength = new QLabel(groupBoxStatus);
        labelStrength->setObjectName(QString::fromUtf8("labelStrength"));
        labelStrength->setGeometry(QRect(0, 10, 211, 31));
        progressBarHp = new QProgressBar(groupBoxStatus);
        progressBarHp->setObjectName(QString::fromUtf8("progressBarHp"));
        progressBarHp->setGeometry(QRect(10, 50, 191, 23));
        progressBarHp->setValue(24);
        MainWindow->setCentralWidget(centralwidget);
        bloodyFrame->raise();
        groupBoxLevel->raise();
        groupBoxControls->raise();
        groupBoxStatus->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        menuLol = new QMenu(menubar);
        menuLol->setObjectName(QString::fromUtf8("menuLol"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLol->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBoxControls->setTitle(QString());
        groupBoxLevel->setTitle(QString());
        bloodyFrame->setText(QString());
        groupBoxStatus->setTitle(QString());
        labelStrength->setText(QString());
        menuLol->setTitle(QCoreApplication::translate("MainWindow", "Lol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
