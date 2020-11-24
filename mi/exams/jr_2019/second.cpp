#include <iostream>
#define N 8

int bin(int A[], int l, int h, int x) {
    int half = l + (h - l) / 2;
    if (A[half] == x) {
        return true;
    }

    if (l == h || half == l || half == h) {
        return false;
    }

    if (A[half] % 2 == x % 2) {
        if (A[half] < x) {
            return bin(A, half, h, x);
        }

        return bin(A, l, half, x);
    } else {
        if (A[half] % 2 == 0) {
            return bin(A, l, half, x);
        }

        return bin(A, half, h, x);
    }
}

int find(int A[], int n, int x) { return bin(A, 0, n, x); }

int main(void) {
    int a[N] = {3, 7, 15, 8, 10, 12, 20, 22};

    std::cout << find(a, N, 6) << std::endl;
    std::cout << find(a, N, 3) << std::endl;
    std::cout << find(a, N, 22) << std::endl;
    std::cout << find(a, N, 20) << std::endl;
    std::cout << find(a, N, 0) << std::endl;

    return 0;
}