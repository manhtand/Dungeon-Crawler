#ifndef DOOR_H
#define DOOR_H

#include <tile/tile.h>
#include <passive.h>

class Door : public Tile, public Passive
{
public:
    Door(int, int, int);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    void notify(Active*) override;

    string getTexture() override;

    bool getIsOpen();
    int getType();

private:
    bool isOpen;
    int type;
    const string openedTextur = "/";
    const string closedTextur = "X";
    const string characterOnDoor = "C";
};

#endif // DOOR_H
