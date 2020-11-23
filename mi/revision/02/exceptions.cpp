#include <iostream>
#define MAX 5

// runtime_error je RuntimeException

int main(void) {
    int p[5] = {1, 2, 3, 4, 5};
    int i;

    try {
        while (1) {
            std::cin >> i;
            if (i < 0 || i >= MAX) {
                throw std::out_of_range("ArrayIndexOutOfRange");
            }

            std::cout << p[i] << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}