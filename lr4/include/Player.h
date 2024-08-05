#include <iostream>

namespace BlackJack
{
    class Player
    {
    public:
        Player();
        ~Player();

        const uint16_t MinScore = 12;
        const uint16_t MaxScore = 21;

        uint16_t GetScore();
        bool IsPlayingAce();

    private:
        uint16_t _score;
        bool _playingAce;
    };
}