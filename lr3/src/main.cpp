#include "iostream"
#include "time.h"
#include "Manager.h"


using namespace std;
using namespace Parking;

int main()
{
    Manager* manager = new Manager();

    manager->PrintLastPolitics();

   // manager->GoDay();

    manager->Study();
    manager->PrintLastPolitics();
    manager->Study();
    manager->PrintLastPolitics();
    manager->Study();
    manager->PrintLastPolitics();
    manager->Study();
    manager->PrintLastPolitics();

    //manager->Study();
    
    //manager->Study();
    //manager->Study();
    //manager->Study();
    //manager->Study();
    //manager->Study();

    //manager->GoDay();




    //manager->PrintLastPolitics();
    //manager->PrintLastPolitics();





    return 0;
}