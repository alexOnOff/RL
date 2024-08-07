#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace BlackJack
{
    class EpisodeHistory
    {
    public:
        EpisodeHistory();
        ~EpisodeHistory();

        void Clear();

        void AddStartState(uint16_t, uint16_t, bool);
        void AddStep(uint16_t playerScore, uint16_t dealerScore, bool action, int16_t reward);
        void PrintInfo();

        int16_t GetReward(uint16_t index);
        uint16_t GetPlayerScore(uint16_t index);
        uint16_t GetDealerScore(uint16_t index);
        uint16_t GetSteps();



    private:
        uint16_t _steps;
        vector<uint16_t> _playerScores;
        vector<uint16_t> _dealerScores;
        vector<bool> _actions;
        vector<int16_t> _rewards;

        void AddState(uint16_t, uint16_t);
        void AddAction(bool);
        void AddReward(int16_t);
    };
}