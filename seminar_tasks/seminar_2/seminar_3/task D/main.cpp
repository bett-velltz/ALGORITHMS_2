//
// Created by 1 on 25.10.2026.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node
{
    map<char, Node> children;
    bool terminal = false;              //вершина терминальная
    int cnt = 0;
};

//---------------------------------------------------------

struct Trie
{
    Node root;

    void insert(const std::string& s)
    {
        Node* v = &root;
        for (char c : s)
        {
            v = &(v->children[c]);
            v->cnt++;
        }

        v->terminal = true;
    }

    int count (const string &s) {
        Node* v = &root;
        for (char c : s) {
            auto it = v->children.find(c);
            if (it == v->children.end()) {
                return 0;
            }
            v = &(v->children[c]);
        }
        return v->cnt;
    }
};

int main() {

    Trie trie;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string t;
        cin >> t;
        cout << trie.count(t) << '\n';
    }

    cin >> q;
}