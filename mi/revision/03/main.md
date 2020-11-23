# Notes

## Info

O - WORST
Ω - BEST
Θ - NOPE

```plaintext
// normal search
n*n = n^2

// sort then bin
n log(n) + n * log(n)
```

## Block search

N -> all
B -> Block size = sqrt(n)
search in block size n/2 (average)
sqrt(n) + b/2

O(sqrt(n) + sqrt(n) / 2) = sqrt(n)
