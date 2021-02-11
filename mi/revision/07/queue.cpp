#include <iostream>

class QueueStatic {
  private:
    int *arr = new int[10];
    int push = 0;
    int read = 0;

  public:
    void add(int a) { arr[push++] = a; }
    int get() { return arr[read++]; }
};

class QueueDynamic {
  private:
    struct Elem {
        int val;
        Elem *next;
    };

    Elem *read;
    Elem *write;

  public:
    void add(int a) {
        Elem *e = new Elem;
        e->val = a;

        if (write == nullptr) {
            read = e;
        } else {
            write->next = e;
        }
        write = e;
    }

    int get() {
        if (read != nullptr) {
            Elem *tmp = read;
            int val = tmp->val;
            read = tmp->next;
            delete tmp;
            return val;
        }

        return -1;
    }
};

int main() {
    // QueueStatic q = QueueStatic();
    // q.add(10);
    // q.add(20);
    // q.add(30);

    // std::cout << q.get() << std::endl;

    // q.add(50);
    // std::cout << q.get() << " " << q.get() << " " << q.get() << std::endl;

    QueueDynamic q = QueueDynamic();
    q.add(10);
    q.add(20);
    q.add(30);

    std::cout << q.get() << " " << q.get() << std::endl;

    q.add(40);
    q.add(50);
    std::cout << q.get() << " " << q.get() << " " << q.get() << std::endl;

    return 0;
}
