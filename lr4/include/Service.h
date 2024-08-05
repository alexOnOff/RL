#include <iostream>
#include <vector>

using namespace std;

namespace Service
{
    template<typename T> void InitMatrix(vector<vector<T>>& table, T value, uint16_t rows, uint16_t cols)
    {
        table.resize(rows + 1);

        for (int i = 0; i < rows + 1; i++)
        {
            table[i].resize(cols + 1);

            for (int j = 0; j < cols + 1; j++)
            {
                table[i][j] = value;
            }
        }
    }

    template<typename T> void PrintMatrix(vector<vector<T>>& table)
    {
        for (auto line : table)
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


