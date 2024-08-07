#include "Service.h"

float Service::AvgFloat(std::vector<float> const& v)
{
    auto sum = 0;

    for (auto item : v)
    {
        sum += item;
    }

    return (sum * 1.0f) / v.size();
}

void Service::WriteValuesInFile(vector<vector<float>>& v, std::string filename)
{
    std::ofstream out;
    out.open(filename);


    if (out.is_open())
    {
        for (int i = 0; i < v.size(); i++)
        {
            int j = 0;
            for (int j = 0; j < v[i].size(); j++)
            {
                out << std::setprecision(3) << v[j][i] << ' ';
            }
            out << endl;
        }
    }

    out.close();
}
