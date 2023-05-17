#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H

#include <QPushButton>

class GraphicalUI;
class ControlButton : public QPushButton
{
public:
    ControlButton(int, GraphicalUI*);

public slots:
    void setDirection();

private:
    int direction;
    GraphicalUI* gui;
};

#endif // CONTROLBUTTON_H
