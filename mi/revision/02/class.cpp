#include <iostream>

#include "Point.h"

int main() {
    Point a = Point(123, 123);

    std::cout << a.x << " " << a.y << std::endl;

    a.x = 10;
    a.y = 40;

    std::cout << a.x << " " << a.y << std::endl;

    a.mirrorX(10);
    std::cout << a.x << " " << a.y << std::endl;

    a.mirrorY(10);
    std::cout << a.x << " " << a.y << std::endl;

    Point *p;
    p = &a;

    std::cout << "Pointers" << std::endl;
    std::cout << p->x << " " << p->y << std::endl;

    return 0;
}
