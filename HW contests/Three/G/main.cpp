//
// Created by 1 on 17.10.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s.size()  > n) {
        cout << "NO" << '\n';
        return 0;
    }

    int m = s.size();
    vector<vector<char>> cubes(n, vector<char>(6));

    vector<vector<int>> capacity(n + s.size() + 2, vector<int>(n + s.size() + 2));
    vector<vector<int>> flow(n + s.size() + 2, vector<int>(n + s.size() + 2));

    for (int i = 1; i <= m; ++i) {
        capacity[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        capacity[m+i][n+m+1] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> cubes[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (find(cubes[j-1].begin(), cubes[j-1].end(), s[i-1]) != cubes[j-1].end()) {
                capacity[i][m + j] = 1;
            }
        }
    }

    //-------
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
    if (answer < m) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (flow[i][m+j] == 1) {
                cout << j << ' ';
            }
        }
    }
    cout << '\n';

    return 0;
}
