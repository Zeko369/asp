#include <iostream>

template <typename T> class Arr {
  public:
    T *item;
    int size;

    Arr(int size) : size(size) {
        this->item = (T *)malloc(sizeof(T) * size);

        for (int i = 0; i < size; i++) {
            this->item[i] = 0;
        }
    }

    T &operator[](int a) { return *(item + a); }

    ~Arr() { free(this->item); }
};

int main() {
    Arr<int> a(10);

    a[0] = 10;
    a[1] = 1;
    a[2] = 3;

    for (int i = 0; i < a.size; i++) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
