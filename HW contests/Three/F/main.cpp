//
// Created by 1 on 16.10.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

std::vector<std::vector<int>> gr;

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> capacity(n+m+2, vector<int>(n+m+2));
    vector<vector<int>> flow(n+m+2, vector<int>(n+m+2));

    for (int i = 1; i <= n; ++i) {
        capacity[0][i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        capacity[n+i][n+m+1] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        int pr;
        while (true) {
            std::cin >> pr;
            if (pr == 0) break;
            capacity[i][n+pr] = 1;
        }
    }

    const int INF = 1e6;
    vector<int> used(n+m+2);

    function<int(int, int)> dfs = [&](int v, int delta) -> int {
        if (v == n + m + 1) return delta;           // дошли до стока: ура
        used[v] = 1;
        for (int u = 0; u < n + m + 2; ++u) {
            int d = capacity[v][u] - flow[v][u];
            if (used[u] || d <= 0) continue;    // были там или дуга закрыта
            int add = dfs(u, min(delta, d));    // запоминаем узкое место
            if (add > 0) {                      // путь найден, откатываемся
                flow[v][u] += add;
                flow[u][v] -= add;
                return add;
            }
        }
        return 0;                               // увеличивающего пути здесь нет
    };

    int answer = 0;
    while (true) {
        fill(used.begin(), used.end(), 0);
        int delta = dfs(0, INF);
        if (delta == 0) break;
        answer += delta;
    }
    cout << answer << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (flow[i][n+j] == 1) {
                cout << i << ' ' << j << "\n";
            }
        }
    }

    return 0;
}
