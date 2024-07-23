#include "Manager.h"

using namespace Parking;
using namespace std;

Manager::Manager()
{
    _firstOffice = new Office(3,3);
    _secondOffice = new Office(4,2);
    _jack = new Jack();    
    _argMax = 0;

    Service::InitVectorOfMatrix(_politics, (int16_t)0, _firstOffice->GetCapacity(), _secondOffice->GetCapacity());
    Service::InitVectorOfMatrix(_rewards, (int16_t)0, _firstOffice->GetCapacity(), _secondOffice->GetCapacity());
    Service::InitVectorOfMatrix(_stateValues, 0.0f, _firstOffice->GetCapacity(), _secondOffice->GetCapacity());
}

Manager::~Manager()
{
}

void Manager::GoDay()
{
    _dayCash = 0;
    // Return cars
    _firstOffice->ReturnCarsForDay();
    _secondOffice->ReturnCarsForDay();

    // Query cars
    auto clientsFirst = _firstOffice->ClientsForDay();
    auto clientsSecond = _secondOffice->ClientsForDay();

    // Give reward
    _dayCash = (clientsFirst + clientsSecond) * _Reward;
    //auto currentCash = _jack->AddCash();

}

void Manager::GoNight()
{
    // Choose strategy
    _jack->GoTrack(_politics.back(), _firstOffice, _secondOffice);

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

void Parking::Manager::Study()
{
    vector<vector<float>> newValues;

    newValues.resize(_firstOffice->GetCapacity() + 1);

    for (int i = 0; i < _firstOffice->GetCapacity() + 1 ; i++)
    {
        newValues[i].resize(_secondOffice->GetCapacity() + 1);

        for (int j = 0; j < _secondOffice->GetCapacity() + 1; j++)
        {
            _firstOffice->SetCarNumber(i);
            _secondOffice->SetCarNumber(j);
            GoDay();
            newValues[i][j] = NewStateValue(i, j);
        }
    }

    _stateValues.push_back(newValues);
}

float Parking::Manager::NewStateValue(uint16_t curFirstOfficeState, uint16_t curSecondOfficeState)
{
    _argMax = -6;
    float sum = 0; 
    float maxValue = INT_MIN;
    float curValue;
    
    
    for (int i = -5; i < 6; i++)
    {
        
        auto trackedCars = _jack->GoTrack(_politics.back(), _firstOffice, _secondOffice);

        curValue = ((_dayCash - trackedCars * _jack->GetTrackCost()) + _Gamma * _stateValues.back()[_firstOffice->GetCarNumber()][_secondOffice->GetCarNumber()]) / 11;

        if (curValue > maxValue)
        {
            _argMax = trackedCars;
            maxValue = curValue;
            // i;

            //cout << "Update Politics" << endl;
        }

        sum += curValue;
    }
    _politics.back()[curFirstOfficeState][curSecondOfficeState] = _argMax;

    return sum;
}

