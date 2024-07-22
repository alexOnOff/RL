#include "Manager.h"

using namespace Parking;
using namespace std;

Manager::Manager()
{
    _firstOffice = new Office(3,3);
    _secondOffice = new Office(4,2);
    _jack = new Jack();    

    Service::InitVectorOfMatrix(_politics, (int16_t)0, _firstOffice->GetCapacity(), _secondOffice->GetCapacity());
    Service::InitVectorOfMatrix(_stateValues, 0.0f, _firstOffice->GetCapacity(), _secondOffice->GetCapacity());
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
    _jack->GoTrack(_politics.back(), _firstOffice, _secondOffice);

    //UpdateTables
    vector<vector<int16_t>> newValues;

    newValues.resize(_firstOffice->GetCapacity());

    for (int i = 0; i < _firstOffice->GetCapacity(); i++)
    {
        newValues[i].resize(_secondOffice->GetCapacity());

        for (int j = 0; j < _secondOffice->GetCapacity(); j++)
        {
            newValues[i][j] = 0;
        }
    }

    _politics.push_back(newValues);

    _dayNumber++;
}

void Manager::PrintLastStateValues()
{
    cout << endl << "Values:" << endl;
    Service::PrintLastMatrix(_stateValues);
}

void Parking::Manager::PrintLastPolitics()
{
    cout << endl << "Politics:" << endl;
    Service::PrintLastMatrix(_politics);
}

