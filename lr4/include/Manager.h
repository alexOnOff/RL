#pragma once

#include <iostream>
#include "Player.h"
#include "Service.h"
#include "EpisodeHistory.h"
#include <vector>
#include <random>

using namespace std;

namespace BlackJack
{
    class Manager
    {
    public:
        Manager();
        ~Manager();

        void Study(uint16_t);
        void PrintValues();
        void SaveResults();

    private:
        bool _isFirstVisit;

        Player* _player;
        Player* _dealer;
        mt19937 _gen;

        int16_t const _WinReward = 1;
        int16_t const _LoseReward = -1;
        int16_t const _PushReward = 0;
        uint16_t const _BlackJack = 21;
        uint16_t const _MinScore = 12;
        uint16_t const _Ace = 11;

        vector<vector<float>> _stateValues;
        vector<vector<vector<float>>> _returns;

        int16_t GenerateEpisode(EpisodeHistory*);
        void Evaluate(EpisodeHistory*);

    };
}