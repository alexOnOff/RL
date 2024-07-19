#include "Jack.h"

using namespace Parking;

Jack::Jack()
{
}

Jack::~Jack()
{
}

int16_t Jack::AddCash(int16_t reward)
{
    _cash += reward;
    return _cash;
}

int16_t Parking::Jack::PayCash(int16_t cost)
{
    _cash -= cost;
    return _cash;
}

int16_t Jack::GetCash()
{
    return _cash;
}

uint16_t Jack::TrackCars(Office* source, Office* dest, uint16_t num)
{
    int i = 0;

    for (i = 0; i < num && i < _MaxTrack; i++)
    {
        if (source->CanTake() && dest->CanReturn())
        {
            source->Take();
            dest->Return();
            _cash -= _TrackCost;
        }
    }

    return i;
}


