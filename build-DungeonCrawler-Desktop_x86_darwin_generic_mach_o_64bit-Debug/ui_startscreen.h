/********************************************************************************
** Form generated from reading UI file 'startscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSCREEN_H
#define UI_STARTSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartScreen
{
public:
    QLabel *startScreenTexture;
    QPushButton *btnNewGame;

    void setupUi(QDialog *StartScreen)
    {
        if (StartScreen->objectName().isEmpty())
            StartScreen->setObjectName(QString::fromUtf8("StartScreen"));
        StartScreen->resize(1200, 700);
        startScreenTexture = new QLabel(StartScreen);
        startScreenTexture->setObjectName(QString::fromUtf8("startScreenTexture"));
        startScreenTexture->setGeometry(QRect(-10, 0, 1200, 720));
        startScreenTexture->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        startScreenTexture->setPixmap(QPixmap(QString::fromUtf8("../textures/startscreen.png")));
        startScreenTexture->setScaledContents(true);
        btnNewGame = new QPushButton(StartScreen);
        btnNewGame->setObjectName(QString::fromUtf8("btnNewGame"));
        btnNewGame->setGeometry(QRect(470, 530, 270, 200));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../textures/new_game_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewGame->setIcon(icon);
        btnNewGame->setIconSize(QSize(270, 200));

        retranslateUi(StartScreen);

        QMetaObject::connectSlotsByName(StartScreen);
    } // setupUi

    void retranslateUi(QDialog *StartScreen)
    {
        StartScreen->setWindowTitle(QCoreApplication::translate("StartScreen", "Dialog", nullptr));
        startScreenTexture->setText(QString());
        btnNewGame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartScreen: public Ui_StartScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSCREEN_H
