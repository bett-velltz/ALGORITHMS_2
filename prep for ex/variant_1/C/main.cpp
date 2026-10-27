//
// Created by 1 on 28.10.2026.
//
//
// Created by 1 on 28.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }

    }
    return z;
}

int main() {

    string s, t;
    cin >> s >> t;

    string find = t + '$' + s;

    auto z = z_function(find);
    int m = 0;

    for (int i = (int)t.size() + 1; i < (int)t.size() + (int)s.size() + 1; ++i) {
        if (z[i] + i - 1 - t.size() == s.size()) m = max(m, z[i]);
    }
    cout << (t.size() + s.size() - m) << '\n';
    return 0;
}
