#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QMainWindow>
#include <map>

#include <controller/controller.h>
#include <abstractui.h>
#include <GUI/startscreen.h>
#include <GUI/mainwindow.h>

class DungeonCrawler;

class GraphicalUI : public QMainWindow, public AbstractUI, public Controller
{
    Q_OBJECT

public:
    GraphicalUI(DungeonCrawler*, QWidget* parent = nullptr);

    void draw(Level*) override;
    int move() override;

    QPixmap* getTexture(string);

    void proxyMove(int);
    string getPlayerTexture();

    void setLevelTextureInit(bool newLevelTextureInit);

    void updateHpBar(int, int);
    void printStrengthLabel(int);

public slots:
    void btnNewGame();

private:
    DungeonCrawler* dungenCrawler;

    int lastInput;
    GraphicalUI* gui;

    StartScreen* startscreen;
    MainWindow* mainwindow;

    void initTextures();
    map<string, QPixmap*> textureMap;

    bool levelCreated = false;
    void initLevel(Level*);

    vector<QPixmap*> paintedTiles;
};

#endif // GRAPHICALUI_H↔

