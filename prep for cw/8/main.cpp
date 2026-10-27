//
// Created by 1 on 21.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {

    int n;
    cin >> n;

    vector<int> L(n, -1), R(n, -1), a(n, 0), b(n, 0);

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (r != -1) {
            R[i] = r;
        }
        if (l != -1) {
            L[i] = l;
        }
    }

    vector<int> order;
    order.emplace_back(0);

    for (int i = 0; i < order.size(); ++i) {
        if (L[order[i]] != -1) {
            order.emplace_back(L[order[i]]);
        }
        if (R[order[i]] != -1) {
            order.emplace_back(R[order[i]]);
        }
    }

    bool balanced = true;
    for (int i = order.size() - 1; i >= 0; --i) {
        int v = order[i];

        if (L[v] == -1) {
            a[v] = 1;
        }
        else {
            a[v] = a[L[v]] + b[L[v]];
        }

        if (R[v] == -1) {
            b[v] = 1;
        }
        else {
            b[v] = a[R[v]] + b[R[v]];
        }

        if (max(a[v], b[v]) > 2 * min(a[v], b[v])) {
            balanced = false;
            break;
        }
    }
    if (balanced) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << '\n';

    return 0;
}