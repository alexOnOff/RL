#include <iostream>
#include "Player.h"
#include "Service.h"
#include "Dealer.h"

namespace BlackJack
{
    class Manager
    {
    public:
        Manager();
        ~Manager();

    private:
        Player* _player;
        Dealer* _dealer;
    };
}