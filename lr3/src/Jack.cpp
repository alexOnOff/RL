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

void Jack::GoTrack(vector<vector<int16_t>> states, Office* officeFirst, Office* officeSecond)
{
    auto value = states[officeFirst->GetCarNumber()][officeSecond->GetCarNumber()];

    if (value < 0)
    {
        TrackCars(officeSecond, officeFirst, abs(value));
    }
    else if (value > 0)
    {
        TrackCars(officeFirst, officeSecond, abs(value));
    }
}

