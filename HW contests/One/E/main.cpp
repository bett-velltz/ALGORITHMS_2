//
// Created by 1 on 29.09.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    long long key;
    int left;
    int right;
};

std::vector<Node> v;
std::vector<long long> sums;
std::vector<int> vis;

void postorder(int ind) {
    long long res = v[ind].key;
    if (v[ind].left != -1) {
        postorder(v[ind].left);
        res += sums[v[ind].left];
    }
    if (v[ind].right != -1) {
        postorder(v[ind].right);
        res += sums[v[ind].right];
    }
    sums[ind] = res;
}

int main() {
    int n;
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].key >> v[i].left >> v[i].right;
    }

    sums.resize(n, 0);
    vis.resize(n, 0);

    postorder(0);

    for (int i = 0; i < n; ++i) {
        std::cout << sums[i] << ' ';
    }

    return 0;
}