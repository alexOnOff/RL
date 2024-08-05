#include <iostream>

namespace BlackJack
{
    class Dealer
    {
    public:
        Dealer();
        ~Dealer();

        const uint16_t MinScore = 1;
        const uint16_t MaxScore = 10;

        uint16_t GetScore();
    private:
        uint16_t _score;
    };
}