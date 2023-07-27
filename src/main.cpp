#include <iostream>
#include <algorithm>
#include <cmath>

struct Point
{
    double x;
    double y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << p.x << ',' << p.y;
    return os;
}

static double distance(const Point& p0, const Point& p1)
{
    const double term0 = p1.x - p0.x;
    const double term1 = p1.y - p0.y;
    return std::sqrt(term0 * term0 + term1 * term1);
}

static bool obtuseTriangle(double a, double b, double c)
{
    const bool case0 = (a * a) > (b * b + c * c);
    const bool case1 = (b * b) > (a * a + c * c);
    return case0 || case1;
}

double distance2Segment(const Point& p0, const Point& p1, const Point& p2)
{
    const double a = distance(p0, p1);
    const double b = distance(p0, p2);
    const double c = distance(p1, p2);

    if (obtuseTriangle(a, b, c))
        return std::min(a, b);

    const double p = (a + b + c) / 2.0;
    return 2.0 / c * std::sqrt(p * (p - a) * (p - b) * (p - c));
}

void test(const Point& p0, const Point& p1, const Point& p2, double check)
{
    std::cout << p0 << "  " << p1 << "  " << p2 << std::endl;
    const double val = distance2Segment(p0, p1, p2);
    if ((val - 0.0001) < check && (val + 0.0001) > check)
        std::cout << "OK   " << val << " == " << check << std::endl;
    else
        std::cout << "FAIL " << val << " != " << check << std::endl;
    std::cout << std::endl;
}

int main()
{
    test({ 3, 2 }, { 0, 0 }, { 5, 0 }, 2.0);
    test({ 0, 3 }, { 0, 0 }, { 5, 0 }, 3.0);
    test({ 0, -4 }, { 0, 0 }, { 5, 0 }, 4.0);
    test({ -3, 4 }, { 0, 0 }, { 5, 0 }, 5.0);
    test({ -3, 0 }, { 0, 0 }, { 5, 0 }, 3.0);
    test({ 1, 0 }, { 0, 0 }, { 5, 0 }, 0.0);
    return 0;
}
