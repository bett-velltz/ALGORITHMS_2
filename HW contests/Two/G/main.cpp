//
// Created by 1 on 10.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

struct Node {
    long long key;          // ключ
    int height = 0;     // высота поддерева
    Node* left = nullptr;     // левое поддерево
    Node* right = nullptr;    // правое поддерево
};

int func(Node* nd) {
    if (nd == nullptr) {
        return 0;
    }
    int lh = func(nd->left);
    int rh = func(nd->right);

    nd->height = std::max(lh, rh) + 1;
    return nd->height;
}

void fixHeight(Node* nod) {
    int l = (nod->left) ? nod->left->height : 0;
    int r = (nod->right) ? nod->right->height : 0;
    nod->height = std::max(l, r) + 1;
}

int blnc(Node* nod) {
    int l = (nod->left) ? nod->left->height : 0;
    int r = (nod->right) ? nod->right->height : 0;
    return (r-l);
}

Node* rotateLeft(Node* q) {            // малый левый поворот
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

Node* rotateRight(Node* p) {           // малый правый поворот
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);                      // обновляем высоту p после балансировки
    fixHeight(q);                      // обновляем высоту q после балансировки
    return q;                          // q становится новым корнем поддерева
}

Node* rotateRightLeft(Node* p) {
    p->right = rotateRight(p->right);
    return rotateLeft(p);
}

std::vector<Node*> v;

std::vector<Node*> end_v;

void indexing(Node* nod) {
    if (!nod) {
        return;
    }
    end_v.push_back(nod);
    indexing(nod->left);
    indexing(nod->right);
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

    //пересчитали высоты
    func(v[0]);

    //делаем поворот
    if (blnc(v[0]) == 2) {
        if ((blnc(v[0]->right)) == -1) {
            v[0] = rotateRightLeft(v[0]);
        } else {
            v[0] = rotateLeft(v[0]);
        }
    }

    //выводим новое дерево
    std::cout << N << '\n';
    indexing(v[0]);

    std::unordered_map<Node*, int> nw;
    nw.reserve(N);

    for (int i = 0; i < N; ++i) {
        nw[end_v[i]] = i + 1;
    }

    for (Node* node : end_v) {
        int l = (node->left) ? nw[node->left] : 0;
        int r = (node->right) ? nw[node->right] : 0;

        std::cout << node->key << ' ' << l << ' ' << r << '\n';
    }

    return 0;
}