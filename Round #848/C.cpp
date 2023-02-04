#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

// Created by AndZhi 01.02.2023

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

int count_bits(int mask) {
    int ans = 0;
    for (int i = 0; (1 << i) <= mask; ++i) {
        ans += (mask & (1 << i)) != 0;
    }
    return ans;
}

int get_ans_for_mask(const string& a, const string& b, int mask, const vector<char>& all_chars) {
    set<char> current_chars;
    int n = a.size();
    for (int i = 0; i < 10; ++i) {
        if (mask & (1 << i)) {
            current_chars.insert(all_chars[i]);
        }
    }
    vector<bool> equal (n);
    for (int i = 0; i < n; ++i) {
        equal[i] = (a[i] == b[i] || current_chars.count(a[i]));
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!equal[i]) continue;
        int len = 1;
        while (i + len < n && equal[i + len]) ++len;
        ans += len * (len + 1) / 2;
        i += len - 1;
    }
    return ans;
}

void solve_test_case() {
    get(n)
    get(k)
    string a, b;
    cin >> a >> b;
    set<char> all_chars_set;
    loop(i, n) {
        all_chars_set.insert(a[i]);
    }
    if (all_chars_set.size() <= k) {
        cout << n * (n + 1) / 2 << '\n';
        return;
    }
    vector<char> all_chars;
    for (auto& x : all_chars_set) all_chars.push_back(x);
    int ans = 0;
    for (int mask = 0; mask < (1 << 10); ++mask) {
        if (count_bits(mask) == k) {
            ans = max(ans, get_ans_for_mask(a, b, mask, all_chars));
        }
    }
    cout << ans << '\n';

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}
