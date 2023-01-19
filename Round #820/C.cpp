#include <bits/stdc++.h>

using namespace std;

#define int int64_t
// #define print cout<<
#define loop(n) for(int i = 0; i < n; ++i)
#define i_am_speed std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

template<typename T = int>
vector<T> read(int n) {
    vector<T> v (n);
    for (T& x : v) cin >> x;
    return v;
}

template<typename T = int>
vector<vector<T>> read(int n, int m) {
    vector<vector<T>> v (n, vector<T> (m));
    for (auto& x : v) x = read<T>(n);
    return v;
}

template<typename T = int>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template<typename T = int>
void print2(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}

void solve_test_case() {
    // cin >> n;
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> letters(26);
    for (int i = 1; i < n - 1; ++i) letters[s[i] - 'a'].push_back(i);
    int inc = 1;
    if (s[0] > s[n-1]) inc = -1;
    int ans = 1;
    vector<int> answ;
    for (int i = s[0] - 'a'; i != s[n-1] - 'a'; i += inc) {
        ans += letters[i].size();
        for (int l : letters[i]) {
            answ.push_back(l);
        }
    }
    ans += letters[s[n-1] - 'a'].size();
    for (int l : letters[s[n-1] - 'a']) {
        answ.push_back(l);
    }
    cout << abs(s[0] - s[n-1])<< ' ' << answ.size() + 2 << '\n' << "1 ";
    // print(answ)
    for (int& x : answ) cout << x+1 << ' ';
    cout << n << '\n';
}

signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
