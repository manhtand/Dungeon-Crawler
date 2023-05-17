#ifndef GUARDCONTROLLER_H
#define GUARDCONTROLLER_H

#include <vector>
using namespace std;

#include <controller/controller.h>

class GuardController : public Controller
{
public:
    GuardController(vector<int>);
    ~GuardController();
    int move() override;
    void incrementLastMove();

private:
    vector<int> moves;
    size_t lastMove;
};

#endif // GUARDCONTROLLER_H
