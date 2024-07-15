#pragma once
#include <iostream>
#include <cmath>

namespace LeftRight
{
    enum Choise
    {
        Left = 0,
        Right = 1,
        Undef = 2
    };

    class Graph
    {
    public:
        Graph();
        ~Graph();

        void Move(Choise);

    private:
        void GoLeft();
        void GoRight();
        uint16_t iters;
    };
}