//
// Created by 1 on 21.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n, 0);

    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r-i+1, z[i-l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main() {
    string s;
    string p;
    cin >> s >> p;

    auto p_rev = p;
    reverse(p_rev.begin(), p_rev.end());

    auto s1 = p + '$' + s;
    auto s2 = p_rev + '$' + s;

    auto z1 = z_function(s1);
    auto z2 = z_function(s2);

    int cnt1 = 0, cnt2 = 0;

    for (int i = p.size() + 1; i < s1.size(); ++i) {
        if (z1[i] >= p.size()) {
            cnt1 ++;
        }
    }

    for (int i = p.size() + 1; i < s2.size(); ++i) {
        if (z2[i] >= p.size()) {
            cnt2 ++;
        }
    }

    cout << cnt1 << ' ' << cnt2 << '\n';
    return 0;
}
