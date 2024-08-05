#include "Player.h"

using namespace BlackJack;

Player::Player()
{
    _score = 0;
    _playingAce = false;
}

Player::~Player()
{
}

uint16_t Player::GetScore()
{
    return _score;
}

bool Player::IsPlayingAce()
{
    return _playingAce;
}
