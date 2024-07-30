#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Service.h"
#include <iomanip>


class PlayerTask
{
public:
    PlayerTask();
    ~PlayerTask();

    void Study();
    void PrintValues();
    void PrintPolicy();
    void WriteValuesInFile(std::string);

private:
    const uint16_t _Bank = 100;
    uint16_t _reward = 1;
    const float _EagleProb = 0.4f;
    const float _Theta = 0.001f;
    std::vector<float> _values;
    std::vector<uint16_t> _politics;
    std::vector<std::vector<float>> _totalValues;

    const float _MinP = 0.15f;
    const float _MaxP = 0.65f;
    const float _Step = 0.01f;
};

