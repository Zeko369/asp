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

template <class T> int frequency(Queue<T> *q, int &max) {
    int high = 0;
    int countHigh = 0;

    T item;
    Queue<T> helper;
    Queue<T> out;

    while (q->dequeue(item)) {
        out.enqueue(item);

        T tmp;
        int counter = 1;
        while (q->dequeue(tmp)) {
            helper.enqueue(tmp);

            if (tmp == item) {
                counter++;
            }
        }

        if (counter > high) {
            high = counter;
            countHigh = 1;
        } else if (counter == high) {
            countHigh++;
        }

        while (helper.dequeue(tmp)) {
            q->enqueue(tmp);
        }
    }

    while (out.dequeue(item)) {
        q->enqueue(item);
    }

    max = countHigh;
    return high;
}

int main(void) {
    Queue<char> q = Queue<char>();
    q.enqueue('A');
    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('B');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');
    q.enqueue('D');
    q.enqueue('E');
    q.enqueue('E');
    q.enqueue('E');
    q.enqueue('F');

    int max = 0;
    std::cout << frequency(&q, max) << " " << max << std::endl;
    return 0;
}