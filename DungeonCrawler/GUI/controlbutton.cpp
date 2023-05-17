#include "controlbutton.h"
#include "GUI/graphicalui.h"

ControlButton::ControlButton(int p_direction, GraphicalUI* p_gui) : direction(p_direction), gui(p_gui)
{
    Qt::Key numpadList[] = { Qt::Key_1, Qt::Key_2, Qt::Key_3, Qt::Key_4, Qt::Key_5, Qt::Key_6, Qt::Key_7, Qt::Key_8, Qt::Key_9 };
    //setShortcut(QKeySequence( numpadList[direction-1] ));
    connect(this, &ControlButton::clicked, this, &ControlButton::setDirection);
}

void ControlButton::setDirection()
{
    gui->proxyMove(direction);
}
