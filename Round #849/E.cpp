#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

// Created by AndZhi 03.02.2023

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
    auto v = read(n);
    int sum = 0;
    int number_of_negative = 0;
    int number_of_0 = 0;
    int min_abs = INT64_MAX;
    loop(i, n) {
        sum += abs(v[i]);
        number_of_negative += v[i] < 0;
        number_of_0 += v[i] == 0;
        min_abs = min(min_abs, abs(v[i]));
    }
    if (number_of_0 > 0 || number_of_negative % 2 == 0) {
        cout << sum << '\n';
        return;
    }
    cout << sum - 2 * min_abs << '\n';
    
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}
