//
// Created by 1 on 28.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> L, R, H;

int h(int v) {
    return v == -1 ? 0 : H[v];
}

int main() {
    int n;
    cin >> n;

    L.assign(n, -1), R.assign(n, -1), H.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
    }

    vector<int> order, st = {0};
    while (!st.empty()) {
        int v = st.back();
        st.pop_back();
        order.push_back(v);
        if (L[v] != -1) st.push_back(L[v]);
        if (R[v] != -1) st.push_back(R[v]);
    }

    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        H[v] = max(h(L[v]), h(R[v])) + 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(h(L[i]) - h(R[i])) <= 1) {
            ++cnt;
        }
    }

    cout << cnt << '\n';
    return 0;
}

//st.push_back(x): положить на вершину стека
//st.back(): посмотреть верхний элемент
//st.pop_back(): снять верхний элемент
//st.empty(): проверка на пустоту