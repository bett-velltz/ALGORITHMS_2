//
// Created by 1 on 17.10.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> capacity(n, vector<int>(n));
    vector<vector<int>> flow(n, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        int v, u, c;
        cin >> v >> u >> c;
        --v; --u;
        capacity[v][u] += c;
    }

    const int INF = 1e6;
    vector<int> used(n);

    function<int(int, int)> dfs = [&](int v, int delta) -> int {
        if (v == n - 1) return delta;
        used[v] = 1;
        for (int u = 0; u < n; ++u) {
            int d = capacity[v][u] - flow[v][u];
            if (used[u] || d <= 0) continue;
            int add = dfs(u, min(delta, d));
            if (add > 0) {
                flow[v][u] += add;
                flow[u][v] -= add;
                return add;
            }
        }
        return 0;
    };

    int answer = 0;
    while (true) {
        fill(used.begin(), used.end(), 0);
        int delta = dfs(0, INF);
        if (delta == 0) break;
        answer += delta;
    }
    cout << answer << "\n";

    return 0;
}
