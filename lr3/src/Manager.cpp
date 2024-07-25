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
    //vector<vector<float>> newValues;

    //newValues.resize(_firstOffice->GetCapacity() + 1);


    for (int i = 0; i < _firstOffice->GetCapacity() + 1 ; i++)
    {
        //newValues[i].resize(_secondOffice->GetCapacity() + 1);

        for (int j = 0; j < _secondOffice->GetCapacity() + 1; j++)
        {
            _firstOffice->SetCarNumber(i);
            _secondOffice->SetCarNumber(j);

            // Scoring of strategy
            _stateValues.back()[i][j] = NewStateValue(i, j);
            //newValues[i][j] = NewStateValue(i, j);
            cout << _stateValues.back()[i][j] << " ";
        }
        cout << endl;
    }

    //_stateValues.push_back(newValues);

    //Service::PrintLastMatrix(_rewards);
}

float Parking::Manager::NewStateValue(uint16_t curFirstOfficeState, uint16_t curSecondOfficeState)
{
    float sum = 0; 

    // night track
    //uint16_t trackedCars = _jack->GoTrack(_politics.back(), _firstOffice, _secondOffice);
    float rewardForNight = _politics.back()[curFirstOfficeState][curSecondOfficeState] * _jack->GetTrackCost();

    //auto firstMainState = _firstOffice->GetCarNumber();
    //auto secondMainState = _secondOffice->GetCarNumber();

    auto firstMainState = std::min<int16_t>(curFirstOfficeState - _politics.back()[curFirstOfficeState][curSecondOfficeState], _firstOffice->GetCapacity());
    auto secondMainState = std::min<int16_t>(curSecondOfficeState + _politics.back()[curFirstOfficeState][curSecondOfficeState], _secondOffice->GetCapacity());

    for (int16_t firstRent = 0; firstRent < _firstOffice->GetCapacity() + 1; firstRent++)
    {
        for (int16_t secondRent = 0; secondRent < _secondOffice->GetCapacity() + 1; secondRent++)
        {
            auto newStateFirst = firstMainState;
            auto newStateSecond = secondMainState;

            // take probs
            float firstProbRent = _firstOffice->GetProbabilityRent(firstRent);
            float secondProbRent = _secondOffice->GetProbabilityRent(secondRent);

            //_firstOffice->SetCarNumber(firstMainState);
            //_secondOffice->SetCarNumber(secondMainState);

            // rent cars
            int16_t rentedFirst = std::min<int16_t>(newStateFirst, firstRent);
            int16_t rentedSecond = std::min<int16_t>(newStateSecond, secondRent);

            // sum reward
            float rewardForDay = (rentedFirst + rentedSecond) * _Reward;
            
            newStateFirst =- rentedFirst;
            newStateSecond =- rentedSecond;

            
            for (int16_t firstReturn = 0; firstReturn < _firstOffice->GetCapacity() + 1; firstReturn++)
            {
                for (int16_t secondReturn = 0; secondReturn < _secondOffice->GetCapacity() + 1; secondReturn++)
                {
                    float firstProbReturn = _firstOffice->GetProbabilityReturn(firstReturn);
                    float secondProbReturn = _secondOffice->GetProbabilityReturn(secondReturn);


                    auto newStateFirstRet = std::min<int16_t>(newStateFirst + firstReturn, _firstOffice->GetCapacity());
                    auto newStateSecondRet = std::min<int16_t>(newStateSecond + secondReturn, _secondOffice->GetCapacity());


                    // отрицательное значение не понятно почему
                    if (newStateFirstRet < 0 || newStateSecondRet < 0)
                    {
                        //cout << "ERROR" << endl;
                        newStateFirstRet = 0;
                        newStateSecondRet = 0;
                    }
                    //// set current state
                    //_firstOffice->SetCarNumber(newStateFirst);
                    //_secondOffice->SetCarNumber(newStateSecond);

                    //// return cars
                    //_firstOffice->Return(firstReturn);
                    //_secondOffice->Return(secondReturn);
                    
                    sum += (firstProbRent * firstProbReturn * secondProbRent * secondProbReturn) * 
                        ((rewardForDay + rewardForNight) + _Gamma * 
                            _stateValues.back()[newStateFirstRet][newStateSecondRet]);

                }
            }
        }
    }

    return sum;
}

