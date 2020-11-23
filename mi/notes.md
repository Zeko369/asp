# Notes

## Virtual methods need to have = 0

```cpp
  public:
    virtual void foo() = 0;
```

## Timing stuff

```cpp
auto start = std::chrono::system_clock::now();

// RUN CODE

auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end - start;

std::cout << elapsed_seconds.count() << std::endl;
```
