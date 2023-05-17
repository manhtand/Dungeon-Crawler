#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler() : ui(new GraphicalUI(this))
{
    std::string levelString = "################ "
                              "#O1.Z...#...#..O2# "
                              "#......#.G.#...# "
                              "########...#...# "
                              "#..Z.C.....X1..-2# "
                              "#....__.<..#...# "
                              "#?1...____.O2#..O1# "
                              "################ ";

    levelList.push_back(new Level(8, 16, levelString, this));

    levelString = "################ "
                  "#-1C....#......?2# "
                  "#..___<X1.....Z.# "
                  "#...?1..###X2##### "
                  "########..__...# "
                  "#......#..__.G.# "
                  "#-2.#.Z.X2..<....# "
                  "################ ";

    levelList.push_back(new Level(8, 16, levelString, this));

    levelString = "################ "
                  "#......#O1._<...# "
                  "#O1...###.___.Z.# "
                  "#..G.#O2#.......# "
                  "#-1C....###X1##### "
                  "########...Z...# "
                  "#O2..?1###......L# "
                  "################ ";

    levelList.push_back(new Level(8, 16, levelString, this));

    currentLevel = *levelList.begin();
    ui->draw(currentLevel);
    checkDeaths();
}

void DungeonCrawler::play(int p_move)
{
    Character* character = currentLevel->getPlayer();
    Tile* curTile = character->getCurTile();
    int row = curTile->getRow();
    int col = curTile->getcol();

    if (movePossible(p_move, row, col))
    {
        switch (p_move)
        {
            case 1: row--; col--; break;
            case 2: row--;        break;
            case 3: row--; col++; break;
            case 4:        col--; break;
            case 5:               break;
            case 6:        col++; break;
            case 7: row++; col--; break;
            case 8: row++;        break;
            case 9: row++; col++; break;
        }

        curTile->moveTo(currentLevel->getTile(row, col), character, this);

        for (Character* zombie : currentLevel->getCharactersList())
        {
            Tile* zombieTile = zombie->getCurTile();
            int zombieRow = zombieTile->getRow();
            int zombieCol = zombieTile->getcol();
            int zombieMove = zombie->move();

            if (movePossible(zombieMove, row, col))
            {
                switch (zombieMove)
                {
                    case 1: zombieRow--; zombieCol--; break;
                    case 2: zombieRow--;              break;
                    case 3: zombieRow--; zombieCol++; break;
                    case 4:              zombieCol--; break;
                    case 5:                           break;
                    case 6:              zombieCol++; break;
                    case 7: zombieRow++; zombieCol--; break;
                    case 8: zombieRow++;              break;
                    case 9: zombieRow++; zombieCol++; break;
                }
            }
            zombieTile->moveTo(currentLevel->getTile(zombieRow, zombieCol), zombie, this);
        }
    }
    checkDeaths();
    ui->draw(currentLevel);
}

bool DungeonCrawler::movePossible(int move, int row, int col)
{
    int rowCount = currentLevel->getRowCount();
    int colCount = currentLevel->getColCount();

    if (move <= 9 && move >= 7 && row == rowCount - 1)
    {
        return false;
    }

    if (move >= 1 && move <= 3 && row == 0)
    {
        return false;
    }

    if ((move == 1 || move == 4 || move == 7) && col == 0)
    {
        return false;
    }

    if ((move == 3 || move == 6 || move == 9) && col == colCount -1)
    {
        return false;
    }
    return true;
}

void DungeonCrawler::notify(Active* p_active)
{
    Levelchanger* test = static_cast<Levelchanger*>(p_active);
    Level* tempLevel;

    if (test->getType() == 2)
    {
        tempLevel = levelList.getNext(currentLevel);
    }
    else
    {
        tempLevel = levelList.getBefore(currentLevel);
    }

    if (tempLevel == nullptr)
    {
        return;
    }
    tempLevel->getPlayer()->setHP(currentLevel->getPlayer()->getHP());
    currentLevel = tempLevel;
    levelTextureInit = false;
}

bool DungeonCrawler::getLevelTextureInit() const
{
    return levelTextureInit;
}

void DungeonCrawler::setLevelTextureInit(bool newLevelTextureInit)
{
    levelTextureInit = newLevelTextureInit;
}

void DungeonCrawler::checkDeaths()
{
    for (int i = 0; i < currentLevel->getRowCount(); i++)
    {
        for (int j = 0; j < currentLevel->getColCount(); j++)
        {
            Tile* tempTile = currentLevel->getTile(i, j);

            if (tempTile->hasCharacter())
            {
                Character* tempChar = tempTile->getCharacter();

                if (tempChar->getHP() <= 0)
                {
                    tempTile->setCharacter(nullptr);

                    if (!tempChar->getIsZombie())
                    {
                        QLabel* endgame = new QLabel;
                        endgame->setText("Verloren!");
                        endgame->setWindowTitle("Notification");
                        endgame->setAlignment(Qt::AlignCenter);
                        endgame->setFixedSize(211, 91);
                        endgame->show();
                    }
                    currentLevel->deleteCharacter(tempChar);
                }

                if (!tempChar->getIsZombie())
                {
                    ui->updateHpBar(tempChar->getHP(), tempChar->getMaxHP());
                    ui->printStrengthLabel(tempChar->getStrength());
                }
            }
        }
    }
}
