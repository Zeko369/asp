#include <iostream>
#include <memory>

class BinTree {
  private:
    struct Node {
        char val;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> root;

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

  public:
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

    void remove(char c) { this->del(root, c); }
    void inorder() { inorderInternal(root); }
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

    return 0;
}
