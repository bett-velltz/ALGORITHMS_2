//
// Created by 1 on 18.10.2026.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct E {
    int to, cap, flow, rev;
};

vector<vector<E>> g;

void add(int v, int u) {
    int a = g[v].size(), b = g[u].size();
    g[v].push_back({u, 1, 0, b});
    g[u].push_back({v, 0, 0, a});
}

bool bfs(int s, int t, vector<int>& pv, vector<int>& pe) {
    int n = g.size();

    pv.assign(n, -1);
    pe.assign(n, -1);

    queue<int> q;
    q.push(s);
    pv[s] = s;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            E& e = g[v][i];
            if (pv[e.to] == -1 && e.cap - e.flow > 0) {
                pv[e.to] = v;
                pe[e.to] = i;

                if (e.to == t) {
                    return true;
                }

                q.push(e.to);
            }
        }
    }
    return false;
}

void push(int s, int t, vector<int>& pv, vector<int>& pe) {
    int v = t;
    while (v != s) {
        E& e = g[pv[v]][pe[v]];
        ++e.flow;
        --g[v][e.rev].flow;
        v = pv[v];
    }
}

int main() {

    int n, m, a, h;
    cin >> n >> m >> a >> h;
    --a; --h;
    g.resize(n);

    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        if (v != u) {
            add(v, u);
        }
    }

    int cnt = 0;

    vector<int> pv, pe;

    while (cnt < 2 && bfs(a, h, pv, pe)) {
        push(a, h, pv, pe);
        ++cnt;
    }

    if (cnt < 2) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';

    for (int j = 0; j < 2; ++j) {
        vector<int> p(n, -1), pe2(n, -1);
        queue<int> q;
        q.push(a);
        p[a] = a;

        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (v == h) break;
            for (int i = 0; i < g[v].size(); ++i) {
                E& e = g[v][i];
                if (e.flow == 1 && p[e.to] == -1) {
                    p[e.to] = v;
                    pe2[e.to] = i;
                    q.push(e.to);
                }
            }
        }

        vector<int> res;
        for (int v = h; v != a; v = p[v]) {
            res.push_back(v);
        }
        res.push_back(a);
        reverse(res.begin(), res.end());

        for (int i = 0; i + 1 < res.size(); ++i) {
            int x = res[i], y = res[i + 1];
            for (auto& e : g[x]) {
                if (e.to == y && e.flow == 1) {
                    e.flow = 0;
                    break;
                }
            }
        }

        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] + 1;
            cout << ' ';
        }
        cout << '\n';
    }
}

//просто ищем поток с величиной два с ребрами пропускной способности 1