#include "iostream"
#include "time.h"
#include "Manager.h"
#include "PlayerTask.h"

using namespace std;
using namespace Parking;

int main(int argc, char* argv[])
{
    //Manager* manager = new Manager();

    //manager->Study();
    //manager->PrintLastStateValues();

    // =================================================================
    // ========================== PLAYER TASK ==========================
    // =================================================================

    PlayerTask* playerTask = new PlayerTask();
    playerTask->Study();
    playerTask->PrintPolicy();

    if (argc > 1)
    {
        playerTask->WriteValuesInFile(argv[1]);
    }
    else
    {
        playerTask->WriteValuesInFile("data.txt");
    }


    return 0;
}