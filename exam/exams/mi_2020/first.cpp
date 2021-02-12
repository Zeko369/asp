#include <iostream>
#include <stdio.h>

void print(int a, int b) {
    if (a == NULL) {
        std::cout << "- " << b << " " << b << std::endl;
    } else if (b == NULL) {
        std::cout << a << " - " << a << std::endl;
    } else {
        std::cout << a << " " << b << " " << std::max(a, b) << std::endl;
    }
}

void func(int a[], int n, int b[], int m) {
    if (n <= 0 && m <= 0) {
        return;
    }

    if (n < m) {
        print(NULL, b[m - 1]);
        func(a, n, b, m - 1);
    } else if (n > m) {
        print(a[n - 1], NULL);
        func(a, n - 1, b, m);
    } else {
        print(a[n - 1], b[m - 1]);
        func(a, n - 1, b, m - 1);
    }
}

int main() {
    int arr1[] = {2, 4, 1, 3};
    int arr2[] = {4, 4, 8};

    func(arr1, 4, arr2, 3);
}
