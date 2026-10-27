//
// Created by 1 on 26.09.2026.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <algorithm>

const int64_t p = 1e9 + 7;
const int64_t x = 263;
std::vector<int> pw;
std::vector<std::vector<std::string>> vec;

int64_t sum(int64_t a, int64_t b) {
    a %= p;
    b %= p;
    return ((a + b) % p + p) % p;
}

int64_t sub(int64_t a, int64_t b) {
    a %= p;
    b %= p;
    return ((a - b) % p + p) % p;
}

int64_t mul(int64_t a, int64_t b) {
    a %= p;
    b %= p;
    return ((a * b) % p + p) % p;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    vec.resize(m);

    //шаг 1: преподсчет массива степеней оснований
    int sz = 15;
    pw.resize(sz + 1);
    pw[0] = 1;
    for (int i = 1; i <= sz; i++) {
        pw[i] = pw[i - 1] * x % p;
    }

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        if (s == "check") {
            int ind;
            std::cin >> ind;
            if (vec[ind].empty()) {
                std::cout << " " << '\n';
            } else {
               for (int j = 0; j < vec[ind].size(); ++j) {
                   std::cout << vec[ind][j] << ' ';
               }
                std::cout << '\n';
            }
        } else {
            std::string str;
            std::cin >> str;
            std::string str2 = str;
            std::reverse(str2.begin(), str2.end());

            int hash = 0;
            for (char c : str2) {
                int64_t val = c;
                hash = sum(mul(hash, x), val);
            }
            hash = hash % m;

            if (s == "del") {
                auto fl = std::find(vec[hash].begin(), vec[hash].end(), str);
                if (fl != vec[hash].end()) {
                    vec[hash].erase(fl);
                }
            } else if (s == "find") {
                auto fl = std::find(vec[hash].begin(), vec[hash].end(), str);
                if (fl == vec[hash].end()) {
                    std::cout << "no\n";
                } else {
                    std::cout << "yes\n";
                }
            } else if (s == "add") {
                auto fl = std::find(vec[hash].begin(), vec[hash].end(), str);
                if (fl == vec[hash].end()) {
                    vec[hash].insert(vec[hash].begin(), str);
                }
            }
        }
    }
    return 0;
}