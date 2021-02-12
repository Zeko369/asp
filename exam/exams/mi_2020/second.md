```cpp
bool isPalindrome(string str) {
    Stack<char> s;
    char c;

    for(int i = 0; i < str.length(); i++) {
        if(i < str.length() / 2) {
            s.push(str[i]);
        } else if(i == (str.length() / 2) && str.lenght() % 2 == 1) {
            // nista
        } else {
            c = s.pop();
            if(c != str[i]) {
                return false;
            }
        }
    }

    return true;
}
```
