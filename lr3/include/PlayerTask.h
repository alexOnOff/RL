#pragma once

#include <iostream>
#include <vector>
#include <fstream>


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
};

