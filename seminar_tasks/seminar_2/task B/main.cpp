//
// Created by 1 on 25.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node* right = nullptr;
    Node* left = nullptr;
    int height = 0;
    int diff = 0;
};

void visit(Node* v) {
    if (v == nullptr) return;
    int h1 = (v->left ? v->left->height : 0);
    int h2 = (v->right ? v->right->height : 0);
    v->height = max(h1, h2) + 1;
    v->diff = h2 - h1;
}

void dfs(Node* x) {
    if (x == nullptr) return;
    dfs(x->left);
    dfs(x->right);
    visit(x);
}

vector<Node*> v;

int main() {

    int n;
    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; ++i) {
        v[i] = new Node();
    }

    for (int i = 0; i < n; ++i) {
        long long key;
        int l, r;
        cin >> key >> l >> r;
        v[i]->left = (l != -1 ? v[l] : nullptr);
        v[i]->right = (r != -1 ? v[r] : nullptr);
    }

    dfs(v[0]);

    bool fl = true;
    for (int i = 0; i < n; ++i) {
        if (v[i]->diff > 1 || v[i]->diff < -1) {
            fl = false;
            break;
        }
    }

    cout << (fl ? "YES" : "NO") << '\n';
    return 0;
}