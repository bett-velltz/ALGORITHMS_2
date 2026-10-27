//
// Created by 1 on 24.10.2026.
//
#include <iostream>
#include <vector>
using namespace std;

/*long long minimum = -1e9 - 1, maximum = 1e9 + 1;

bool func(int ind, long long lo, long long hi) {
    if (ind == -1) {
        return true;
    }

    if (key[ind] <= lo || key[ind] >= hi) return false;

    long long s_l = (l[ind] == -1) ? 0 : s[l[ind]];
    long long s_r = (r[ind] == -1) ? 0 : s[r[ind]];
    if (s[ind] != s_l + s_r + 1) return false;

    return func(l[ind], lo, key[ind]) && func(r[ind], key[ind], hi);
}

int main() {
    int n;
    cin >> n;
    key.resize(n, 0);
    l.resize(n, -1);
    r.resize(n, -1);
    s.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> key[i] >> l[i] >> r[i] >> s[i];
    }

    cout << (func(0, minimum, maximum) ? "YES" : "NO" ) << '\n';

    return 0;
}*/

struct Node {
    int v;
    bool hlo, hhi;
    long long lo, hi;
};

int main() {
    int n;
    cin >> n;
    vector<long long> key(n), cnt(n);
    vector<int> l(n), r(n);

    for (int i = 0; i < n; ++i) {
        cin >> key[i] >> l[i] >> r[i] >> cnt[i];
    }
    vector<char> seen(n, 0);
    vector<int> order;
    vector<Node> stack;
    bool fl = true;

    stack.push_back({0, false, false, 0, 0});
    seen[0] = 1;

    while (!stack.empty() && fl) {
        Node cur = stack.back();
        stack.pop_back();
        int v = cur.v;
        order.push_back(v);
        if (cur.hlo && key[v] <= cur.lo) {
            fl = false; break;
        }
        if (cur.hhi && key[v] >= cur.hi) {
            fl = false; break;
        }
        int kids[2] = {l[v], r[v]};
        for (int k = 0; k < 2; k++) {
            int c = kids[k];
            if (c == -1) continue;
            if (c < 0 || c >= n || seen[c]) {
                fl = false;
                break;
            }
            seen[c] = 1;
            if (k == 0)
                stack.push_back({c, cur.hlo, true, cur.lo, key[v]});
            else
                stack.push_back({c, true, cur.hhi, key[v], cur.hi});
        }
    }
    if (fl && order.size() != n) {
        fl = false;
    }

    if (fl) {
        for (int i = n - 1; i >= 0 && fl; --i) {
            int v = order[i];
            long long s = 1;
            if (l[v]  != -1) {
                s += cnt[l[v]];
            }
            if (r[v] != -1) {
                s += cnt[r[v]];
            }
            if (cnt[v] != s) {
                fl = false;
            }
        }
    }
    cout << (fl ? "YES" : "NO") << '\n';

}