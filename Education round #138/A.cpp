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

bool is_correct(const vector<pair<int, int>>& pos) {
    for (int i = 0; i < pos.size() - 1; ++i) {
        for (int j = i + 1; j < pos.size(); ++j) {
            if (pos[i].first == pos[j].first) return false;
            if (pos[i].second == pos[j].second) return false;
        }
    }
    return true;
}

void solve_test_case() {
    get(n)
    get(m)
    vector<pair<int, int>> pos (m);
    for (int i = 0; i < m; ++i ) {
        cin >> pos[i].first >> pos[i].second;
    }
    for (int rook = 0; rook < m; ++rook) {
        auto old_pos = pos[rook];
        for (int i = 1; i <= n; ++i) {
            if (pos[rook].first == i) continue;
            pos[rook].first = i;
            if (pos[rook] == old_pos) continue;
            if (is_correct(pos)) {
                cout << "Yes\n";
                return;
            }
        }
        pos[rook] = old_pos;
        for (int i = 1; i <= n; ++i) {
            if (pos[rook].second == i) continue;
            pos[rook].second = i;
            if (pos[rook] == old_pos) continue;
            if (is_correct(pos)) {
                cout << "Yes\n";
                return;
            }
        }
        pos[rook] = old_pos;
    }
    cout << "No\n";
}


signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
