#include <cmath>

const double EPSILON = 0.00001;

bool equal(double a, double b)
{
    return(std::abs(a-b) < EPSILON);
}
