#include <iostream>

void print(int arr[], int size)
{
  if (size > 0)
  {
    print(arr + 1, size - 1);
    std::cout << arr[size - 1] << " ";
  }
}

int main()
{
  // int arr[5] = {1, 3, 4, 6, 8};
  int arr[5] = {1, 2, 3, 4, 5};
  print(arr, 5);
  return 0;
}