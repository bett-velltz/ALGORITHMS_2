//
// Created by 1 on 21.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node* right = nullptr;
    Node* left = nullptr;
    int leaves = 0;
    int diff = 0;
};

void visit(Node* v) {
    if (v == nullptr) return;
    int h1  = (v->left ? v->left->leaves : 0);
    int h2  = (v->right ? v->right->leaves : 0);
    if (h1 == 0 && h2 == 0) {
        v->leaves = 1;
    }
    else {
        v->leaves = h1 + h2;
    }
    v->diff = h2 - h1;
}

void function(Node* x) {
    if (x == nullptr) return;
    function(x->left);
    function(x->right);
    visit(x);
}

vector<Node*> v;

int main () {
    int n;
    cin >> n;

    v.resize(n);

    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i] = new Node();
    }

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        v[i]->left = (l != -1 ? v[l] : nullptr);
        v[i]->right = (r != -1 ? v[r] : nullptr);
    }

    function(v[0]);

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (v[i]->diff > 1 || v[i]->diff < -1) {
            ++cnt;
        }
    }

    cout << cnt << '\n';

    return 0;
}