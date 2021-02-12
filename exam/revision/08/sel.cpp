#include <iostream>
#define N 10

// here:
// get smallest element
// put it first
// index to element after
// jp here

int main(void) {
    int arr[N] = {3, 5, 2, 1, 9, 4, 8, 7, 6, 0};
    for (int i = 0; i < N; i++) {
        int min = i;

        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }

    for (int i = 0; i < N; i++) {
        std::cout << arr[i];

        if (i < N - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
