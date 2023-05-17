#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H

#include <controller/controller.h>

class StationaryController : public Controller
{
public:
    StationaryController();
    ~StationaryController() = default;
    int move() override;
};

#endif // STATIONARYCONTROLLER_H
