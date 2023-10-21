//
// Created by andrey on 20.08.23.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

struct Node {
    std::map<char, int> edges;
    bool is_terminate = 0;
    int parent = -1;
    char char_from_parent = 0;
    int link = -1;
    int long_link = -1;
    std::map<char, int> go;
    std::vector<int> indexes_of_terminate;
};

struct Trie {

    std::vector<Node> _nodes;

    void insert(const std::string& s, int index) {
        int ip = 0;
        for (const char& ch : s) {
            if (_nodes[ip].edges.find(ch) == _nodes[ip].edges.end()) {
                _nodes[ip].edges[ch] = (int)_nodes.size();
                _nodes.emplace_back();
                _nodes.back().parent = ip;
                _nodes.back().char_from_parent = ch;
            }
            ip = _nodes[ip].edges[ch];
        }
        _nodes[ip].is_terminate = true;
        _nodes[ip].indexes_of_terminate.push_back(index);
    }

    bool find(const std::string& s) const {
        return findPos(s) != -1;
    }

    int findPos(const std::string& s) const {
        int ip = 0;
        for (const char& ch : s) {
            if (_nodes[ip].edges.find(ch) == _nodes[ip].edges.end()) {
                return -1;
            }
            ip = _nodes[ip].edges.at(ch);
        }
        return (_nodes[ip].is_terminate)? ip : -1;
    }

    Trie() {
        _nodes.resize(1);
    }

    explicit Trie(const std::vector<std::string>& strings) {
        _nodes.resize(1);
        for (int i = 0; i < strings.size(); ++i) {
            insert(strings[i], i);
        }
    }

    int go(int vertice, char ch);
    int link(int vertice);
    int long_link(int vertice);
};


int Trie::link(int vertice) {
    if (_nodes[vertice].link == -1) {
        if (vertice == 0 | _nodes[vertice].parent == 0) {
            _nodes[vertice].link = 0;
        } else {
            _nodes[vertice].link = go(link(_nodes[vertice].parent),
                                      _nodes[vertice].char_from_parent);
        }
    }
    return _nodes[vertice].link;
}

int Trie::go(int vertice, char ch) {
    if (_nodes[vertice].go.find(ch) ==  _nodes[vertice].go.end()) {
        if (_nodes[vertice].edges.find(ch) != _nodes[vertice].edges.end()) {
            _nodes[vertice].go[ch] = _nodes[vertice].edges[ch];
        } else {
            if (vertice == 0) _nodes[vertice].go[ch] = 0;
            else _nodes[vertice].go[ch] = go(link(vertice), ch);
        }
    }
    return _nodes[vertice].go[ch];
}

int Trie::long_link(int vertice) {
    if (_nodes[vertice].long_link == -1) {
        int link_v = link(vertice);
        if (_nodes[link_v].is_terminate) {
            _nodes[vertice].long_link = link_v;
        } else {
            if (link_v == 0) {
                _nodes[vertice].long_link = 0;
            } else {
                _nodes[vertice].long_link = long_link(link_v);
            }
        }
    }
    return _nodes[vertice].long_link;
}


// Counts number of substrings entries
std::vector<std::vector<int>> numberOfSubstringEntries(const std::vector<std::string>& substrings, const std::string& text) {
    Trie trie(substrings);
    int current_vertice = 0;
    std::vector<std::vector<int>> positions = std::vector<std::vector<int>>(substrings.size(), std::vector<int>());
    for (int i = 0; i < text.size(); ++i) {
        current_vertice = trie.go(current_vertice, text[i]);
        if (trie._nodes[current_vertice].is_terminate) {
            for (auto index : trie._nodes[current_vertice].indexes_of_terminate) {
                positions[index].push_back(i + 2 - (int)substrings[index].size());
            }
        }
        int current_link = trie.long_link(current_vertice);
        while (current_link) {
            for (auto index : trie._nodes[current_link].indexes_of_terminate) {
                positions[index].push_back(i + 2 - (int)substrings[index].size());
            }
            current_link = trie.long_link(current_link);
        }
    }

    return positions;
}



signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::string text;
    std::cin >> text;
    std::cin >> n;
    std::vector<std::string> input (n);
    for (auto& s : input) std::cin >> s;
    numberOfSubstringEntries(input, text);

}
