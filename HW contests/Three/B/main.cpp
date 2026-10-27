//
// Created by 1 on 14.10.2026.
//

#include <iostream>
#include <algorithm>

int main() {
    int k;
    std::cin >> k;
    long long ans;

    for (int i = 0; i < k; ++i) {
        long long el;
        std::cin >> el;
        ans = std::min(ans, el);
    }
    std::cout << ans << '\n';
    return 0;
}