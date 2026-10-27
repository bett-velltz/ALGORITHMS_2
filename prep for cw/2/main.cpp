//
// Created by 1 on 20.10.2026.
//
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
long long p, m;

ll sum (ll x, ll y) {
    x %= m;
    y %= m;
    return ((x + y) % m + m) % m;
}

ll sub (ll x, ll y) {
    x %= m;
    y %= m;
    return ((x - y) % m + m) % m;
}

ll mul (ll x, ll y) {
    x %= m;
    y %= m;
    return ((x * y) % m + m) % m;
}


int main() {
    cin >> n >> p >> m;

    vector<long long> even;
    vector<long long> odd;

    for (int i = 1; i <= n; ++i) {
        long long a;
        cin >> a;
        if (i%2) {
            even.emplace_back(a);
            continue;
        }
        odd.emplace_back(a);
    }

    long long H1 = even.size() ? even[0] : 0;
    ll H2 = odd.size() ? odd[0] : 0;

    for (int i = 1; i < even.size(); ++i) {
        H1 = sum(even[i], mul(H1, p));
    }
    for (int i = 1; i < odd.size(); ++i) {
        H2 = sum(odd[i], mul(H2, p));
    }

    cout << H1 << ' ' << H2 << '\n';

    return 0;
}