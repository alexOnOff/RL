#include "Service.h"

int64_t Service::Factorial(int16_t n)
{
    int64_t f = 1, i;
    for (i = 2; i <= n; ++i)
    {
        f = f * i;
    }
    return f;
}

float Service::PoissonDistribution(int lambda, int n)
{
    return exp(-lambda)*pow(lambda, n)/ Service::Factorial(n);
}