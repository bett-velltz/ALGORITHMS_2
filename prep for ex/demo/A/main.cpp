//
// Created by 1 on 28.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long p, m;
    cin >> n >> p >> m;

    vector<long long> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int l, r;
    cin >> l >> r;
    --l, --r;

    long long pow = 1;
    long long H = 0;

    for (int i = 0; i < n; ++i) {
        if (i >= l && i <= r) continue;

        H = (H + v[i] * pow) % m;
        pow = (p * pow) % m;

    }

    cout << H << '\n';
    return 0;
}