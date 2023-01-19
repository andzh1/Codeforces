#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(n) for(int i = 0; i < n; ++i)
#define i_am_speed std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

int modpow(const int& x, const int& power, const int& mod) {
    if (power == 0) return 1;
    if (power == 1) return x;
    int sqrt = modpow(x, power / 2, mod);
    sqrt *= sqrt;
    sqrt %= mod;
    if (power % 2) sqrt *= x;
    sqrt %= mod;
    return sqrt;
}

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
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}
// Created by AndZhi on 03/01/23.

void solve_test_case() {
    get(n)
    string s; 
    cin >> s;
    // int max_left = -1, max_right = n;
    // for (int i = 0; i < n; ++i) {
    //     if (s[i] == 'L') {
    //         max_left = max(max_left, i - 1);
    //     } else {
    //         max_right = min(max_right, i + 1); 
    //     }
    // }
    // if (max_left > max_right) {
    //     cout << "0\n";
    //     return;
    // }
    int ans = -1;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == 'L' && s[i] == 'R') {
            ans = i;
            continue;
        }
        if (s[i - 1] == 'R' && s[i] == 'L') {
            cout << 0 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}


signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
