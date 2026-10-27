//
// Created by 1 on 20.10.2026.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k;
    long long p, m;

    cin >> n >> p >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long H = a[0];

    for (int i = 1; i < n; ++i) {
        H = ((H * p) + a[i]) % m;
    }

    int b = H % k;

    cout << b << '\n';
    return 0;
}