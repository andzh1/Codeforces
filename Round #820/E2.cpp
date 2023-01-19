#include <bits/stdc++.h>

using namespace std;

// #define int64_t int64_t
// #define print cout<<
#define loop(n) for(int64_t i = 0; i < n; ++i)
#define i_am_speed std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

template<typename T = int64_t>
vector<T> read(int64_t n) {
    vector<T> v (n);
    for (T& x : v) cin >> x;
    return v;
}

template<typename T = int64_t>
vector<vector<T>> read(int64_t n, int64_t m) {
    vector<vector<T>> v (n, vector<T> (m));
    for (auto& x : v) x = read<T>(n);
    return v;
}

template<typename T = int64_t>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template<typename T = int64_t>
void print2(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}

int64_t power(int64_t x, int64_t pow) {
    if (pow == 1) return x;
    return x * power(x, pow - 1);
}

void solve_test_case() {
    int64_t l = 1, r = 1e18;
    int64_t q = power(2, 49);
    cout << "? 1 " << q << endl;
    int64_t a;
    cin >> a;
    if (a == -1) r = q - 1;
    else l = max(q, a);
    int cnt = 49;
    while (cnt-- && l < r - 1) {
        int64_t mid = (l + r) / 2;
        cout << "? " << 1 << ' ' << mid << endl;
        int64_t a;
        cin >> a;
        if (a == -1) r = mid - 1;
        else l = max(mid, a);
        l = max(l, a);
    }
    cout << "! " << l << endl;
}

signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int64_t tests = 1;
    // cin >> tests;
    while(tests--) solve_test_case();
}
