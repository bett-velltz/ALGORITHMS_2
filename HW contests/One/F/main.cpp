//
// Created by 1 on 30.09.2026.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> z(n, 0);
    std::vector<int> p(n, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> z[i];
    }

    for (int i = 1; i < n; i++) {
        if (z[i] != 0) {
            for (int j = z[i] - 1; j >= 0 && !p[i + j]; --j) {
                p[i + j] = j + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << '\n';
}