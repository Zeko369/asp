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

## Cool methods

```cpp
std::toupper // to Upper
std::isspace // is space

// load line
std::string str;
std::getline(std::cin, str);

// Set print width for cout
#include <iomanip>
std::cout << std::setw(10) << "hello";
```
