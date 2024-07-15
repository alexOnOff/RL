#include "LeftRightChoise.h"

LeftRight::Graph::Graph()
{
    iters = 10000;
}

LeftRight::Graph::~Graph()
{
}

void LeftRight::Graph::Move(Choise choise)
{
    switch (choise)
    {
    case Choise::Left:
        GoLeft();
        break;
    case Choise::Right:
        GoRight();
        break;
    default:
        break;
    }
}

void LeftRight::Graph::GoLeft()
{
    float gamma = 0.0f;

    while (gamma <= 1.1f)
    {
        double sum = 0;
        for (int i = 0; i < iters; i++)
        {
            if (i % 2 == 0)
            {
                sum += 1 * pow(gamma, i);
            }
        }

        std::cout << "gamma = " << gamma << " Cost = " << sum << std::endl;
        
        gamma += 0.1f;
    }
}

void LeftRight::Graph::GoRight()
{
    float gamma = 0.0f;

    while (gamma <= 1.1f)
    {
        double sum = 0;
        for (int i = 0; i < iters; i++)
        {
            if (i % 2)
            {
                sum += 2 * pow(gamma, i);
            }
        }

        std::cout << "gamma = " << gamma << " Cost = " << sum << std::endl;

        gamma += 0.1f;
    }
}
