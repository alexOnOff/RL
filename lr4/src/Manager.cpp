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
        EpisodeHistory* history = new EpisodeHistory();
        auto res = GenerateEpisode(history);

        if (res == 0)
        {
            cout << "Push!" << endl;
        }
        else if (res == 1)
        {
            cout << "Win!" << endl;
        }
        else
        {
            cout << "Lose!" << endl;
        }

    }
}

int16_t Manager::GenerateEpisode(EpisodeHistory* episode)
{
    // start state

    auto startScorePlayer = _gen() % 10 + 12;
    auto startScoreDealer = _gen() % 10 + 12;

    _player->SetScore(startScorePlayer);
    _dealer->SetScore(startScoreDealer);

    //cout << "Player score - " << _player->GetScore() << endl;
    //cout << "Dealer score - " << _dealer->GetScore() << endl;

    if(_player->IsWin() && _dealer->IsWin())
    {
        episode->AddStep(_player->GetScore(), _dealer->GetScore(), false, _PushReward);
        return _PushReward;
    }
    else if(_player->IsWin()) 
    {
        episode->AddStep(_player->GetScore(), _dealer->GetScore(), false, _WinReward);
        return _WinReward;
    }
    else if(_dealer->IsWin()) 
    {
        episode->AddStep(_player->GetScore(), _dealer->GetScore(), false, _LoseReward);
        return _LoseReward;
    }

    // player steps

    while (_player->ShouldTake())
    {
        int16_t newCard = _gen() % 10 + 2;
        //cout << "Player take - " << newCard << endl;

        // Check Ace
        if(_player->IsPlayingAce() && _Ace == newCard && _player->GetScore() + newCard > _BlackJack)
            newCard = 1;
                
        auto prevScore = _player->GetScore();
        _player->AddScore(newCard);
        //cout << "Player score - " << _player->GetScore() << endl;

        if (_player->IsWin())
        {
            episode->AddStep(prevScore, _dealer->GetScore(), true, _WinReward);
            return _WinReward;
        }
        else if (_player->IsLose())
        {
            episode->AddStep(prevScore, _dealer->GetScore(), true, _LoseReward);
            return _LoseReward;
        }

        //TODO: update table
        episode->AddStep(prevScore, _dealer->GetScore(), true, _PushReward);

    }

    // dealer steps
    auto prevScore = _dealer->GetScore();

    while (_dealer->ShouldTake())
    {
        int16_t newCard = _gen() % 10 + 2;
        //cout << "Dealer take - " << newCard << endl;

        
        _dealer->AddScore(newCard);

        //cout << "Dealer score - " << _dealer->GetScore() << endl;

        if (_dealer->IsWin())
        {
            episode->AddStep(_player->GetScore(), prevScore, false, _LoseReward);
            return _WinReward;
        }
        else if (_dealer->IsLose())
        {
            episode->AddStep(_player->GetScore(), prevScore, false, _WinReward);
            return _LoseReward;
        }
    }

    // Counting

    if(_player->GetScore() > _dealer->GetScore()) 
    {
        episode->AddStep(_player->GetScore(), prevScore, false, _WinReward);
        return _WinReward;
    }
    else if (_player->GetScore() < _dealer->GetScore()) 
    {
        episode->AddStep(_player->GetScore(), prevScore, false, _LoseReward);
        return _LoseReward;
    } 

    episode->AddStep(_player->GetScore(), prevScore, false, _PushReward);
    return _PushReward;
}
