#include <iostream>

bool __initialized = false;
bool __good = false;
int __ilosc_prob = 10;
int __x = 0;
int __n;
int __tab[500001], __tab2[500001];

int initialize() {
    if (__initialized == true) {
        std::cout << "Juz wykonales te operacje!\n";
        return -1;
    }
    __initialized = true;
    std::cin >> __n;
    for (int i = 1; i <= __n; ++i) {
        std::cin >> __tab[i];
    }
    return __n;
}

int get_difference(int L, int R) {
    
    if (__x == 1000000) {
        return 1;
    }
    __x++;
    if (__good == true) {
        std::cout << "Juz udalo Ci sie zgadnac Ciag.\n";
        exit(0);
    }
    if (__initialized == false) {
        std::cout << "Nie zostala wywolana funkcja initialize()!\n";
        return -1;
    }
    int maxx = 0, minn = 1e9;
    for (int i=L; i<=R; ++i) {
        maxx = std::max(maxx, __tab[i]);
        minn = std::min(minn, __tab[i]);
    }
    return maxx - minn;
}

void override(int i, int x) {
    if (__good == true) {
        std::cout << "Juz udalo Ci sie zgadnac Ciag.\n";
        exit(0);
    }
    if (__initialized == false) {
        std::cout << "Nie zostala wywolana funkcja initialize()!\n";
        return;
    }
    __tab2[i] = x;
}

bool check_solution() {
    std::cout << __x << "\n";
    if (__good == true) {
        std::cout << "Juz udalo Ci sie zgadnac Ciag.\n";
        exit(0);
    }
    if (__ilosc_prob == 0) {
        std::cout << "Wszystkie proby zostaly wykorzystane!\n";
        exit(0);
    }
    __ilosc_prob--;
    bool res = true;
    
    for (int i=1; i<=__n; ++i) {
        if (__tab[i] != __tab2[i])
            res = false; 
    }

    if (res == true) {
        std::cout << "Gratulacje! Udalo Ci sie!\n";
        __good = true;
    }
    else {
        std::cout << "Bledna odpowiedz.\n";
    }

    return res;
}