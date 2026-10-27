//
// Created by 1 on 14.10.2026.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

std::vector<std::vector<int>> gr;
std::vector<int> used;

void dfs(int ver) {
    used[ver] = true;
    for (int i = 0; i < gr.size(); ++i)
        if (gr[ver][i] == 1 && !used[i])
            dfs(i);
}

int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--, t--;
    gr.resize(n, std::vector<int>(n, 0));
    used.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        gr[u][v] = 1;
    }
    dfs(s);
    if (used[t] == 1) {
        std::cout << "YES\n";
        return 0;
    }
    std::cout << "NO\n";
    return 0;
}