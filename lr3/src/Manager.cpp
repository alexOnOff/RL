#include "Manager.h"

using namespace Parking;
using namespace std;

Manager::Manager()
{
    _firstOffice = new Office(3,3);
    _secondOffice = new Office(4,2);
    _jack = new Jack();    
}

Manager::~Manager()
{
}

void Manager::GoDay()
{
    // Return cars
    _firstOffice->ReturnCarsForDay();
    _secondOffice->ReturnCarsForDay();

    // Query cars
    auto clientsFirst = _firstOffice->ClientsForDay();
    auto clientsSecond = _secondOffice->ClientsForDay();

    // Give reward
    auto currentCash = _jack->AddCash((clientsFirst + clientsSecond) * _Reward);
}

void Manager::GoNight()
{
    // Choose strategy
    auto tracks = _jack->TrackCars(_firstOffice, _secondOffice, 5);
    
}

