#include "guardcontroller.h"

GuardController::GuardController(vector<int> p_moves) : moves(p_moves), lastMove(0)
{

}

int GuardController::move()
{
    if (lastMove == moves.size())
    {
        lastMove = 0;
    }
    return moves.at(lastMove);
}

void GuardController::incrementLastMove()
{
    lastMove++;
}
