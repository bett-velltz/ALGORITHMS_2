//
// Created by 1 on 14.10.2026.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::map<int, std::vector<int>> stud1;
    std::map<int, std::vector<int>> stud2;
    std::map<int, std::vector<int>> prod;

    for (int i = 0; i < k; ++i) {
        int u, v;
        std::cin >> u >> v;
        stud1[u].emplace_back(v);
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (std::find(stud1[u].begin(), stud1[u].end(), v) == stud1[u].end()) {
            std::cout << "NO" << '\n';
            return 0;
        }
        prod[v].emplace_back(u);
        stud2[u].emplace_back(v);
    }
    for (const auto& [st, pr] : stud2) {
        if (pr.size() > 1) {
            std::cout << "NO" << '\n';
            return 0;
        }
    }

    for (const auto& [pr, st] : prod) {
        if (st.size() > 1) {
            std::cout << "NO" << '\n';
            return 0;
        }
    }
    std::cout << "YES" << '\n';
    return 0;
}