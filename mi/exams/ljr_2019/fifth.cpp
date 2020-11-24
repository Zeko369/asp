class Node {
  public:
    int value;
    Node *next;
};

class List {
  private:
    Node *head;

  public:
    void extend(int item) {
        Node **tmp = &head;
        while (*tmp) {
            if ((*tmp)->next) {
                if ((*tmp)->value < item && (*tmp)->next->value < item) {
                    int val = (*tmp)->value;

                    if ((*tmp)->value < (*tmp)->next->value) {
                        val = (*tmp)->next->value;
                    }

                    Node *newNode = new Node();
                    newNode->value = val;
                    newNode->next = (*tmp)->next;
                    (*tmp)->next = newNode;
                }
            }

            tmp = &((*tmp)->next);
        }
    }
};