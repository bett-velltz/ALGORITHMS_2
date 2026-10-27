//
// Created by 1 on 01.10.2026.
//
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> z_function(const std::vector<int> &s) {
    int n = (int) s.size();
    std::vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    auto v2 = v;
    v2.emplace_back(0);
    for (int i = v.size() - 1; i >= 0; --i) {
        v2.emplace_back(v[i]);
    }
    auto z = z_function(v2);

    std::vector<int> ans;
    ans.emplace_back(n);
    for (int i = 1; i <= n; ++i) {
        if (z[2*n + 1 - 2*i] == 2*i) {
            ans.emplace_back(n-i);
        }
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << '\n';
    return 0;
}