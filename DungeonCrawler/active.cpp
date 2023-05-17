#include "active.h"

Active::Active()
{

}

void Active::attach(Passive* object)
{
    if (findPassivObject(object) < 0)
    {
        observers.push_back(object);
    }
}

void Active::detach(Passive* object)
{
    observers.erase(observers.begin() +findPassivObject(object));
}

void Active::activate()
{
    for (Passive* tempObject : observers)
    {
        tempObject->notify(this);
    }
}

int Active::findPassivObject(Passive* object)
{
    size_t size = observers.size();

    if (size == 0)
    {
        return -1;
    }

    for (size_t i = 0; i < size -1; i++)
    {
        if (observers.at(i) == object)
        {
            return i;
        }
    }
    return -1;
}
