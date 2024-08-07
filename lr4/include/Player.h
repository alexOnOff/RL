#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace BlackJack
{
    class Player
    {
    public:
        Player();
        Player(uint16_t policy);
        ~Player();

        const uint16_t MinScore = 12;
        const uint16_t MaxScore = 21;

        uint16_t GetScore();
        bool IsPlayingAce();

        void SetScore(uint16_t);
        void AddScore(uint16_t);
        bool ShouldTake();
        bool IsWin();
        bool IsLose();


    private:
        uint16_t _score;
        bool _playingAce;
        vector<bool> _policy;

        uint16_t _maxTakeScore;

        void InitDefaultPolicy(uint16_t);
    };
}