#include "Manager.h"

using namespace GridWorld;

Manager::Manager()
{
    _agent = new Agent();
    _env = new Environment();
}

Manager::~Manager()
{
   _env->~Environment();
   _agent->~Agent();
}

void Manager::TryMoveAgent()
{
    auto moving = _agent->RandomMove();

    TryConcreteMoveAgent(moving);
}

void Manager::TryConcreteMoveAgent(MoveType type)
{
    auto xIncr = 0;
    auto yIncr = 0;

    switch (type)
    {
    case MoveType::Up:
        yIncr = -1;
        break;
    case MoveType::Down:
        yIncr = 1;
        break;
    case MoveType::Left:
        xIncr = -1;
        break;
    case MoveType::Right:
        xIncr = 1;
        break;
    default:
        throw new runtime_error("Undefined MoveType");
        break;
    }

    if(CheckMagicCells()) return;

    if (CheckNewCoordinates(xIncr, yIncr))
    {
        _agent->SetCoordinates(_agent->GetX() + xIncr, _agent->GetY() + yIncr);
    }
    else
    {
        _currentReward += _punishment;
    }
        
}

void Manager::PrintCurrentState()
{
    cout << endl;

    for (int i = 0; i < _env->GetCols(); i++)
    {
        for (int j = 0; j < _env->GetRows(); j++)
        {
            if(i == _agent->GetY() && j == _agent->GetX())
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }

    cout << endl;
}

void Manager::PrintCurrentReward()
{
    cout << "Current reward : " << _currentReward << endl;
}

bool Manager::CheckNewCoordinates(int xIncr, int yIncr)
{
    if(_agent->GetX() + xIncr < 0 || _agent->GetX() + xIncr > _env->GetRows()-1)
        return false;
    else if(_agent->GetY() + yIncr < 0 || _agent->GetY() + yIncr > _env->GetCols()-1)
        return false;
    else 
        return true;
}

bool Manager::CheckMagicCells()
{
    if(MagicCells.empty())
        return false;

    for(auto &cell : MagicCells)
    {
        if (cell == _agent)
        {
            _agent->SetCoordinates(cell.GetXDest(), cell.GetYDest());
            _currentReward += cell.GetReward();

            return true;
        }
    }

    return false;
}
