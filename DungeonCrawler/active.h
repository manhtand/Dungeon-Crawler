#ifndef ACTIVE_H
#define ACTIVE_H

#include <passive.h>
#include <vector>


class Active
{
public:
    Active();

    void attach(Passive*);
    void detach(Passive*);
    void activate();

private:
    std::vector<Passive*>observers;
    int findPassivObject(Passive*);
};

#endif // ACTIVE_H
