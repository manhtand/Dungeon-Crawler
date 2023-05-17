#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GUI/graphicalui.h"

MainWindow::MainWindow(GraphicalUI* p_graphicalui, QWidget *parent) : QMainWindow(parent), graphicalui(p_graphicalui), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initBloodyFrame();
    initControls();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initBloodyFrame()
{
    ui->bloodyFrame->setPixmap(*graphicalui->getTexture("tex_bloody_frame"));
}

void MainWindow::initControls(){

    int directions[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    string textures[9] =
    {
        "tex_arrow_up_left",
        "tex_arrow_up",
        "tex_arrow_up_right",

        "tex_arrow_left",
        "tex_arrow_skip",
        "tex_arrow_right",

        "tex_arrow_down_left",
        "tex_arrow_down",
        "tex_arrow_down_right",
    };

    int maxRows = 3, maxCols = 3, textureCounter = 0;

    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxCols; j++, textureCounter++)
        {
            ControlButton* tmpButton = new ControlButton(directions[textureCounter], graphicalui);

            tmpButton->setIcon(*graphicalui->getTexture(textures[textureCounter]));
            tmpButton->setIconSize(QSize(64,64));
            tmpButton->setStyleSheet("border:none");

            ui->gridLayoutConrtols->addWidget(tmpButton, i, j, Qt::AlignCenter);
        }
    }
}

void MainWindow::changeTexture(int row, int col, QPixmap* pixmap)
{
    QLabel* tempLabel = qobject_cast<QLabel*>(ui->gridLayoutLevel->itemAtPosition(row, col)->widget());
    tempLabel->setPixmap(*pixmap);
}

void MainWindow::initLevel(Level* p_level)
{
    for (int i = 0; i < p_level->getRowCount(); i++)
    {
        for (int j = 0; j < p_level->getColCount(); j++)
        {
            QLabel* tempLabel = new QLabel();
            ui->gridLayoutLevel->addWidget(tempLabel, i, j, Qt::AlignCenter);
        }
    }
}

void MainWindow::initLevelTextures(Level* p_level)
{
    for (int i = 0; i < p_level->getRowCount(); i++)
    {
        for (int j = 0; j < p_level->getColCount(); j++)
        {
            QLabel* tempLabel = qobject_cast<QLabel*>(ui->gridLayoutLevel->itemAtPosition(i, j)->widget());
            string texture = "tex_floor" + to_string( rand() % 5 + 1 );

            tempLabel->setPixmap(*graphicalui->getTexture( texture ));
            tempLabel->setScaledContents(true);

            p_level->getTile(i, j)->setTexture(texture);
        }
    }
}

void MainWindow::updateHpBar(int hp, int maxHP)
{
    ui->progressBarHp->setMaximum(maxHP);
    ui->progressBarHp->setMinimum(0);
    ui->progressBarHp->setValue(hp);
}

void MainWindow::printStrengthLabel(int strength)
{
    ui->labelStrength->setText(QString::fromStdString("Strength: " + to_string(strength)));
}
