//
// Created by 1 on 28.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int q;
    long long p, m;
    cin >> q >> p >> m;

    long long pow = 1;
    long long H = 0;

    for (int i = 0; i < q; ++i) {
        long long x;
        int c;
        cin >> x >> c;

        for (int j = 0; j < c; ++j) {
            H = (H + x * pow) % m;
            pow = (p * pow) % m;
        }
    }

    cout << H << '\n';
    return 0;
}