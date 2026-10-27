//
// Created by 1 on 21.10.2026.
//

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

    auto s1_z = p + '$' + s;

    string p2, p3;
    for (int i = 0; i < p.size(); ++i) {
        if (i == p.size() - 1) {
            continue;
        }
        if (i == p.size() - 2) {
            p2 += p[i];
        } else {
            p2 += p[i];
            p3 += p[i];
        }
    }

    auto s2_z = p2 + '$' + s;
    auto s3_z = p3 + '$' + s;

    auto z1 = z_function(s1_z);
    auto z2 = z_function(s2_z);
    auto z3 = z_function(s3_z);

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for (int i = p.size() + 1; i < s1_z.size(); ++i) {
        if (z1[i] >= p.size()) {
            cnt1++;
        }
    }

    for (int i = p2.size() + 1; i < s2_z.size(); ++i) {
        if (z2[i] >= p2.size()) {
            cnt2++;
        }
    }
    for (int i = p3.size() + 1; i < s3_z.size(); ++i) {
        if (z3[i] >= p3.size()) {
            cnt3++;
        }
    }

    cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';
    return 0;
}
