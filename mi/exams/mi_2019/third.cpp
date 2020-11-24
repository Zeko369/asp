#include <iostream>

template <typename T> class Node {
  public:
    T value;
    Node<T> *next;

    Node<T>(T val) : value(val) {}
};

template <typename T> class List {
  public:
    Node<T> *head = nullptr;

    void add(T item) {
        Node<T> *nextNode = new Node<T>(item);

        if (head == nullptr) {
            head = nextNode;
        } else {
            nextNode->next = head;
            head = nextNode;
        }
    }

    void print() {
        Node<T> *tmp = head;

        while (tmp->next != nullptr) {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }

        std::cout << tmp->value << std::endl;
    }

    // TODO: Check this out
    void removeGreaterThan(T item) {
        Node<T> **p = &head;

        while (*p) {
            if ((*p)->value > item) {
                Node<T> *tmp;
                tmp = *p;

                *p = (*p)->next;

                delete tmp;
            } else {
                p = &((*p)->next);
            }
        }
    }
};

int main(void) {
    List<int> a = List<int>();

    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);

    a.print();

    a.removeGreaterThan(2);

    a.print();

    return 0;
}