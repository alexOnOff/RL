#include "EpisodeHistory.h"

using namespace BlackJack;


EpisodeHistory::EpisodeHistory()
{
    _steps = 0;
}

EpisodeHistory::~EpisodeHistory()
{
}

void EpisodeHistory::Clear()
{
    _playerScores.clear();
    _dealerScores.clear();
    _actions.clear();
    _rewards.clear();
    _steps = 0;
}

void EpisodeHistory::AddState(uint16_t playerScore, uint16_t dealerScore)
{
    _playerScores.push_back(playerScore);
    _dealerScores.push_back(dealerScore);
}

void EpisodeHistory::AddAction(bool action)
{
    _actions.push_back(action);
}

void EpisodeHistory::AddReward(int16_t reward)
{
    _rewards.push_back(reward);
}

void EpisodeHistory::AddStartState(uint16_t playerScore, uint16_t dealerScore, bool action)
{
    _playerScores.push_back(playerScore);
    _dealerScores.push_back(dealerScore);
    _actions.push_back(action);
}

void EpisodeHistory::AddStep(uint16_t playerScore, uint16_t dealerScore, bool action, int16_t reward)
{
    _rewards.push_back(reward);
    _actions.push_back(action);
    _playerScores.push_back(playerScore);
    _dealerScores.push_back(dealerScore);
    _steps++;
}

void EpisodeHistory::PrintInfo()
{
    cout << endl << "========== HISTORY ===========" << endl;
    for (int i = 0; i < _steps; i++)
    {
        cout << "State: " << _playerScores[i] << "-" << _dealerScores[i] << "\t\t Action: " << _actions[i]
            << "\t\t Reward: " << _rewards[i] << endl;
    }
}

int16_t EpisodeHistory::GetReward(uint16_t index)
{
    return _rewards[index];
}

uint16_t BlackJack::EpisodeHistory::GetPlayerScore(uint16_t index)
{
    return _playerScores[index];
}

uint16_t BlackJack::EpisodeHistory::GetDealerScore(uint16_t index)
{
    return _dealerScores[index];
}

uint16_t BlackJack::EpisodeHistory::GetSteps()
{
    return _steps;
}

