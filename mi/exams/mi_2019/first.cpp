#include <iostream>

bool podnizUNizu(std::string niz, std::string podniz, int pocetak) {
    if (niz.length() == 0) {
        return false;
    }

    if (podniz.length() == 0) {
        return true;
    }

    if (podniz[0] == niz[pocetak]) {
        return podnizUNizu(niz.substr(1), podniz.substr(1), pocetak);
    }

    return false;
}

int main(void) {
    struct Data {
        std::string niz;
        std::string podniz;
        int pocetak;
    };

    Data data[4] = {{"Dobar dan!", "dan", 0},
                    {"Dobar dan!", "dan", 6},
                    {"aaa", "", 0},
                    {"", "asd", 0}};

    for (int i = 0; i < sizeof(data) / sizeof(Data); i++) {
        bool ok = podnizUNizu(data[i].niz, data[i].podniz, data[i].pocetak);
        std::cout << (ok ? "Yes" : "No") << std::endl;
    }

    return 0;
}