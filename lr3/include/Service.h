#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace Service {

    int64_t Factorial(int16_t n);
    float PoissonDistribution(int lambda, int n);

    template<typename T> void InitVectorOfMatrix(vector<vector<vector<T>>>& table, T value, uint16_t rows, uint16_t cols)
    {
        table.resize(1);
        table.back().resize(rows + 1);

        for (int i = 0; i < rows + 1; i++)
        {
            table.back()[i].resize(cols + 1);

            for (int j = 0; j < cols + 1; j++)
            {
                table.back()[i][j] = value;
            }
        }
    }

    template<typename T> void PrintLastMatrix(vector<vector<vector<T>>>& table)
    {
        for (auto line : table.back())
        {
            for (auto value : line)
            {
                cout << value << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}