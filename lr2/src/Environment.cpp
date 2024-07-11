#include "Environment.h"

using namespace GridWorld;

Environment::Environment()
{
    _rows = 5;
    _columns = 5;
}

Environment::Environment(int16_t size)
{
    _rows = size;
    _columns = size;
}

Environment::Environment(int16_t rows, int16_t cols)
{
    _rows = rows;
    _columns = cols;
}

Environment::~Environment()
{
}

int16_t Environment::GetRows()
{
    return _rows;
}

int16_t Environment::GetCols()
{
    return _columns;
}


