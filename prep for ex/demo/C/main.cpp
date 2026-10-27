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

    string s, p;
    cin >> s >> p;

    string find = p + '$' + s;

    auto z = z_function(find);
    int cnt = 0;

    for (int i = (int)p.size(); i < (int)p.size() + (int)s.size() + 1; ++i) {
        if (z[i] == p.size()) ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}
