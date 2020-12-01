#include "operations.hpp"
#include <exception>
#include <stdexcept>

int math::operations::sum(int a, int b)
{
    return a + b;
}

int math::operations::subtract(int a, int b)
{
    return a - b;
}

int math::operations::multiply(int a, int b)
{
    return a * b;
}

double math::operations::divide(int a, int b)
{
    if (b == 0)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    return static_cast<double>(a) / b;
}