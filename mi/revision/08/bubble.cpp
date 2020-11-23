#include <iostream>
#define N 10

// here:
// if bigger than next
//   swap
// last is sure biggest
//   end--
// jp here

// Improvement
// If no swaps break outer for loop

int main(void) {
    int arr[N] = {3, 5, 2, 1, 9, 4, 8, 7, 6, 0};
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j + 1] < arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
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