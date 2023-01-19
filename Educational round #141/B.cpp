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


void solve_test_case() {
    get(n)
    int len = n * n;
    vector<int> v(len);
    loop(len) v[i] = i + 1;
    vector<int> qq;
    for (int i = 0; i < len/2; ++i) {
        qq.push_back(v[i]);
        qq.push_back(v[len - 1 - i]);
    }
    if (len % 2) qq.push_back(v[len / 2]);
    int index = 0;
    int h = 0;
    vector<vector<int>> answer(n, vector<int> (n));
    for (int side = n - 1; side >= 0; side -= 2) {
        for (int i = 0; i < side; ++i) {
            answer[h][h + i] = qq[index++];
        }
        for (int i = 0; i < side; ++i) {
            answer[h + i][n - h - 1] = qq[index++];
        }
        for (int i = 0; i < side; ++i) {
            answer[n - 1 - h][n - 1 - h - i] = qq[index++];
        }
        for (int i = 0; i < side; ++i) {
            answer[n - 1 - h - i][h] = qq[index++];
        }
        ++h;
    }
    if (n % 2) {
        answer[n/2][n/2] = qq[index];
    }
    print(answer);

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
