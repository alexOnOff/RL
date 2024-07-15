#include "iostream"
#include "time.h"
#include "Manager.h"
#include "LeftRightChoise.h"

using namespace std;
using namespace GridWorld;

int main()
{
    srand(time(NULL));

    Manager* manager = new Manager();
    manager->MagicCells.push_back(MagicCell(1, 0, 1, 4, 10));
    manager->MagicCells.push_back(MagicCell(3, 0, 3, 2, 5));  

    // Проверяем выполнение уравнения Беллмана
    //cout << "=================== START ===================" << endl;
    //manager->SetStateValues5x5();
    //manager->PrintCurrentStateValues();
    //cout << "=================== STUDING ===================" << endl;
    //manager->StudyOnce();
    //manager->PrintCurrentStateValues();

    // Обучаем с 1 итерацией
    //cout << "=================== START ===================" << endl;
    //manager->PrintCurrentStateValues();
    //cout << "=================== STUDING ===================" << endl;
    //manager->Study(1);
    //manager->PrintCurrentStateValues();


    //// Обучаем с 100 итерацией
    //cout << "=================== START ===================" << endl;
    //manager->PrintCurrentStateValues();
    //cout << "=================== STUDING ===================" << endl;
    //manager->Study(100);
    //manager->PrintCurrentStateValues();

    //// Обучаем с 10000 итерацией
    //cout << "=================== START ===================" << endl;
    //manager->PrintCurrentStateValues();
    //cout << "=================== STUDING ===================" << endl;
    //manager->Study(10000);
    //manager->PrintCurrentStateValues();


    //cout << "=================== START ===================" << endl;
    //manager->PrintCurrentStateValues();
    //cout << "=================== STUDING ===================" << endl;
    //manager->StudyOptimal(10000);
    //manager->PrintCurrentStateValues();

    LeftRight::Graph* graph = new LeftRight::Graph();
    cout << "Left Rule" << endl;
    graph->Move(LeftRight::Choise::Left);
    cout << "Right Rule" << endl;
    graph->Move(LeftRight::Choise::Right);

    return 0;
}