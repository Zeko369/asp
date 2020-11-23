#include <iostream>

template <typename T> class Node {
  public:
    T value;
    Node<T> *next;

    Node(T val) : value(val) {}
};

template <typename T> class ListIter {
  private:
    Node<T> *ptr = nullptr;

  public:
    ListIter<T>() : ptr(nullptr){};
    ListIter<T>(Node<T> *head) : ptr(head){};

    // a++
    ListIter<T> &operator++() {
        if (ptr)
            ptr = ptr->next;
        return *this;
    }

    // ++a
    ListIter<T> operator++(int) {
        ListIter<T> tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator!=(const ListIter<T> &other) { return this->ptr != other.ptr; }

    T get() { return ptr->value; }
};

template <typename T> class List {
  private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

  public:
    int size = 0;
    List() {}

    void append(T val) {
        Node<T> *tmp = new Node<T>(val);

        Node<T> **p = &this->head;
        tmp->next = *p;
        *p = tmp;

        if (this->tail == nullptr) {
            this->tail = this->head;
        }

        size++;
    }

    void prepend(T val) {
        Node<T> *tmp = new Node<T>(val);
        tmp->next = nullptr;
        this->tail->next = tmp;
        this->tail = tmp;

        size++;
    }

    void insert(T val, int index) {
        if (index >= size) {
            std::cerr << "ArrayIndexOutOfBounds " << size << " " << index
                      << std::endl;
            return;
        }

        Node<T> *tmp = head;
        int i = 1;

        while (i < index - 1) {
            tmp = tmp->next;
            i++;
        }

        Node<T> *newNode = new Node<T>(val);
        newNode->next = tmp->next;
        tmp->next = newNode;

        this->size++;
    }

    void print() {
        Node<T> *tmp = head;

        while (tmp->next != nullptr) {
            std::cout << tmp->value << ", ";
            tmp = tmp->next;
        }

        std::cout << tmp->value << std::endl;
    }

    typedef ListIter<T> iterator;
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(); }
};

int main(void) {
    List<int> arr = List<int>();

    arr.append(0);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(5);
    arr.append(6);

    // arr.insert(10, 4);

    // arr.prepend(4);
    // arr.prepend(5);
    // arr.prepend(6);

    arr.print();

    ListIter<int> i;
    for (i = arr.begin(); i != arr.end(); i++) {
        std::cout << i.get() << ",";
    }

    std::cout << "\n";

    return 0;
}