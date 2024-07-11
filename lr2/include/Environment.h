#pragma once
#include <iostream>

namespace GridWorld
{
    class Environment
    {
        public:
            Environment();
            Environment(int16_t);
            Environment(int16_t, int16_t);
            ~Environment();

            
            int16_t GetRows();
            int16_t GetCols();


        private:
            int16_t _rows;
            int16_t _columns;
    };
}