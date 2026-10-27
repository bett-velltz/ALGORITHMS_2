//
// Created by 1 on 14.10.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> com;

struct Wire {
    int from;
    int to;
    long long weight;
};

std::vector<Wire> wires;
long long summ = 0;
int cnt = 0;

int main() {
    int n, m;
    std::cin >> n >> m;
    wires.resize(m);
    com.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long c;
        std::cin >> u >> v >> c;
        u--, v--;
        wires[i].from = u;
        wires[i].to = v;
        wires[i].weight = c;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> com[i];
    }

    for (int i = 0; i < m; ++i) {
        auto w = wires[i];
        if (com[w.from] != com[w.to]) {
            cnt++;
            summ += w.weight;
        }
    }

    std::cout << cnt << ' ' << summ << '\n';
    return 0;
}
