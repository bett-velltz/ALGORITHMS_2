//
// Created by 1 on 12.09.2026.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>

int64_t p, m;
std::string s;

std::vector<int64_t> r (1000000);

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

int main() {
    std::cin >> p >> m >> s;
    std::reverse(s.begin(), s.end());
    int64_t H = 0;

    for (char c : s) {
        int64_t val = c - 'a' + 1;
        H = sum(mul(H, p), val);
    }

    std::cout << H << '\n';
    return 0;
}