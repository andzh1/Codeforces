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
    string s1; cin >> s1;
    string s2; cin >> s2;
    bool cnt = 0;
    int number = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '0') continue;
        int ip = i;
        while (ip < n && s1[ip] == '1') ++ip;
        cnt = !cnt;
        ++number;
        i = ip - 1;
    }
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '0') {
            if (cnt) s2[i] = '0' + (1 - (s2[i] - '0'));
        } else {
            int ip = i;
            while (ip < n && s1[ip] == '1') ++ip;
            
            for (int j = i; j < ip && !cnt; ++j) {
                s2[j] = '0' + (1 - (s2[j] - '0'));
            }
            i = ip - 1;
        }
    }
    if (s2 != string(n, '1') && s2 != string(n, '0')) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (s2 == string(n, '1')) number += 3;
    cout << number << '\n';
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '0') continue;
        int ip = i;
        while (ip < n && s1[ip] == '1') ++ip;
        cout << i+1 << ' ' << ip << '\n';
        i = ip - 1;
    }
    if (s2 == string(n, '1')) {
        cout << "1 1\n";
        cout << "2 " << n << '\n';
        cout << "1 " << n << '\n';
    }

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
