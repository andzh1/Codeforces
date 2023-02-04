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

struct Point {
    int value;
    int index;
    bool close_to_left;
    bool operator<(const Point& other) const {
        if (value + index != other.value + other.index) return value + index < other.value + other.index;
        return index < other.index;
    }
};


void solve_test_case() {
    get(n)
    get(c)
    auto a = read(n);
    if (n == 1) {
        cout << (c >= a[0] + 1) << '\n';
        return;
    }
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        points[i].value = a[i];
        points[i].index = min(i + 1, n - i);
        points[i].close_to_left = i + 1 <= n - i;
    }
    
    sort(points.begin(), points.end());
    int ans = 0;
    bool has_left = false;
    while (c > 0 && ans < n) {
        if (c >= points[ans].index + points[ans].value) {
            c -= (points[ans].index + points[ans].value);
            if (points[ans].close_to_left) has_left = 1;
            ++ans;
        } else break;
    }
    if (has_left) {
        cout << ans << '\n';
        return;
    }
    for (int i = 0; i < ans; ++i) {
        if (c >= n - 2 * points[i].index + 1) {
            cout << ans << '\n';
            return;
        }
    }
    int min_cost = INT64_MAX;
    for (int i = ans; i < n; ++i) {
        if (points[i].close_to_left) {
            min_cost = min(min_cost, points[i].index + points[i].value);
            continue;
        }
        min_cost = min(min_cost, points[i].value + n - points[i].index + 1);
    }
    c -= min_cost;
    while (c < 0 && ans > 0) {
        --ans;
        c += points[ans].index + points[ans].value;
    }
    if (c >= 0) {
        cout << ans + 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}
