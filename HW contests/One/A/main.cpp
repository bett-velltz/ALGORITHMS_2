//
// Created by 1 on 23.09.2026.
//

#include <iostream>
#include <cstdint>

uint32_t reverse(const uint32_t &x) {
    uint32_t ans = x - (x << 16);
    //---------------------------------------------
    uint32_t ansy = ans;
    uint32_t ansx = ansy & (0xFFFFFFFF << 21);
    for (int i = 31; i >= 11; --i) {
        int bit1 = (ansx >> i) & 1;
        int bit2 = (ansy >> (i-11)) & 1;
        ansx += (bit1 ^ bit2) * (1 << (i-11));
    }
    ans = ansx;
    //---------------------------------------------
    ansy = ans;
    for (int i = 0; i < 11; ++i)
    {
        ans = ansy - (ans << 3);
    }
    //---------------------------------------------
    ansy = ans;
    ansx = ansy & (0xFFFFFFFF << 26);
    for (int i = 31; i >= 6; --i) {
        int bit1 = (ansx >> i) & 1;
        int bit2 = (ansy >> (i-6)) & 1;
        ansx += (bit1 ^ bit2) * (1 << (i-6));
    }
    ans = ansx;
    //---------------------------------------------
    ansy = ans;
    for (int i = 0; i < 4; ++i) {
        ans = ansy - (ans << 10);
    }
    return ans;
}

int main() {
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        uint32_t n;
        std::cin >> n;

        std::cout << reverse(n) << '\n';
    }
    return 0;
}