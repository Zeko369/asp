#include <iostream>

template <typename T> class Queue {
  private:
    static const int MAX = 100;
    T queue[MAX];
    int write = 0;
    int read = 0;

  public:
    bool enqueue(T item) {
        if ((write + 1) % MAX == read)
            return false;
        queue[write] = item;
        write = (write + 1) % MAX;
        return true;
    }
    bool dequeue(T &item) {
        if (write == read)
            return false;
        item = queue[read];
        read = (read + 1) % MAX;
        return true;
    }

    void print() {
        for (int j = read; j < write; j++) {
            std::cout << queue[j] << " ";
        }

        std::cout << std::endl;
    }
};

template <typename T> Queue<T> *split(Queue<T> *q) {
    Queue<T> *out = new Queue<T>();
    Queue<T> addBack;

    T a;
    int i = 0;

    while (q->dequeue(a)) {
        if (i++ % 2 == 0) {
            out->enqueue(a);
        } else {
            addBack.enqueue(a);
        }
    }

    while (addBack.dequeue(a)) {
        q->enqueue(a);
    }

    return out;
}

int main(void) {
    Queue<int> q = Queue<int>();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.print();

    Queue<int> *a = split(&q);
    q.print();
    a->print();
}