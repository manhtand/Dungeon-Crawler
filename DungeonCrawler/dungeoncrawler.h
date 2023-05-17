#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#include <level.h>
#include <GUI/graphicalui.h>
#include <helper/list.h>
#include <passive.h>

class DungeonCrawler : public Passive
{
public:
    DungeonCrawler();
    void play(int);
    bool movePossible(int, int, int);
    void notify(Active*);
    bool getLevelTextureInit() const;
    void setLevelTextureInit(bool newLevelTextureInit);
    void checkDeaths();

private:
    GraphicalUI* ui;
    Level* currentLevel;
    List levelList;
    bool levelTextureInit = false;
};

#endif // DUNGEONCRAWLER_H
