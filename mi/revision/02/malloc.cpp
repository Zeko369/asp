#include <iostream>

int main(void) {
    int *ptr = new int[10];

    // To delete an array
    delete[] ptr;

    return 0;
}