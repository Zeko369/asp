#include <iostream>
#include <math.h>

class Heap {
  protected:
    size_t size;
    int *elements;
    int j = 1;

  public:
    Heap(size_t n) {
        this->size = n;
        this->elements = new int[n + 1];
    }

    void Print() {
        size_t i = 1;
        size_t k = 1;
        while (i < this->size) {
            for (; i <= pow(2, k) - 1 && i < this->size; i++) {
                std::cout << " " << this->elements[i] << " ";
            }

            k++;
            std::cout << "\n";
        }
    }

    void PrintTree() { PrintTree(1, 0); }

    void Adjust(size_t i, size_t n) {
        size_t j;
        int element;
        j = 2 * i;
        element = this->elements[i];

        while (j <= n) {
            // Compare left and right child (if they exist)
            if ((j < n) && (this->elements[j] < this->elements[j + 1]))
                j++;
            // j points to a larger child
            if (element >= this->elements[j])
                break; // element is in its position
            this->elements[j / 2] =
                this->elements[j]; // raise larger child one position up
            j *= 2;
        }

        this->elements[j / 2] = element; // store the element
    }

    void AdjustN() {
        size_t i;
        for (i = this->size / 2; i >= 1; i--)
            Adjust(i, this->size);
    }

    void InsertLogN() {
        size_t i, k;
        size_t newElementIndex;
        k = this->j;
        i = this->j / 2;
        newElementIndex = this->elements[this->j];
        while ((i > 0) && (this->elements[i] < newElementIndex)) {
            this->elements[k] =
                this->elements[i]; // push parent to the lower level
            k = i;
            i /= 2; // parent of A[i] is at A[i/2]
        }
        this->elements[k] = newElementIndex;
    }

    void Add(int &element) {
        if (this->j >= (this->size + 1))
            throw std::runtime_error("Allocated heap space is full!");
        this->elements[this->j] = element;
        this->InsertLogN();
        this->j++;
    }

    ~Heap() { delete[] this->elements; }

  private:
    void PrintTree(int i, int level) {
        if (i <= this->size) {
            PrintTree(2 * i + 1, level + 1); // right child
            std::string spaces(level * 2, ' ');
            std::cout << spaces << this->elements[i] << "\n";
            PrintTree(2 * i, level + 1); // left child
        }
    }
};

int main() {
    int A[] = {40, 80, 35, 90, 45, 50, 70, 10, 30};
    constexpr auto n = sizeof(A) / sizeof(int);

    Heap h(n);
    for (int i = 0; i < n; i++) {
        h.Add(A[i]);
    }

    h.Print();
    // h.PrintTree();

    return 0;
}
