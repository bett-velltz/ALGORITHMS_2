//
// Created by 1 on 21.10.2026.
//

//
// Created by 1 on 21.10.2026.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    map<char, Node> children;
    bool terminal = false;
    int cnt_starts = 0;
};

struct Trie {
    Node root;

    void insert(const string &s) {
        Node* v = &root;

        for (char c : s) {
            v = &(v->children[c]);
            v->cnt_starts++;
        }

        v->terminal = true;
    }

     int func(const string &s) {
         Node* v = &root;

         for (char c : s) {
             v = &(v->children[c]);
         }
         return v->cnt_starts;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Trie my_trie;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        my_trie.insert(s);
    }


    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        cout << my_trie.func(s) << '\n';
    }

    return 0;
}