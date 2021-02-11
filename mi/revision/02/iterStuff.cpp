#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Double {
  public:
    void operator()(int &i) { std::cout << i * 2 << std::endl; }
};

int main(void) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int>::iterator i;

    for (i = v.begin(); i != v.end(); i++) {
        std::cout << *i << std::endl;
    }
    std::cout << "NEW" << std::endl;

    // This is how to lambda
    for_each(v.begin(), v.end(), [](auto a) { std::cout << a << std::endl; });

    std::cout << "NEW" << std::endl;
    for_each(v.begin(), v.end(), Double());

    return 0;
}
