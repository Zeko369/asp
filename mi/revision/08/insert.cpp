#include <stdio.h>
#define N 8

void print(int *a) {
    for (int i = 0; i < N; i++) {
        printf("%d ", *(a + i));
    }

    printf("\n");
}

int main() {
    int arr[N] = {6, 4, 1, 8, 7, 5, 3, 2};

    print(arr);

    for (int i = 1; i < N; i++) {
        int tmp = arr[i];
        int j = i;

        for (j = i; j >= 1 && arr[j - 1] > tmp; j--) {
            arr[j] = arr[j - 1];
        }

        arr[j] = tmp;
    }

    print(arr);

    return 0;
}
