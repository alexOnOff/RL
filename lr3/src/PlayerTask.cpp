#include "PlayerTask.h"

PlayerTask::PlayerTask()
{
    _values = std::vector<float>(_Bank+1);
    _politics = std::vector<uint16_t>(_Bank + 1);
    
    for (int i = 0; i < _Bank + 1; i++)
    {
        _values[i] = 0;
        _politics[i] = 0;
    }
}


PlayerTask::~PlayerTask()
{
}

void PlayerTask::Study()
{
    float maxAbs = 0.0f;

    while(true)
    {
        maxAbs = 0.0f;

        for (int i = 1; i < _Bank; i++)
        {
            float newValue = 0;
            float maxValue = 0.0f;
            float prevValue;
            

            for (int j = 0; j < std::min(i + 1, _Bank - i + 1); j++)
            {
                _reward = (i+j == _Bank) ? 1 : 0;
                newValue = _EagleProb*(_reward + _values[i + j]);
                newValue += ((1 - _EagleProb) * _values[i - j]);

                if (newValue > maxValue)
                {
                    maxValue = newValue;
                    _politics[i] = j;
                }

            }

            prevValue = _values[i];
            _values[i] = maxValue;

            if(maxAbs < std::abs(prevValue - _values[i])) 
                maxAbs = std::abs(prevValue - _values[i]);
            
        }

        //PrintValues();

        if (maxAbs < _Theta)
            break;
    } 
}

void PlayerTask::PrintValues()
{
    std::cout << std::endl << "======== Values ========" << std::endl;
    for (auto value: _values)
    {
        std::cout << value << " ";
    }

    std::cout << std::endl;
}

void PlayerTask::PrintPolicy()
{
    std::cout << std::endl << "======== POLICY ========" << std::endl;
    for (auto value : _politics)
    {
        std::cout << value << " ";
    }
}

void PlayerTask::WriteValuesInFile(std::string filename)
{
    std::ofstream out;          // поток для записи
    out.open(filename);

    if (out.is_open())
    {
        for (auto value: _politics)
        {
            out << value << " ";
        }
    }
    out.close();
}
