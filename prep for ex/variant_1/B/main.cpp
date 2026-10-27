//
// Created by 1 on 28.10.2026.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> L, R, D;

int main() {

    int n, k;
    cin >> n >> k;

    L.assign(n, -1), R.assign(n, -1), D.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
    }

    vector<int> st = {0};
    int cnt = 0;

    while (!st.empty()) {
        int v = st.back();
        st.pop_back();

        if (D[v] == k) ++cnt;

        if (L[v] != -1) {
            D[L[v]] = D[v] + 1;
            st.push_back(L[v]);
        }
        if (R[v] != -1) {
            D[R[v]] = D[v] + 1;
            st.push_back(R[v]);
        }
    }

    cout << cnt << '\n';
    return 0;
}
