#include <bits/stdc++.h>

using namespace std;

#define int int64_t
// #define print cout<<
#define loop(n) for(int i = 0; i < n; ++i)
#define i_am_speed std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

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
    int n;
    cin >> n;
    string t;
    cin >> t;
    string s;
    for (int i = n - 1; i >= 0; --i) {
        if (t[i] != '0') s.push_back('a' + t[i] - '1');
        else {
            int c = t[i-1] - '1' + 10 * (t[i-2] - '0');
            s.push_back('a' + c);
            i -= 2;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
