#include <iostream>

int fib(int n) {
    if (n < 2) {
        return 1;
    }

    int *tmp = new int(n);

    tmp[0] = 1;
    tmp[1] = 1;

    delete tmp;

    for (int i = 2; i <= n; i++) {
        tmp[i] = tmp[i - 1] + tmp[i - 2];
    }

    return tmp[n];
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        std::cout << fib(i) << std::endl;
    }

    return 0;
}