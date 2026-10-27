//
// Created by 1 on 07.10.2026.
//
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

    Node root;
    int leafs = 0;

    void insert(const std::string& s)
    {
        Node* v = &root;
        for (char c : s)
        {
            v = &(v->children[c]);
        }

        v->terminal = true;
    }

    void function(Node* v) {
        if (v->children.empty())
        {
            leafs++;
            return;
        }
        for (auto& [c, to] : v->children) {
            function(&to);
        }
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

    Node r = MyTrie.root;
    MyTrie.function(&r);

    std::cout << MyTrie.leafs << '\n';

    return 0;
}