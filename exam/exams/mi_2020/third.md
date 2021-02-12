```cpp
Atom *tmp = head;
List newList = List();

while(tmp) {
    if(tmp->val % 2 == 0) {
        newList.insert(tmp->val);
    }

    tmp = tmp->next;
}

return newList;
```
