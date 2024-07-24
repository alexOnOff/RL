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

    auto i = _firstOffice->GetCarNumber();
    auto j = _secondOffice->GetCarNumber();
    // Return cars
    auto firstReturn = _firstOffice->ReturnCarsForDay();
    auto secondReturn = _secondOffice->ReturnCarsForDay();

    _firstOffice->SetCarNumber(_firstOffice->GetCarNumber() + firstReturn);
    _secondOffice->SetCarNumber(_secondOffice->GetCarNumber() + secondReturn);

    // Query cars
    auto clientsFirst = _firstOffice->ClientsForDay();
    auto clientsSecond = _secondOffice->ClientsForDay();

    // Give reward
    _dayCash = (clientsFirst + clientsSecond) * _Reward;
    _rewards.back()[i][j] = _dayCash;
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

void Parking::Manager::PrintProbabilities()
{
    cout << endl << " FIRST OFFICE RENT " << endl;

    for (int i = 0; i < _firstOffice->GetCapacity() + 1; i++)
    {
        cout << _firstOffice->GetProbabilityRent(i) << " " ;
    }

    cout << endl << " FIRST OFFICE RETURN " << endl;

    for (int i = 0; i < _firstOffice->GetCapacity() + 1; i++)
    {
        cout << _firstOffice->GetProbabilityReturn(i) << " ";
    }

    cout << endl << " SECOND OFFICE RENT " << endl;

    for (int i = 0; i < _firstOffice->GetCapacity() + 1; i++)
    {
        cout << _secondOffice->GetProbabilityRent(i) << " ";
    }

    cout << endl << " SECOND OFFICE RETURN " << endl;

    for (int i = 0; i < _firstOffice->GetCapacity() + 1; i++)
    {
        cout << _secondOffice->GetProbabilityReturn(i) << " ";
    }
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
            // Scoring of strategy

            newValues[i][j] = NewStateValue(i, j);
            //cout << newValues[i][j] << " ";
        }
        //cout << endl;
    }

    _stateValues.push_back(newValues);

    //Service::PrintLastMatrix(_rewards);
}

float Parking::Manager::NewStateValue(uint16_t curFirstOfficeState, uint16_t curSecondOfficeState)
{
    _argMax = -6;
    float sum = 0; 
    float maxValue = INT_MIN;
    float curValue;

    for (int firstRent = 0; firstRent < _firstOffice->GetCapacity() + 1; firstRent++)
    {
        for (int secondRent = 0; secondRent < _firstOffice->GetCapacity() + 1; secondRent++)
        {
            // take probs
            float firstProbRent = _firstOffice->GetProbabilityRent(firstRent);
            float secondProbRent = _secondOffice->GetProbabilityRent(secondRent);

            _firstOffice->SetCarNumber(curFirstOfficeState);
            _secondOffice->SetCarNumber(curSecondOfficeState);

            if(firstProbRent < 0.001 ||  secondProbRent < 0.001 ) continue;

            // rent cars
            uint16_t rentedFirst = _firstOffice->TryRent(firstRent);
            uint16_t rentedSecond = _secondOffice->TryRent(secondRent);

            // night track
            uint16_t trackedCars = _jack->GoTrack(_politics.back(), _firstOffice, _secondOffice);

            // sum reward
            float rewardForDay = (rentedFirst + rentedSecond) * _Reward;
            float rewardForNight = trackedCars * _jack->GetTrackCost();

            auto newStateFirst = _firstOffice->GetCarNumber();
            auto newStateSecond = _secondOffice->GetCarNumber();
            
            for (int firstReturn = 0; firstReturn < _firstOffice->GetCapacity()  + 1; firstReturn++)
            {
                for (int secondReturn = 0; secondReturn < _secondOffice->GetCapacity() + 1; secondReturn++)
                {
                    float firstProbReturn = _firstOffice->GetProbabilityReturn(firstReturn);
                    float secondProbReturn = _secondOffice->GetProbabilityReturn(secondReturn);

                    // set current state
                    _firstOffice->SetCarNumber(newStateFirst);
                    _secondOffice->SetCarNumber(newStateSecond);

                    // return cars
                    _firstOffice->Return(firstReturn);
                    _secondOffice->Return(secondReturn);

                    sum += (float)(firstProbRent * firstProbReturn * secondProbRent * secondProbReturn) * 
                        ((rewardForDay + rewardForNight) + _Gamma * 
                            _stateValues.back()[_firstOffice->GetCarNumber()][_secondOffice->GetCarNumber()]);

                }
            }
        }
    }

    return sum;
}

