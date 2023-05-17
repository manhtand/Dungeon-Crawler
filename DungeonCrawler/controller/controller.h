#ifndef CONTROLLER_H
#define CONTROLLER_H


class Controller
{
public:
    Controller();
    ~Controller() = default;
    virtual int move() = 0;
};

#endif // CONTROLLER_H
