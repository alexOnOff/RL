#include "iostream"
#include "time.h"
#include "Manager.h"

using namespace std;
using namespace Parking;

int main()
{
    Manager* manager = new Manager();

    manager->Study();
    manager->PrintLastStateValues();

    return 0;
}