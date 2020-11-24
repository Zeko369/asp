# Second

## a

```cpp
if (n <= 5) {
    g(n); /* obavlja se u Θ(n) vremenu */
}
else {
    for (i = n - 1; i > 0; i--) {
        if (A[i] - A[i - 1] < 0) {
            g(i);
        }
    }
}
```

```plaintext
O - n^2
Ω - n
Θ - NOPE
```
