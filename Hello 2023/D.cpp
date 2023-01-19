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

struct SparceTable {
    vector<vector<int>> data_;

    SparceTable(const vector<int>& v) {
        int n = v.size();
        int logn = log2(n) + 1;
        data_ = vector<vector<int>>(logn + 1, vector<int>(n));
        data_[0] = v;
        for (int i = 1; i <= logn; ++i) {
            int pow = (1 << (i - 1));
            for (int j = 0; j + pow < n; ++j) {
                data_[i][j] = std::min(data_[i - 1][j], data_[i - 1][j + pow]);
            }
        }
    }

    // [left, right]
    int GetMinOnSegment(int left, int right) const {
        int len = right - left + 1;
        if (len == 1) return data_[0][left];
        int pow = 0;
        while ((1 << (pow + 1)) < len) ++pow;
        int ans1 = data_[pow][left];
        int ans2 = data_[pow][right - (1 << pow) + 1];
        return std::min(ans1, ans2);
    }

    // True, if on (left, right) interval there are no value greater then on left and right position
    bool NoMaxOnInterval(int left, int right) const {
        if (right - left == 1) {
            return true;
        }
        return GetMinOnSegment(left + 1, right - 1) <= data_[0][left]; // Assume that v[left] == v[right]
    }
};


void solve_test_case() {
    get(n)
    auto a = read(n);
    auto b = read(n);
    get(m)
    auto list_of_shavers = read(m);
    map<int, int> shavers;
    loop(m) {
        shavers[list_of_shavers[i]]++;
    }
    loop(n) {
        if (a[i] < b[i]) {
            cout << "NO\n";
            return;
        }
    }
    int logn = log2(n) + 1;
    SparceTable sparse(b);

    map<int, vector<int>> pos_to_cut;
    loop(n) {
        if (b[i] < a[i]) {
            pos_to_cut[b[i]].push_back(i);
        }
    }
    for (const auto& [value, positions]: pos_to_cut) {
        if (positions.size() == 0) {
            continue;
        }
        if (positions.size() == 1) {
            if (shavers[value] >= 1) {
                --shavers[value];
                continue;
            } else {
                cout << "NO\n";
                return;
            }
        }
        for (int i = 1; i < positions.size(); ++i) {
            if (!sparse.NoMaxOnInterval(positions[i - 1], positions[i])) {
                --shavers[value];
                if (shavers[value] < 0) {
                    cout << "NO\n";
                    return;
                } 
            }
        }
        --shavers[value];
        if (shavers[value] < 0) {
            cout << "NO\n";
            return;
        } 
    }
    cout << "YES\n";
}


signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
    // get(n)
    // auto v = read(n);
    // SparceTable sp(v);
    // while (1) {
    //     get(l)
    //     get(r)
    //     cout << sp.GetMinOnSegment(l, r) << endl;
    // }
}
