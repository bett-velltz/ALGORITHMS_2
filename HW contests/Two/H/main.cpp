//
// Created by 1 on 10.10.2026.
//

#include <iostream>
#include <algorithm>
#include <cmath>


struct Node {
    long long key;          // ключ
    int height;     // высота поддерева
    Node* left = nullptr;     // левое поддерево
    Node* right = nullptr;    // правое поддерево

    Node(long long k) : key(k), height(1), left(nullptr), right(nullptr) {};
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

Node* rotateLeftRight(Node* p) {       // большой LR-поворот
    p->left = rotateLeft(p->left);
    return rotateRight(p);
}

Node* rotateRightLeft(Node* p) {       // большой RL-поворот
    p->right = rotateRight(p->right);
    return rotateLeft(p);
}

Node* rebalance(Node* p) {
    fixHeight(p);

    if (blnc(p) == 2) {
        if (blnc(p->right) == -1) {
            p->right = rotateRight(p->right);
        }
        return rotateLeft(p);
    }

    if (blnc(p) == -2) {
        if (blnc(p->left) == 1) {
            p->left = rotateLeft(p->left);
        }
        return rotateRight(p);
    }
    return p;
}

Node* insert(Node* p, long long k) {
    if (p == nullptr)
        return new Node(k);            // высота нового листа = 0
    if (k < p->key)
        p->left = insert(p->left, k);
    else if (k > p->key) {
        p->right = insert(p->right, k);
    }
    else {
        return p; // Ключ уже существует
    }
    return rebalance(p);
}

Node* remove(Node* p, long long k) {
    if (p == nullptr) {
        return nullptr;
    }

    if (k < p->key) {
        p->left = remove(p->left, k);
    } else if (k > p->key) {
        p->right = remove(p->right, k);
    } else {
        // Нашли удаляемую вершину

        // Нет левого ребёнка
        if (p->left == nullptr) {
            Node* right = p->right;
            delete p;
            return right;
        }

        // Нет правого ребёнка
        if (p->right == nullptr) {
            Node* left = p->left;
            delete p;
            return left;
        }

        // Есть оба ребёнка:
        // ищем самую правую вершину слева
        Node* r = p->left;

        while (r->right != nullptr) {
            r = r->right;
        }

        // Копируем ключ предшественника
        p->key = r->key;

        // Удаляем предшественника из левого поддерева
        p->left = remove(p->left, r->key);
    }

    // Обновляем высоту и балансируем при подъёме
    return rebalance(p);
}

bool contains(Node* p, long long k) {
    if (p == nullptr) {
        return false;
    }

    if (p->key == k) {
        return true;
    }

    if (k < p->key) {
        return contains(p->left, k);
    }

    return contains(p->right, k);
}


int main() {
    int N;
    std::cin >> N;

    Node* r = nullptr;

    for (int i = 0; i < N; ++i) {
        std::string type;
        std::cin >> type;
        long long x;
        std::cin >> x;

        if (type == "A") {
            r = insert(r, x);
            std::cout << ((r) ? blnc(r) : 0) << '\n';
        }
        else if (type == "D") {
            r = remove(r, x);
            std::cout << ((r) ? blnc(r) : 0) << '\n';
        }
        else {
            std::cout << (contains(r, x) ? "Y" : "N") << '\n';
        }
    }

    return 0;
}