#include <iostream>
#include "Manager.h"

using namespace BlackJack;
using namespace std;

int main()
{
    Manager* manager = new Manager();
    manager->Study(10000);
    manager->PrintValues();
    manager->SaveResults();
    
    return 0;
}