# Second

## a

```cpp
void f1(int A[], int n) {
    insertionSort(A, n);
    for(int i = n - 1; i >= 0; i--) {
        binarySearch(A, n, A[i]);
    }
}
```

```plaintext
O - n^2
Ω - n \* log(n)
Θ - NOPE
```

## b

```cpp
int g(int i, int n) {
    int zbroj = 0;
    if (n <= 2)
        return 1;

    for (int k = i; k < n; k++) {
        zbroj += k;
        cout << zbroj << " " << endl;

    }
    return zbroj;
}
void f2(int n) { // n >= 0
    for (int i = 1; i <= n; i *= 2)
        cout << g(i, n) << endl;
}
```

```plaintext
O - n \* log(n)
Ω - n \* log(n)
Θ - n \* log(n)
```
