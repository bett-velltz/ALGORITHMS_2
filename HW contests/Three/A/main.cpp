//
// Created by 1 on 14.10.2026.
//

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int cnt_req = 0;
    int cnt_st = 0;

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        int req;
        while (true) {
            std::cin >> req;
            if (req == 0) {
                break;
            }
            cnt_req++;
            cnt++;
        }
        if (cnt > 0) {
            cnt_st++;
        }
    }
    std::cout << cnt_st << ' ' << cnt_req << '\n';
    return 0;
}
