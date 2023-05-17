#include "lootchest.h"
#include "QtWidgets/qlabel.h"

Lootchest::Lootchest(int p_row, int p_col) : Tile(p_row, p_col, "K")
{

}

Tile *Lootchest::onEnter(Tile *fromTile, Character *who)
{
    QLabel* endgame = new QLabel;
    endgame->setText("Gewonnen!");
    endgame->setWindowTitle("Glückwunsch");
    endgame->setAlignment(Qt::AlignCenter);
    endgame->setFixedSize(211, 91);
    endgame->show();

    return this;
}

Tile *Lootchest::onLeave(Tile *destTile, Character *who)
{
    return this;
}
