//
// Created by 1 on 25.10.2026.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> z_function(string s) {
    int n = (long long) s.size();
    vector<long long> z(n, 0);
    long long l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        // если мы уже видели этот символ
        if (i <= r)
            // то мы можем попробовать его инициализировать z[i - l],
            // но не дальше правой границы: там мы уже ничего не знаем
            z[i] = min(r - i + 1, z[i - l]);
        // дальше каждое успешное увеличение z[i] сдвинет z-блок на единицу
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        // проверим, правее ли мы текущего z-блока
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main() {

    string s;
    cin >> s;

    auto z = z_function(s);
    z[0] = s.size();

    for (long long i = 0; i < s.size(); ++i ){
        cout << z[i] << ' ';
    }
    cout << '\n';
    return 0;
}