#include <iostream>
#define N 8

void print(int *a) {
    for (int i = 0; i < N; i++) {
        std::cout << *(a + i) << " ";
    }

    std::cout << std::endl;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;

            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;

    return i + 1;
}

void quick(int *arr, int low = 0, int high = N - 1) {
    if (low >= high) {
        return;
    }

    int pi = partition(arr, low, high);
    quick(arr, low, pi - 1);
    quick(arr, pi + 1, high);
}

int main() {
    int arr[N] = {6, 4, 1, 8, 7, 5, 3, 2};

    print(arr);

    quick(arr);

    print(arr);

    return 0;
}
