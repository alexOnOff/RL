#include "Manager.h"

using namespace Parking;
using namespace std;

Manager::Manager()
{
    _firstOffice = new Office(3,3);
    _secondOffice = new Office(4,2);
    _jack = new Jack();    

    _stateValues.resize(1);
    _stateValues.back().resize(_firstOffice->GetCapacity());

    for (int i = 0; i < _firstOffice->GetCapacity(); i++)
    {
        _stateValues.back()[i].resize(_secondOffice->GetCapacity());
        
        for (int j = 0; j < _secondOffice->GetCapacity(); j++)
        {
            _stateValues.back()[i][j] = 0;
        }
    }
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
    _jack->GoTrack(_stateValues.back(), _firstOffice, _secondOffice);
}

void Manager::PrintLastStateValues()
{
    cout << endl << "Values:" << endl;
    for (auto line: _stateValues.back())
    {
        for (auto value: line)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

