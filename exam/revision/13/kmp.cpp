#include <stdio.h>

#define M 4
#define N 12

int main() {
    char arr[N + 1] = "ababbaabaaab";
    char pat[M + 1] = "abaa";

    // preprocess
    int len = 0;
    int lps[M];
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i++] = len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }

    // find
    i = 0;
    int j = 0;

    while (i < N) {
        if (pat[j] == arr[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != arr[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return 0;
}
