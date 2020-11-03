#include <iostream>

int g(int i)
{
  std::cout << i << " ";
  if (i > 1)
    return g(i - 1);
  else
    return 0;
}

void f(int &n)
{
  if (n >= 2)
    g(n);
  else
  {
    n -= 1;
    std::cout << n;
  }
}

void f2(int &n)
{
  int m = n - 1;
  if (n >= 1)
    f2(m);
  else
  {
    std::cout << n << ' ';
  }
}

int main()
{
  // int i = 5;
  int i = 4;
  f2(i);
  return 0;
}