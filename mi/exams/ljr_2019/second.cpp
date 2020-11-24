#include <iostream>
#define N 10

int canAdd(int a[], int n, int m) {
    if (n == 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == m) {
            return 1;
        }

        if (a[i] < m) {
            if (canAdd(&(a[i + 1]), n - 1, m - a[i])) {
                return 1;
            }
        }
    }

    return 0;
}

int main(void) {
    int a[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << canAdd(a, N, 3) << std::endl;
    std::cout << canAdd(a, N, 21) << std::endl;
    std::cout << canAdd(a, N, 10000) << std::endl;

    return 0;
}