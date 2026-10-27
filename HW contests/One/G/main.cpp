//
// Created by 1 on 02.10.2026.
//

#include <iostream>
#include <vector>

std::vector<int> func(const std::vector <int> &v) {
    int sz = v.size();
    std::vector<int> z( sz, 0);

    for (int i = 1; i < sz; ++i) {
        if (v[i]) {
            z[i - v[i] + 1] = v[i];
        }
    }
    z[0] = 0;
    for (int i = 1; i < sz; ++i) {
        int t = i;
        if (z[i]) {
            for (int j = 1; j < z[i]; ++j) {
                if (z[i + j] > z[j]) break;
                z[i + j] = std::min(z[j], z[i] - j);
                t = i + j;
            }
        }
        i = t;
    }
    return z;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    std::vector<int> res = func(p);

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
