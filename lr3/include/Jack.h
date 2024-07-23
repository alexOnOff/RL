#pragma once
#include <iostream>
#include "Office.h"

using namespace std;

namespace Parking
{
    class Jack
    {
    public:
        Jack();
        ~Jack();

        int16_t AddCash(int16_t);
        int16_t PayCash(int16_t);
        int16_t GetCash();
        uint16_t GetTrackCost();
        uint16_t TrackCars(Office* from, Office* to, uint16_t num);
        uint16_t GoTrack(vector<vector<int16_t>> states, Office* officeFirst, Office* officeSecond);
        

    private:
        int16_t _cash = 0;
        const uint16_t _TrackCost = 2;
        const uint16_t _MaxTrack = 5;
        
    };
}