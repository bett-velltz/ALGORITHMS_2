//
// Created by 1 on 07.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Node
{
    std::map<char, Node> children;
    bool terminal = false;
};

//---------------------------------------------------------

struct Trie
{
    int dpth = 0;
    Node root;

    void insert(const std::string& s)
    {
        int this_dpth = 0;
        Node* v = &root;
        for (char c : s)
        {
            auto flag = v->children.find(c);
            if (flag != v->children.end()) {
                this_dpth++;
            }
            v = &(v->children[c]);
        }
        v->terminal = true;
        dpth = std::max(dpth, this_dpth);
    }
};

int main() {
    Trie MyTrie;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        MyTrie.insert(s);
    }

    std::cout << MyTrie.dpth << '\n';
    return 0;
}