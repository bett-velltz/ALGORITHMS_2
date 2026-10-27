//
// Created by 1 on 16.09.2026.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <fstream>

const int64_t m = 1e9 + 9;
const int64_t base = 257;
std::string s_a, s_b;
std::vector<long long> pw;
std::vector<long long> pref;

int64_t sum(int64_t a, int64_t b) {
    a %= m;
    b %= m;
    return ((a + b) % m + m) % m;
}

int64_t sub(int64_t a, int64_t b) {
    a %= m;
    b %= m;
    return ((a - b) % m + m) % m;
}

int64_t mul(int64_t a, int64_t b) {
    a %= m;
    b %= m;
    return ((a * b) % m + m) % m;
}

long long hash(int l, int r) {
    return sub(pref[r], mul(pref[l-1], pw[r-l+1])) % m;
}

int main() {
    std::ifstream file("input.txt");
    file >> s_a >> s_b;

    if (s_b == "") {
        std::ofstream out("output.txt");
        out << 0 << '\n';
        return 0;
    }

    long long n1 = s_a.size();
    long long n2 = s_b.size();

    //шаг 1: преподсчет массива степеней оснований
    pw.resize(n1 + 1);
    pw[0] = 1;
    for (int i = 1; i <= n1; i++) {
        pw[i] = pw[i - 1] * base % m;
    }

    //шаг 2: массив преф хэшей
    pref.resize(n1 + 1);
    pref[0] = 0;
    for (int i = 1; i <= n1; i++) {
        int64_t val = s_a[i-1] - 'a' + 1;
        pref[i] = (pref[i - 1] * base + val) % m;
    }

    //шаг 3: вычисляем хэн второй строки
    int64_t base_hash = 0;

    for (char c : s_b) {
        int64_t val = c - 'a' + 1;
        base_hash = sum(mul(base_hash, base), val);
    }


    //шаг 4: проверяем хэши подстрок по порядку
    int cnt = 0;
    std::vector<int> res;

    for (int i = 1; i <= n1-n2+1; ++i) {
        if (hash(i, i + n2 - 1) == base_hash) {
            cnt++;
            res.emplace_back(i);
        }
    }
    std::ofstream out("output.txt");
    out << cnt << '\n';
    for (int i = 0; i < cnt; ++i) {
        out << res[i] << ' ';
    }
    out << '\n';

    return 0;
}