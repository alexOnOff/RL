#include "Player.h"

using namespace BlackJack;

Player::Player()
{
    _score = 0;
    _playingAce = true;
    _maxTakeScore = 18;
    InitDefaultPolicy(_maxTakeScore);
}

BlackJack::Player::Player(uint16_t policy)
{
    _score = 0;
    _playingAce = false;
    _maxTakeScore = policy;
    InitDefaultPolicy(policy);
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

void Player::SetScore(uint16_t score)
{
    _score = score;
}

void BlackJack::Player::AddScore(uint16_t score)
{
    _score += score;
}

bool Player::ShouldTake()
{
    return _policy[_score - MinScore];
}

bool Player::IsWin()
{
    return _score == MaxScore;
}

bool BlackJack::Player::IsLose()
{
    return _score > MaxScore;
}


void Player::InitDefaultPolicy(uint16_t maxTake)
{
    _policy.resize(MaxScore - MinScore);

    for (int i = 0; i < _policy.size(); i++)
    {
        _policy[i] = (i <= maxTake - MinScore) ? true: false;
    }
}
