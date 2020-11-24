#include <iostream>

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

template <class T> bool isOk(T item) {
    if (item >= 10) {
        return false;
    }

    return true;
}

template <class T> void shuffle(Stack<T> *s) {
    Stack<T> ok;
    Stack<T> notOk;

    T item;
    while (s->pop(item)) {
        if (isOk(item)) {
            ok.push(item);
        } else {
            notOk.push(item);
        }
    }

    Stack<T> tmp;
    while (notOk.pop(item)) {
        tmp.push(item);
    }

    int side = 0;
    while (1) {
        if (side % 2 == 0) {
            if (ok.pop(item)) {
                s->push(item);
                side++;
                continue;
            }

            if (tmp.pop(item)) {
                s->push(item);
                side++;
                continue;
            }
        } else {
            if (tmp.pop(item)) {
                s->push(item);
                side++;
                continue;
            }

            if (ok.pop(item)) {
                s->push(item);
                side++;
                continue;
            }
        }

        break;
    }
}

int main(void) {
    Stack<int> stack = Stack<int>();

    stack.push(1);
    stack.push(2);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(3);
    stack.push(40);
    stack.push(50);
    stack.push(4);
    stack.push(60);

    stack.print();

    shuffle(&stack);

    stack.print();

    return 0;
}