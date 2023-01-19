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

struct S {
    int val;
    int index;


    bool operator<(const S& other) const {
        if (val != other.val) return val < other.val;
        return index > other.index;
    }
};


void solve_test_case() {
    get(n)
    get(m)
    auto a = read(n);
    vector<S> pii(n);
    loop(n) {
        pii[i].val = a[i];
        pii[i].index = i;
    }
    sort(pii.begin(), pii.end());
    int cnt = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i + 1;
    while (m >= 0 && cnt < n) {
        if (m - pii[cnt].val >= 0) {
            m -= pii[cnt].val;
            v[pii[cnt].index]--;
            ++cnt;
        } else break;
    }
    if (cnt > 0) {
        --cnt;
        m += pii[cnt].val;
        v[pii[cnt].index]++;
        int pos = 0;
        ++cnt;
        while (pos < n && v[pos] <= cnt) ++pos;
        if (v[pos] == pos + 1 && a[pos] <= m) {
            --v[pos];
        } 
    }
    int x = 1;
    while (x <= n && v[n - x] > cnt) ++x;
    cout << x << '\n';

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
