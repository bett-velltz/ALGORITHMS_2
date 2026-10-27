//
// Created by 1 on 25.10.2026.
//
//
// Created by 1 on 25.10.2026.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int) s.size();
    vector<int> pi(n, 0);
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && s[i] != s[k])
            k = pi[k - 1];
        if (s[i] == s[k])
            k++;
        pi[i] = k;
    }
    return pi;
}

int main() {

    string s;
    cin >> s;

    auto p = prefix_function(s);

    for (long long i = 0; i < s.size(); ++i ){
        cout << p[i] << ' ';
    }
    cout << '\n';

    return 0;
}