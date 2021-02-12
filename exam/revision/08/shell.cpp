#include <iostream>
#define N 8

void print(int *a) {
    for (int i = 0; i < N; i++)
        printf("%d ", *(a + i));
    printf("\n");
}

void shell(int *arr, int size) {
    for (int step = size / 2; step > 0; step /= 2) {
        printf("step %d\n", step);
        for (int i = step; i < size; i++) {
            int tmp = arr[i];
            int j;

            for (j = i; j >= step && arr[j - step] > tmp; j -= step) {
                arr[j] = arr[j - step];
            }

            arr[j] = tmp;
        }
    }
}

int main() {
    int arr[N] = {6, 4, 1, 8, 7, 5, 3, 2};
    print(arr);

    shell(arr, N);

    print(arr);

    return 0;
}
