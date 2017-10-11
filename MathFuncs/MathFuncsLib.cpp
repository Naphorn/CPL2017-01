// MathFuncsLib.cpp
// compile with: cl /cEHsc MathFuncsLib.cpp
// post-build command: lib MathFuncsLib.obj

#include "MathFuncsLib.h"
#include <stdexcept>

using namespace std;

namespace MathFuncs
{
    double MyMathFuncs::Add(double a, double b)
    {
        return a + b;
    }

    double MyMathFuncs::Subtract(double a, double b)
    {
        return a - b;
    }

    double MyMathFuncs::Multiply(double a, double b)
    {
        return a * b;
    }

    double MyMathFuncs::Divide(double a, double b)
    {
        return a / b;
    }
}
