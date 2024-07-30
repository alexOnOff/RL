#include "PlayerTask.h"

PlayerTask::PlayerTask()
{
    _values = std::vector<float>(_Bank+1);
    _politics = std::vector<uint16_t>(_Bank + 1);

    int size = (int)((_MaxP - _MinP) / _Step) + 1;
    Service::InitMatrix(_totalValues,0.0f, size, _Bank);
    
    for (int i = 0; i < _Bank; i++)
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
    int iter = 0;

    for (float p = _MinP; p <= _MaxP; p += _Step)
    {
        while (true)
        {
            maxAbs = 0.0f;

            for (int i = 1; i < _Bank; i++)
            {
                float newValue = 0;
                float maxValue = 0.0f;
                float prevValue;


                for (int j = 0; j < std::min(i + 1, _Bank - i + 1); j++)
                {
                    _reward = (i + j == _Bank) ? 1 : 0;
                    newValue = p * (_reward + _values[i + j]);
                    newValue += ((1 - p) * _values[i - j]);

                    if (newValue >= maxValue)
                    {
                        maxValue = newValue;
                        _politics[i] = j;
                    }

                }

                prevValue = _values[i];
                _values[i] = maxValue;
                _totalValues[iter][i] = maxValue;

                if (maxAbs < std::abs(prevValue - _values[i]))
                    maxAbs = std::abs(prevValue - _values[i]);

            }

            //PrintValues();

            if (maxAbs < _Theta)
                break;
        }

        //auto copy = _values.data();
        //_totalValues.push_back(copy);
        iter++;
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
    std::ofstream out;
    out.open(filename);


    if (out.is_open())
    {

        for (float i = _MinP; i <= _MaxP; i += _Step)
        {
            out << std::setprecision(2) <<  i << ',';
        }

        //out << endl;

        for (int i = 0; i < _Bank; i++)
        {
            int j = 0;
            out << endl;
            for (float iter = _MinP; iter <= _MaxP; iter += _Step)
            {
                out << std::setprecision(6) << _totalValues[j][i] << ',';
                j++;
            }
        }
    }

    out.close();
}
