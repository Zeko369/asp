#include <iostream>

template <typename T> class Stack {
    template <typename K> struct StackElem {
        K val;
        StackElem<K> *next;
    };

  private:
    StackElem<T> *ptr = nullptr;

  public:
    Stack() {}

    void push(T val) {
        StackElem<T> *se = new StackElem<T>;
        se->val = val;
        se->next = ptr;

        ptr = se;
    }

    void pop() {
        if (ptr == nullptr) {
            return;
        }

        StackElem<T> *tmp = ptr;
        ptr = tmp->next;

        delete tmp;
    }

    T head() { return this->ptr->val; }
};

int main() {
    Stack<int> s = Stack<int>();

    s.push(1);
    s.push(2);

    std::cout << s.head() << std::endl;

    s.pop();
    std::cout << s.head() << std::endl;

    return 0;
}
