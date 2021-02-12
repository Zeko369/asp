#include <iostream>
#include <math.h>

#define N 12
#define M 4

#define FIRST_POW 16777216

int hashFn(char *arr) {
    int hash = 0;

    for (int i = 0; i < M; i++) {
        hash += pow(256, M - i - 1) * *(arr + i);
    }

    return hash;
}

void checkIfOk(char *arr, char *pat, int from) {
    bool yes = true;
    for (int i = 0; i < M; i++) {
        if (arr[i + from] != pat[i]) {
            yes = false;
            break;
        }
    }

    if (yes) {
        std::cout << from << std::endl;
    }
}

int main() {
    char arr[N + 1] = "ababbaabaaab";
    char pat[M + 1] = "abaa";

    int hash = hashFn(pat);
    int slidingHash = hashFn(arr);

    if (hash == slidingHash) {
        checkIfOk(arr, pat, 0);
    }

    for (int i = 1; i < N - 3; i++) {
        slidingHash -= arr[i - 1] * FIRST_POW;
        slidingHash *= 256;
        slidingHash += arr[i + 3];

        if (slidingHash == hash) {
            checkIfOk(arr, pat, i);
        }
    }

    return 0;
}
