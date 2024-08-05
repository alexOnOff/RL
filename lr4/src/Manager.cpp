#include "Manager.h"

using namespace BlackJack;

Manager::Manager()
{
    _player = new Player();
    _dealer = new Dealer();
}

Manager::~Manager()
{
    _player->~Player();
    _dealer->~Dealer();
}