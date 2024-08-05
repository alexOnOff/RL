#include "Dealer.h"

using namespace BlackJack;

Dealer::Dealer()
{
    _score = 0;
}

Dealer::~Dealer()
{
}

uint16_t Dealer::GetScore()
{
    return _score;
}
