#include <iostream>

template <typename T> inline T abs(T a) { return a < 0 ? -a : a; }

template <typename T> class Foo {
  public:
    T a;
    Foo(T a) : a(a){};
};

int main(void) {
    Foo<int> a1 = Foo(10);
    Foo<double> a2 = Foo(10.1);
    Foo a3 = Foo("asd");

    std::cout << a1.a << " " << a2.a << " " << a3.a << std::endl;
    std::cout << abs(1.1) << " " << abs(-123) << std::endl;

    return 0;
}