//
// Created by 1 on 29.09.2026.
//
//
// Created by 1 on 29.09.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Node {
    std::map<char, Node> children;
    bool terminal = false;
};

struct Trie {

    Node root;

    void insert(const std::string &s) {
        Node *v = &root;

        for (char c: s) {
            v = &(v->children[c]);
        }

        v->terminal = true;
    }

    bool has(const std::string &s) {
        Node *v = &root;
        for (char c: s) {
            auto p = v->children.find(c);
            if (p == v->children.end()) {
                return false;
            }
            v = &(v->children[c]);
        }
        if (v->terminal) {return true;}
        return false;
    }
};

int main() {

    long long n;
    std::cin >> n;

    Trie MyTrie;

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        if (!MyTrie.has(s)) {
            MyTrie.insert(s);
            cnt++;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}