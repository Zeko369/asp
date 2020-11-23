#include <iostream>

struct Point {
    int x;
    int y;
};

int main(void) {
    Point p = {1, 2};
    Point r = {3};

    std::cout << p.x << " " << p.y << std::endl;
    std::cout << r.x << " " << r.y << std::endl;

    return 0;
}