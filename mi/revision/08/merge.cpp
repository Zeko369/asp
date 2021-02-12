#include <iostream>
#define N 8

void print(int *a) {
    for (int i = 0; i < N; i++) {
        std::cout << *(a + i) << " ";
    }

    std::cout << std::endl;
}

void mergeArr(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        mergeArr(arr, left, middle, right);
    }
}

void mergeArr2(int *arr, int *helper, int left, int mid, int right) {
    int leftEnd = mid - 1;
    int helperPos = left;
    int num = right - left + 1;

    while (left <= leftEnd && mid <= right) {
        if (arr[left] <= arr[mid]) {
            helper[helperPos++] = arr[left++];
        } else {
            helper[helperPos++] = arr[mid++];
        }
    }

    while (left <= leftEnd) {
        helper[helperPos++] = arr[left++];
    }
    while (mid <= right) {
        helper[helperPos++] = arr[mid++];
    }

    for (int i = 0; i < num; i++, right--)
        arr[right] = helper[right];
}

void mergeSort2(int *arr, int *helper, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort2(arr, helper, left, mid);
    mergeSort2(arr, helper, mid + 1, right);

    mergeArr2(arr, helper, left, mid + 1, right);
}

int main() {
    int arr[N] = {6, 4, 1, 8, 7, 5, 3, 2};

    print(arr);

    int *helper = new int[N];
    mergeSort2(arr, helper, 0, N - 1);

    print(arr);

    return 0;
}
