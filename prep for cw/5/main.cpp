//
// Created by 1 on 21.10.2026.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> ind;

struct Node {
    map<char, Node> children;
    bool terminal = false;
    int ind = 0;
};

struct Trie {
    Node root;
    int cnt = 0;  // номер последней созданной вершины
    int ins_cnt_ver = 0; // сколько вершин создано последней вставкой

    int insert(const string &s) {
        Node* v = &root;
        ins_cnt_ver = 0;

        for (char c : s) {
            if (v->children.find(c) == v->children.end()) {
                v = &(v->children[c]);
                ++cnt;
                v->ind = cnt;
                ++ins_cnt_ver;
                continue;
            }
            v = &(v->children[c]);
        }

        v->terminal = true;
        return v->ind;
    }
};

int main() {
    int n;
    cin >> n;

    Trie my_trie;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int l = 0;
        cout << my_trie.insert(s) << ' ' << my_trie.ins_cnt_ver << '\n';
    }
    return 0;
}