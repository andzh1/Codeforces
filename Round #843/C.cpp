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

template<typename T = int>
void sortv(vector<T>& v) {
    std::sort(v.begin(), v.end());
} 

int solve(int n, int res) {
    if (n < res) {
        // cout << "-1\n";
        return -1;
    }
    if (n == res) {
        return n;
    }
    vector<int> nv, resv;
    while (n > 0) {
        nv.push_back(n % 2);
        n /= 2;
    }
    while (res > 0) {
        resv.push_back(res % 2);
        res /= 2;
    }
    int sz = max(nv.size(), resv.size());
    nv.resize(sz);
    resv.resize(sz);
    reverse(nv.begin(), nv.end());
    reverse(resv.begin(), resv.end());
    int pow = 0;
    loop(sz) {
        if (nv[i] < resv[i]) {
            // cout << "-1\n";
            return -1;
        }
    }
    for (; pow < sz; ++pow) {
        if (nv[pow] == resv[pow]) continue;
        break;
    }
    for (int i = pow; i < sz; ++i) {
        if (resv[i]) {
            return -1;
        }
    }
    if (pow == 0) {
        // cout << (1ll << sz) << '\n';
        return (1ll << sz);
    }
    if (nv[pow - 1]) {
        return -1;
    }
    nv[pow - 1] = 1;
    int ans = 0;
    for (int i = 0; i < pow; ++i) {
        ans = ans * 2ll + nv[i];
    }
    for (int i = pow; i < sz; ++i) {
        ans *= 2ll;
        if (resv[i]) {
            return -1;
        }
    }
    return ans;
}

int solve2(int n, int x) {
    int res = n;
    while (res > x) {
        res &= (n + 1);
        ++n;
    }
    if (res == x) return n;
    return -1;
}

void test() {
    int n = rand() % 100;
    int x = rand() % 100;
    auto a = solve(n, x), b = solve2(n, x);
    if (a != b) {
        cout << n << ' ' << x << ' ' << a << ' ' << b << '\n';
        exit(0);
    }
}

void solve_test_case() {
    get(n)
    get(res)
    if (n < res) {
        cout << "-1\n";
        return;
    }
    if (n == res) {
        cout << n << '\n';
        return;
    }
    vector<int> nv, resv;
    while (n > 0) {
        nv.push_back(n % 2);
        n /= 2;
    }
    while (res > 0) {
        resv.push_back(res % 2);
        res /= 2;
    }
    int sz = max(nv.size(), resv.size());
    nv.resize(sz);
    resv.resize(sz);
    reverse(nv.begin(), nv.end());
    reverse(resv.begin(), resv.end());
    int pow = 0;
    loop(sz) {
        if (nv[i] < resv[i]) {
            cout << "-1\n";
            return;
        }
    }
    for (; pow < sz; ++pow) {
        if (nv[pow] == resv[pow]) continue;
        break;
    }
    for (int i = pow; i < sz; ++i) {
        if (resv[i]) {
            cout << "-1\n";
            return;
        }
    }
    if (pow == 0) {
        cout << (1ll << sz) << '\n';
        return;
    }
    if (nv[pow - 1]) {
        cout << "-1\n";
        return;
    }
    nv[pow - 1] = 1;
    int ans = 0;
    for (int i = 0; i < pow; ++i) {
        ans = ans * 2ll + nv[i];
    }
    for (int i = pow; i < sz; ++i) {
        ans *= 2ll;
        if (resv[i]) {
            cout << "-1\n";
            return;
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
    while(tests--) solve_test_case();
    // while(1) test();
}

// 9503 19 16384 -1