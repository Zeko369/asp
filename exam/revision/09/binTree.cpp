#include <iostream>
#include <memory>

class BinTree {
  private:
    struct Node {
        char val;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    void insert(std::shared_ptr<Node> &n, char c) {
        if (n->val > c) {
            if (n->left != nullptr) {
                insert(n->left, c);
            } else {
                std::shared_ptr<Node> newNode = std::make_shared<Node>();
                newNode->val = c;
                n->left = newNode;
            }
        } else if (n->val < c) {
            if (n->right != nullptr) {
                insert(n->right, c);
            } else {
                std::shared_ptr<Node> newNode = std::make_shared<Node>();
                newNode->val = c;
                n->right = newNode;
            }
        }
    }

    void del(std::shared_ptr<Node> &node, char c) {
        if (!node) {
            return;
        }

        if (node->val < c) {
            del(node->right, c);
        } else if (node->val > c) {
            del(node->left, c);
        } else {
            if (!node->right) {
                std::cout << node->left << " " << node->val << " "
                          << node->right << std::endl;
                node = node->left;
                if (node == nullptr) {
                    std::cout << "nullptr" << std::endl;
                } else {
                    std::cout << node->left << " " << node->val << " "
                              << node->right << std::endl;
                }
            } else if (!node->left) {
                node = node->right;
            } else {
                // has both children

                std::shared_ptr<Node> tmp = node->left;
                std::shared_ptr<Node> prev = nullptr;
                while (tmp->right) {
                    prev = tmp;
                    tmp = tmp->right;
                }

                node->val = tmp->val;
                if (prev)
                    prev->right = tmp->left;
                else
                    node->left = tmp->left;
            }
        }
    }

    int countInternal(std::shared_ptr<Node> &n) {
        int tmp = 1;
        if (n->right) {
            tmp += countInternal(n->right);
        }

        if (n->left) {
            tmp += countInternal(n->left);
        }

        return tmp;
    }

    int maxDepthInternal(std::shared_ptr<Node> &n, int d = 0) {
        if (n == nullptr) {
            return d;
        }

        int left = maxDepthInternal(n->left, d + 1);
        int right = maxDepthInternal(n->right, d + 1);

        if (left > right) {
            return left;
        }
        return right;
    }

    void inorderInternal(std::shared_ptr<Node> &n) {
        if (n->left != nullptr) {
            inorderInternal(n->left);
        }

        std::cout << n->val << " ";

        if (n->right != nullptr) {
            inorderInternal(n->right);
        }
    }

    int getMin(std::shared_ptr<Node> &n) {
        if (n->left) {
            return getMin(n->left);
        }

        return n->val;
    }

    int getMax(std::shared_ptr<Node> &n) {
        if (n->right) {
            return getMax(n->right);
        }

        return n->val;
    }

    void getMinMaxInternal(std::shared_ptr<Node> &n) {
        char minVal = getMin(n);
        char maxVal = getMax(n);

        std::cout << minVal << " = " << maxVal << std::endl;
    }

  public:
    std::shared_ptr<Node> root;

    void add(char c) {
        if (root == nullptr) {
            std::shared_ptr<Node> newNode = std::make_shared<Node>();
            newNode->val = c;
            root = newNode;
        } else {
            this->insert(root, c);
        }
    }

    int count() { return this->countInternal(root); }
    int maxDepth() { return this->maxDepthInternal(root); }

    void getMinMax() { return this->getMinMaxInternal(root); }
    void remove(char c) { this->del(root, c); }
    void inorder() { this->inorderInternal(root); }

    bool internalCompare(std::shared_ptr<Node> a, std::shared_ptr<Node> b) {
        if ((a == nullptr && b != nullptr) || (a != nullptr && b == nullptr)) {
            return false;
        }

        if (a->val != b->val) {
            return false;
        }

        if (a->right || b->right) {
            if (!internalCompare(a->right, b->right)) {
                return false;
            }
        }

        if (a->left || b->left) {
            if (!internalCompare(a->left, b->left)) {
                return false;
            }
        }

        return true;
    }

    bool compare(BinTree &other) { return internalCompare(other.root, root); }
};

int main() {
    BinTree bt = BinTree();
    bt.add('3');

    std::cout << bt.count() << "|" << bt.maxDepth() << std::endl;
    bt.add('2');
    bt.add('5');
    bt.add('1');
    bt.add('8');
    bt.add('9');
    bt.add('4');
    std::cout << bt.count() << "|" << bt.maxDepth() << std::endl;

    bt.inorder();
    std::cout << std::endl;

    bt.remove('5');
    std::cout << bt.count() << "|" << bt.maxDepth() << std::endl;

    bt.inorder();
    std::cout << std::endl;

    bt.remove('9');
    bt.inorder();
    std::cout << std::endl;
    std::cout << bt.count() << "|" << bt.maxDepth() << std::endl;

    bt.getMinMax();

    BinTree bt1 = BinTree();
    BinTree bt2 = BinTree();
    BinTree bt3 = BinTree();

    bt1.add(3);
    bt2.add(3);
    bt3.add(3);

    bt1.add(1);
    bt2.add(1);
    bt3.add(1);

    bt1.add(2);
    bt2.add(2);
    bt3.add(4);

    bt1.add(5);
    bt2.add(5);
    bt3.add(5);

    std::cout << (bt1.compare(bt2) ? "true" : "false") << std::endl;
    std::cout << (bt1.compare(bt3) ? "true" : "false") << std::endl;

    return 0;
}
