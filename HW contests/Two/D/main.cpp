//
// Created by 1 on 10.10.2026.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <set>
#include <queue>

struct Node {
    std::map<char, Node*> next;      // ребра бора
    std::map<char, Node*> autoLink;  // переходы автомата
    std::vector<int> terminal;       // номера слов, оканчивающихся здесь
    Node* sufLink = nullptr;
    Node* termLink = nullptr;
};

class Trie {
    Node* root = new Node();
    std::set<char> abc;   // алфавит, встреченный в словаре
    int count = 0;        // сколько слов добавлено (нумерация с 0)

public:
    void insert(const std::string& s) {
        Node* v = root;
        for (char ch : s) {
            abc.insert(ch);
            if (v->next.find(ch) == v->next.end()) {
                v->next[ch] = new Node();
            }
            v = v->next[ch];
        }
        v->terminal.push_back(count++);
    }
    // build() и find()

    std::set<int> find(const std::string& s) {
        std::set<int> index;  // номера найденных слов
        Node* v = root;
        for (auto ch : s) {
            if (abc.find(ch) == abc.end()) {
                v = root;      // неизвестный символ: ни одно слово через него не проходит
                continue;
            }
            v = v->autoLink[ch];
            auto p = v;
            while (p->termLink) {
                p = p->termLink;
                auto& term = p->terminal;
                index.insert(term.begin(), term.end());
            }
            if (!v->terminal.empty()) {
                auto& term = v->terminal;
                index.insert(term.begin(), term.end());
            }
        }
        return index;
    }

    void build() {
        root->sufLink = root;
        std::queue<Node*> q;

        // инициализация корня
        for (auto& [ch, to] : root->next) {
            to->sufLink = root;
            q.push(to);
        }
        for (char ch : abc) {
            if (root->next.find(ch) != root->next.end()) {
                root->autoLink[ch] = root->next[ch];
            } else {
                root->autoLink[ch] = root;
            }
        }

        // BFS по остальным вершинам
        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            // дети: суффиксные и терминальные ссылки
            for (auto& [ch, to] : v->next) {
                to->sufLink = v->sufLink->autoLink[ch];
                if (!to->sufLink->terminal.empty()) {
                    to->termLink = to->sufLink;
                } else {
                    to->termLink = to->sufLink->termLink;
                }
                q.push(to);
            }

            // автоматные переходы по всему алфавиту
            for (char ch : abc) {
                if (v->next.find(ch) != v->next.end()) {
                    v->autoLink[ch] = v->next[ch];
                } else {
                    v->autoLink[ch] = v->sufLink->autoLink[ch];
                }
            }
        }
    }
};

int main() {
    Trie trie;

    std::string txt;
    std::cin >> txt;
    int M;
    std::cin >> M;

    for (int i = 0; i < M; ++i) {
        std::string word;
        std::cin >> word;
        trie.insert(word);
    }
    trie.build();
    auto res = trie.find(txt);

    for (int i = 0; i < M; ++i) {
        std::cout << (res.find(i) != res.end() ? "Yes" : "No") << '\n';
    }

    return 0;
}