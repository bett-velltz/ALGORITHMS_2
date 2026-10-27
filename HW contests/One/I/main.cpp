//
// Created by 1 on 01.10.2026.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

long long function(const std::string &s) {
    int sz = s.size();
    std::vector<int> d(sz, 1);
    int l = 0, r = 0;

    for (int i = 1; i < sz; ++i) {
        if (i < r) {
            d[i] = std::min(r - i + 1, d[l + r - i]);
        }
        while (i - d[i] >= 0 && i + d[i] < sz && s[i - d[i]] == s[i + d[i]]) {
            d[i]++;
        }
        if (i + d[i] - 1 > r) {
            l = i - d[i] + 1, r = i + d[i] - 1;
        }
    }
    for (int i = 0; i < sz; ++i) {
        if (i%2 == 0) {
            d[i] = (d[i] + 1) / 2;
            --d[i];
        } else {
            d[i] = d[i] / 2;
        }
    }
    long long res = std::accumulate(d.begin(), d.end(), 0LL); //тк эта функция определяет тип результата по типу числа 0, а оно int без LL
    return res;
}

int main() {

    std::string s;
    std::cin >> s;
    int n = s.size();

    std::string str;
    str += s[0];
    for (int i = 1; i < n; ++i) {
        str += "#";
        str += s[i];
    }

    std::cout << function(str);
    return 0;
}