#include "Manager.h"

using namespace BlackJack;

Manager::Manager()
{
    _player = new Player();
    _dealer = new Player();
    _gen = std::mt19937(time(NULL));

    auto cols = _player->MaxScore - _player->MinScore;
    auto rows = _dealer->MaxScore - _dealer->MinScore;

    Service::InitMatrix(_stateValues, 0.0f, rows, cols);
}

Manager::~Manager()
{
    _player->~Player();
    _dealer->~Player();
}

void Manager::Study(uint16_t episodes)
{
    for (int i = 0; i < episodes; i++)
    {
        GenerateEpisode();
    }
}

int16_t Manager::GenerateEpisode()
{
    // start state

    auto startScorePlayer = _gen() % 10 + 12;
    auto startScoreDealer = _gen() % 10 + 12;

    _player->SetScore(startScorePlayer);
    _dealer->SetScore(startScoreDealer);

    if(_player->IsWin() && _dealer->IsWin()) return _PushReward;
    else if(_player->IsWin()) return _WinReward;
    else if(_dealer->IsWin()) return _LoseReward;

    // player steps

    if (_player->ShouldTake())
    {
        int16_t newCard;


        // TODO: PLATING ACE?
        if(_player->IsPlayingAce())
            newCard = _gen() % 10 + 2;
        else
            newCard = _gen() % 10 + 1;



    }

    // dealer steps



}
