#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <tile/tile.h>
#include <tile/pit.h>
#include <GUI/controlbutton.h>
#include <QPushButton>
#include <map>
#include <level.h>

namespace Ui { class MainWindow; }

class GraphicalUI;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(GraphicalUI*, QWidget* parent = nullptr);
    ~MainWindow();

    void initLevel(Level*);
    void initLevelTextures(Level*);
    void changeTexture(int, int, QPixmap*);
    QPixmap* getTileTexture(int, int);

    void updateHpBar(int, int);
    void printStrengthLabel(int);
    void initBloodyFrame();

private:
    GraphicalUI* graphicalui;
    Ui::MainWindow* ui;

    void initControls();
    void initLevel();

    map<Character*, QLabel*> characterLabels;
};

#endif // MAINWINDOW_H
