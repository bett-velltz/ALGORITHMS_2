//
// Created by 1 on 25.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long key;          // ключ
    int height;     // высота поддерева
    Node* left;     // левое поддерево
    Node* right;    // правое поддерево

    Node(long long k) : key(k), height(0), left(nullptr), right(nullptr) {}
};

struct AVL_Trie {

    Node* root = nullptr;

    int getHeight(Node* p) {
        return (p ? p->height : -1);
    }

    void fixHeight(Node* p) {
        p->height = 1 + max(getHeight(p->left), getHeight(p->right));
    }

    int bal(Node* p) { return getHeight(p->right) - getHeight(p->left); }

    Node* rotateRight(Node* p) {           // малый правый поворот
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixHeight(p);                      // обновляем высоту p после балансировки
        fixHeight(q);                      // обновляем высоту q после балансировки
        return q;                          // q становится новым корнем поддерева
    }

    Node* rotateLeft(Node* q) {            // малый левый поворот
        Node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixHeight(q);
        fixHeight(p);
        return p;
    }

    /*Node* rotateLeftRight(Node* p) {       // большой LR-поворот
        p->left = rotateLeft(p->left);
        return rotateRight(p);
    }

    Node* rotateRightLeft(Node* p) {       // большой RL-поворот
        p->right = rotateRight(p->right);
        return rotateLeft(p);
    }*/

    Node* rebalance(Node* p) {
        fixHeight(p);
        if (bal(p) == -2) {
            if (bal(p->left) == 1)               // LR: большой левый-правый
                p->left = rotateLeft(p->left);
            return rotateRight(p);              // LL, либо вторая половина LR
        }
        if (bal(p) == 2) {
            if (bal(p->right) == -1)              // RL: большой правый-левый
                p->right = rotateRight(p->right);
            return rotateLeft(p);               // RR, либо вторая половина RL
        }
        return p;
    }

    Node* insert(Node* p, long long k) {
        if (!p) return new Node(k);
        if (k < p->key) p->left = insert(p->left, k);
        else if (k > p->key) p->right = insert(p->right, k);
        else return p;                       // ключ уже есть
        return rebalance(p);
    }

    bool exists(long long k) {
        Node* p = root;
        while (p) {
            if (k == p->key) return true;
            p = (k < p->key) ? p->left : p->right;
        }
        return false;
    }

    Node* findMin(Node* p) {
        while (p->left) p = p->left;
        return p;
    }

    Node* removeMin(Node* p) {
        if (!p->left) return p->right;
        p->left = removeMin(p->left);
        return rebalance(p);
    }

    Node* erase(Node* p, long long k) {
        if (!p) return nullptr;
        if (k < p->key) p->left = erase(p->left, k);
        else if (k > p->key) p->right = erase(p->right, k);
        else {
            Node* L = p->left;
            Node* R = p->right;
            delete p;
            if (!R) return L;
            Node* m = findMin(R);
            m->right = removeMin(R);
            m->left = L;
            return rebalance(m);
        }
        return rebalance(p);
    }

};

int main() {

    AVL_Trie tree;

    string op;
    long long x;
    while (cin >> op >> x) {
        if (op == "insert") {
            tree.root = tree.insert(tree.root, x);
        } else if (op == "delete") {
            tree.root = tree.erase(tree.root, x);
        } else if (op == "exists") {
            cout << (tree.exists(x) ? "true" : "false") << '\n';
        }
    }

    return 0;
}