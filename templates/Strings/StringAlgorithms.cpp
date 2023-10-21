#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define vi vector<int>
#define get(a) int a; cin >> a;
#define repeat(n) for(int i = 0; i < n; ++i)
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(k, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define foreach(val, container) for (const auto& val : container)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

#include <iostream>
#include <vector>

std::vector<int> prefixFunction(const std::string& str) {
    size_t n = str.length();
    std::vector<int> answer (n);
    for (size_t i = 1; i < n; ++i) {
        int j = answer[i - 1];
        while (j > 0 && str[i] != str[j])
            j = answer[j - 1];
        if (str[i] == str[j])  ++j;
        answer[i] = j;
    }
    return answer;
}

// Returns vector of all positions 'pos' such that substr = text.substr(pos, substr.length())
std::vector<int> getSubstringOccurrences(const std::string& text, const std::string& substr, char delim = '#') {
    std::string str = substr + delim + text;
    auto prefixes = prefixFunction(str);
    std::vector<int> answer;
    for (int i = 0; i < text.size(); ++i) {
        if (prefixes[i + substr.size() + 1] == substr.size()) answer.push_back(i - substr.size() + 1);
    }
    return answer;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    // freopen("tests.txt", "right", stdin);
    // freopen("output.txt", "w", stdout);
    std::string text, substr;
    std::cin >> text >> substr;
    auto answer = getSubstringOccurrences(text, substr);
    for (const int& z : answer) std::cout << z << ' ';
    std::cout << '\n';
}
