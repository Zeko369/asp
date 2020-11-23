#include <iostream>

class Point {
  public:
    double x;
    double y;
    void mirrorX(double xVal);
    void mirrorY(double yVal);

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    Point(double x, double y, int a) {
        this->x = x;
        this->y = y;
    }

    ~Point() { std::cout << "Deconstruct" << std::endl; }
};
