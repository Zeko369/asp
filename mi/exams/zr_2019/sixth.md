# Second

## a

```cpp
int f1(int n){
    s=0;
    for(i=1; i<=n; i*=2)
        for(j=1; j<=n; j++)
            s+= f(n,j) + f(n,i);
    return s;
}
```

```plaintext
O - 2x * n * log(n) => (x = n) => n ^ 2 * log(n)
Ω - 2x * n * log(n) => ...     => n ^ 2 * log(n)
Θ - 2x * n * log(n) => ...     => n ^ 2 * log(n)
```
