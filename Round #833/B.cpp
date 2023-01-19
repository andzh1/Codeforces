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

bool correct(vector<int>& symbols) {
    int diff_number = 0;
    for (int j = 0; j < 10; ++j) {
        diff_number += (symbols[j] > 0);
    }
    for (int j = 0; j < 10; ++j) {
        if(symbols[j] > diff_number) return false;
    }
    return true;
}

void solve_test_case() {
    get(n)
    string s;
    cin >> s;
    int ans = s.size();
    for (int length = 2; length <= 100 && length <= n; ++length) {
        vector<int> symbols (10);
        for (int j = 0; j < length; ++j) {
            symbols[s[j] - '0']++;
        }
        ans += correct(symbols);
        for (int i = 1; i <= n - length; ++i) {
            symbols[s[i - 1] - '0']--;
            symbols[s[i + length - 1] - '0']++;
            ans += correct(symbols);
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
