#include "iostream"
#include "time.h"
#include "Manager.h"

using namespace std;
using namespace Parking;

int main()
{
    Manager* manager = new Manager();

    manager->GoDay();
    manager->GoNight();

    manager->GoDay();
    manager->GoNight();

    return 0;
}