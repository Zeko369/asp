#include <algorithm>
#include <iostream>
#include <vector>

template <class T> class Stack {
  private:
    static const int MAX = 100;
    T stack[MAX];
    int top = -1;

  public:
    bool push(T item) {
        if (top >= MAX)
            return false;
        stack[++top] = item;
        return true;
    }

    bool pop(T &item) {
        if (top < 0)
            return false;
        item = stack[top--];
        return true;
    }

    void print() {
        for (int i = 0; i < top + 1; i++) {
            std::cout << stack[i] << " ";
        }

        std::cout << std::endl;
    }
};

template <typename T> void middle(Stack<T> *s) {
    T x;
    s->pop(x);

    std::vector<T> smaller;
    std::vector<T> bigger;

    T item;
    while (s->pop(item)) {
        if (x > item) {
            smaller.push_back(item);
        } else {
            bigger.push_back(item);
        }
    }

    sort(bigger.begin(), bigger.end(), std::greater<>());

    for (int i = 0; i < bigger.size(); i++) {
        s->push(bigger[i]);
    }

    s->push(x);

    for (int i = 0; i < smaller.size(); i++) {
        s->push(smaller[i]);
    }
}

int main(void) {
    Stack<int> stack = Stack<int>();

    stack.push(5);
    stack.push(2);
    stack.push(1);
    stack.push(4);

    // x
    stack.push(3);

    stack.print();

    middle(&stack);

    stack.print();

    return 0;
}