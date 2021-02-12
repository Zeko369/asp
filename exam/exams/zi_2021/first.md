```cpp
private:
int _jednoDijete(std::shared_ptr<Cvor> node) {
    int cnt = 0;

    int count = 0;
    if(node->right) {
        count++;
        cnt += jednoDijete(node->right);
    }
    if(node->left) {
        count++;
        cnt += jednoDijete(node->right);
    }

    if(count == 1) {
        cnt++;
    }

    return cnt;
}

public:
int jednoDijete() {
    return this->_jednoDijete(korijen);
}

int main() {
    BStablo btree = BStablo();
    btree.add(2);
    btree.add(1);
    btree.add(4);
    btree.add(3);
    btree.add(5);

    std::cout << btree.jednoDijete() << std::endl;

    return 0;
}
```
