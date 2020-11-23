#include <iostream>

class Fraction {
  public:
    int up;
    int down;
    Fraction(){};
    Fraction(int a, int b) : up(a), down(b){};

    Fraction operator+(Fraction &other) {
        Fraction tmp;
        tmp.down = this->down * other.down;
        tmp.up = this->up * other.down + this->down * other.up;

        return tmp;
    }

    bool operator==(Fraction &other) {
        return up == other.up && down == other.down;
    }
};

int main(void) {
    Fraction a = Fraction(1, 2);
    Fraction b = Fraction(1, 3);

    std::cout << a.up << " " << a.down << std::endl;
    std::cout << (a == b ? "Same" : "Not same") << std::endl;

    return 0;
}