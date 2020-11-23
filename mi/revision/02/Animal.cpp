#include <iostream>

class Animal {
  public:
    inline static int autoIncrement = 0;

    int id;
    std::string name;
    Animal(std::string n) : name(n), id(++autoIncrement){};

    virtual void say() = 0;
};

class Cat : public Animal {
  public:
    Cat(std::string n) : Animal(n){};
    void say() { std::cout << "Meow" << std::endl; };
};

class Dog : public Animal {
  public:
    // using Animal::Animal;
    Dog(std::string n) : Animal(n){};
    void say() { std::cout << "Woff" << std::endl; };
};

int main() {
    Dog a = Dog("Cloudy");
    Cat b = Cat("Kandi");

    Animal *arr[2] = {&a, &b};

    for (int i = 0; i < 2; i++) {
        std::cout << arr[i]->id << std::endl;
        arr[i]->say();
    }

    std::cout << Animal::autoIncrement << std::endl;

    return 0;
}