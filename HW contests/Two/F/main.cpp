//
// Created by 1 on 10.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    long long key;          // ключ
    int height = 0;     // высота поддерева
    Node* left = nullptr;     // левое поддерево
    Node* right = nullptr;    // правое поддерево
};

std::vector<Node*> v;

int func(Node* nd) {
    if (nd == nullptr) {
        return 0;
    }
    int lh = func(nd->left);
    int rh = func(nd->right);

    nd->height = std::max(lh, rh) + 1;
    return nd->height;
}

int main() {
    int N;
    std::cin >> N;
    v.resize(N);

    for (int i = 0; i < N; ++i) {
        v[i] = new Node();
    }

    for (int i = 0; i < N; ++i) {
        long long K;
        int L, R;
        std::cin >> v[i]->key >> L >> R;
        if (L) {
            v[i]->left = v[L-1];
        }
        if (R) {
            v[i]->right = v[R-1];
        }
    }

    func(v[0]);

    for (int i = 0; i < N; ++i) {
        int l = (v[i]->left) ? v[i]->left->height : 0;
        int r = (v[i]->right) ? v[i]->right->height : 0;
        std::cout << r-l << '\n';
    }
    return 0;
}