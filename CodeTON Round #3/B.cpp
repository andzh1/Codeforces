#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(n) for(int i = 0; i < n; ++i)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

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


void solve_test_case() {
    get(n)
    string s; cin >> s;
    int max_sum = 0, x1 = 0, x0 = 0;
    for (char ch : s) {
        x0 += (ch == '0');
        x1 += (ch == '1');
    }
    if (x0 == 0) {
        cout << x1 * x1 << '\n';
        return;
    }
    if (x1 == 0) {
        cout << x0 * x0 << '\n';
        return;
    }
    max_sum = x0 * x1;
    x0 = x1 = 0;
    for (int i = 0; i < n; ++i) {
        int ip = i;
        while (ip < n && s[ip] == s[i]) ++ip;
        max_sum = max(max_sum, (ip - i) * (ip - i));
    }
    cout << max_sum << '\n';

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
