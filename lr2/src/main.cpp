#include "iostream"
#include "time.h"
#include "Manager.h"

using namespace std;
using namespace GridWorld;

int main()
{
    srand(time(NULL));

    Manager* manager = new Manager();

    cout << "=================== START ===================" << endl;

    manager->PrintCurrentState();
    manager->TryConcreteMoveAgent(MoveType::Down);
    manager->PrintCurrentState();
    manager->TryConcreteMoveAgent(MoveType::Down);
    manager->PrintCurrentState();
    manager->TryConcreteMoveAgent(MoveType::Down);
    manager->PrintCurrentState();
    manager->TryConcreteMoveAgent(MoveType::Down);
    manager->PrintCurrentState();
    manager->TryConcreteMoveAgent(MoveType::Down);
    manager->PrintCurrentState();
    manager->TryConcreteMoveAgent(MoveType::Down);
    
    manager->PrintCurrentState();

    return 0;
}