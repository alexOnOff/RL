#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace Service {

    template<typename T> void InitVectorOfMatrix(vector<vector<vector<T>>>& table, T value, uint16_t rows, uint16_t cols)
    {
        table.resize(1);
        table.back().resize(rows);

        for (int i = 0; i < rows; i++)
        {
            table.back()[i].resize(cols);

            for (int j = 0; j < cols; j++)
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