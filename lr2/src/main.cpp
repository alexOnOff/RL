#include "iostream"
#include "time.h"
#include "Manager.h"

using namespace std;
using namespace GridWorld;

int main()
{
    srand(time(NULL));

    Manager* manager = new Manager();
    manager->MagicCells.push_back(MagicCell(1, 0, 1, 4, 10));
    manager->MagicCells.push_back(MagicCell(3, 0, 3, 2, 5));  

    cout << "=================== START ===================" << endl;

    manager->PrintCurrentStateValues();

    cout << "=================== STUDING ===================" << endl;

    manager->Study(100000);
    manager->PrintCurrentStateValues();

    return 0;
}