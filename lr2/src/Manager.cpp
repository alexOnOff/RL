#include "Manager.h"

using namespace GridWorld;

Manager::Manager()
{
    _agent = new Agent();
    _env = new Environment();
    _tempCell = new Cell();

    _stateValues.resize(_env->GetCols());
    _nextStateValues.resize(_env->GetCols());

    for (int i = 0; i < _env->GetCols(); i++)
    {
        _stateValues[i].resize(_env->GetRows());
        _nextStateValues[i].resize(_env->GetRows());
        for (int j = 0; j < _env->GetRows(); j++)
        {
            _stateValues[i][j] = 0.0f;
            _nextStateValues[i][j] = 0.0f;
        }
    }
}

Manager::~Manager()
{
   _env->~Environment();
   _agent->~Agent();
}

int16_t Manager::TryMoveAgent()
{
    auto moving = _agent->RandomMove();

    return TryConcreteMoveAgent(moving);
}

int16_t Manager::TryConcreteMoveAgent(MoveType type)
{
    auto xIncr = 0;
    auto yIncr = 0;
    auto magicReward = CheckMagicCells();

    if (magicReward) return magicReward;

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

    if (CheckNewCoordinates(xIncr, yIncr))
    {
        _agent->SetCoordinates(_agent->GetX() + xIncr, _agent->GetY() + yIncr);
        return 0;
    }
    else
    {
        return _Punishment;
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

void Manager::PrintCurrentStateValues()
{
    for (int j = 0; j < _stateValues.size(); j++)
    {
        for (int i = 0; i < _stateValues[j].size(); i++)
        {
            cout << setw(7) << roundf(_stateValues[i][j] * 100) / 100;
            //_stateValues[i][j] = _nextStateValues[i][j];
        }
        cout << endl;
    }
}

void Manager::Study(int iters)
{
    for (int i = 0; i < iters; i++)
    {
        StudyOnce();
    }
}

void Manager::StudyOnce()
{
    for (int j = 0; j < _stateValues.size(); j++)
    {
        for (int i = 0; i < _stateValues[j].size();  i++)
        {
            float k = 1.0f / (int)MoveType::Undefined; // Делим на undefind, потому что это максимальное значение enum'а
            float sum = 0.0f;

            for (int fooInt = (int)MoveType::Up; fooInt != (int)MoveType::Undefined; fooInt++)
            {
                _agent->SetCoordinates(i, j);
                int reward = TryConcreteMoveAgent((MoveType)fooInt);
                float neighbourState;
                neighbourState = _stateValues[_agent->GetX()][_agent->GetY()];
                
                sum += (reward + _Gamma * neighbourState);
            }

            _nextStateValues[i][j] = k*sum;
        }
    }

    for (int j = 0; j < _stateValues.size(); j++)
    {
        for (int i = 0; i < _stateValues[j].size(); i++)
        {
            _stateValues[i][j] = _nextStateValues[i][j];
        }
    }
}

void Manager::SetStateValues5x5()
{
    _stateValues[0][0] = 3.3f;
    _stateValues[1][0] = 8.8f;
    _stateValues[2][0] = 4.4f;
    _stateValues[3][0] = 5.3f;
    _stateValues[4][0] = 1.5f;
    _stateValues[0][1] = 1.5f;
    _stateValues[1][1] = 3.0f;
    _stateValues[2][1] = 2.3f;
    _stateValues[3][1] = 1.9f;
    _stateValues[4][1] = 0.5f; 
    _stateValues[0][2] = 0.1f;
    _stateValues[1][2] = 0.7f;
    _stateValues[2][2] = 0.7f;
    _stateValues[3][2] = 0.4f;
    _stateValues[4][2] = -0.4f;
    _stateValues[0][3] = -1.0f;
    _stateValues[1][3] = -0.4f;
    _stateValues[2][3] = -0.4f;
    _stateValues[3][3] = -0.6f;
    _stateValues[4][3] = -1.2f;
    _stateValues[0][4] = -1.9f;
    _stateValues[1][4] = -1.3f;
    _stateValues[2][4] = -1.2f;
    _stateValues[3][4] = -1.4f;
    _stateValues[4][4] = -2.0f;

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

int16_t Manager::CheckMagicCells()
{
    if(MagicCells.empty())
        return 0;

    for(auto &cell : MagicCells)
    {
        if (cell == _agent)
        {
            _agent->SetCoordinates(cell.GetXDest(), cell.GetYDest());
            return cell.GetReward();
        }
    }

    return 0;
}
