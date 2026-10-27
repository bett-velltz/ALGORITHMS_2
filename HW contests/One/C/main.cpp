//
// Created by 1 on 25.09.2026.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <algorithm>

const int64_t m = 1e9 + 9;
const int64_t base = 257;
std::vector<int64_t> r (1000000);
std::vector<long long> pref;
std::vector<long long> pw;

int64_t sum(int64_t a, int64_t b) {
    a %= m;
    b %= m;
    return ((a + b) % m + m) % m;
}

int64_t sub(int64_t a, int64_t b) {
    a %= m;
    b %= m;
    return ((a - b) % m + m) % m;
}

int64_t mul(int64_t a, int64_t b) {
    a %= m;
    b %= m;
    return ((a * b) % m + m) % m;
}

long long hash(int l, int r) {
    return sub(pref[r], mul(pref[l-1], pw[r-l+1])) % m;
}

int main() {
    char ss[100000];
    int n;
    std::scanf("%s", ss);
    std::scanf("%d", &n);
    std::string s(ss);
    int n1 = s.size();

    pref.resize(n1 + 1);
    pw.resize(n1 + 1);

    pw[0] = 1;
    for (int i = 1; i <= n1; i++) {
        pw[i] = pw[i - 1] * base % m;
    }

    pref[0] = 0;
    for (int i = 1; i <= n1; i++) {
        int64_t val = s[i-1] - 'a' + 1;
        pref[i] = (pref[i - 1] * base + val) % m;
    }

    for (int i = 0; i < n; ++i) {
        int l1, l2, r1, r2;
        std::scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        l1++, l2++, r1++, r2++;

        int left = 0, right = std::min((r1-l1+1), (r2-l2+1));
        while (left < right) {
            int mid = (left+right+1) / 2;
            if (hash(l1, l1+mid-1) == hash(l2, l2+mid-1)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int pref_length = left;
        if (pref_length == 0) {
            if (s[l1-1] - 'a' > s[l2-1] - 'a') {
                printf("1\n");
            } else printf("-1\n");
        } else if (pref_length == std::min((r1-l1+1), (r2-l2+1))) {
                if ((r1-l1+1) == (r2-l2+1)) {
                    printf("0\n");
                }
                else if (std::min((r1-l1+1), (r2-l2+1)) == (r1-l1+1)) {
                    printf("-1\n");
                } else {
                    printf("1\n");
                }
            } else {
                if (s[l1+pref_length-1] > s[l2+pref_length-1]) {
                    printf("1\n");
                } else {
                    printf("-1\n");
                }
            }
    }
    return 0;
}