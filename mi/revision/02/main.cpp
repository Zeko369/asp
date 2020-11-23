#include <iostream>

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int a = 1;
    int b = 3;

    std::cout << a << " " << b << std::endl;

    swap(a, b);

    std::cout << a << " " << b << std::endl;

    return 0;
}