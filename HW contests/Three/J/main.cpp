#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct E {
    int to, cap, flow, rev;
};

vector<vector<E>> g;

void add(int v, int u, int c) {
    int a = g[v].size(), b = g[u].size();
    g[v].push_back({u, c, 0, b});
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

long long push(int s, int t, vector<int>& pv, vector<int>& pe) {
    int v = t, mn = 1e9;

    while (v != s) {
        E& e = g[pv[v]][pe[v]];
        mn = min(mn, e.cap - e.flow);
        v = pv[v];
    }

    v = t;
    while (v != s) {
        E& e = g[pv[v]][pe[v]];
        e.flow += mn;
        g[v][e.rev].flow -= mn;
        v = pv[v];
    }

    return mn;
}

int main() {

    int n, m;
    cin >> n >> m;
    --n;
    g.resize(n + 1);

    vector<int> U(m), V(m), C(m);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        U[i] = u; V[i] = v; C[i] = c;
        add(u, v, c);
        add(v, u, c);
    }

    int s = 0, t = n;

    long long flow = 0;
    vector<int> pv, pe;
    while (bfs(s, t, pv, pe)) {
        flow += push(s, t, pv, pe);
    }

    if (flow == 0) {
        cout << "0 0\n\n";
        return 0;
    }

    vector<int> inS(n + 1, 0);
    queue<int> q;
    q.push(s);
    inS[s] = 1;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (E& e : g[v]) {
            if (!inS[e.to] && e.cap - e.flow > 0) {
                inS[e.to] = 1;
                q.push(e.to);
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < m; ++i) {
        if (inS[U[i]] != inS[V[i]]) {
            res.push_back(i + 1);
        }
    }

    cout << res.size() << " " << flow << "\n";
    for (int i = 0; i < res.size(); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << res[i];
    }

    cout << "\n";

    return 0;
}