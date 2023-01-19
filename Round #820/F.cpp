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
void print2(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}


void solve_test_case() {
    string s;
    cin >> s;
    int m, w, n = s.size();
    cin >> w >> m;
    vector<int> in (n);
    for (int i = 0; i < n; ++i) in[i] = s[i] - '0';
    vector<int> index_of_rem[9];
    int sum = 0;
    for (int i = 0; i < w - 1; ++i) sum += in[i];
    for (int i = w - 1; i < n; ++i) {
        sum += in[i];
        if (index_of_rem[sum % 9].size() < 2) index_of_rem[sum % 9].push_back(i - w + 1);
        sum -= in[i-w + 1];
    }
    vector<int> prefix_sum (n);
    prefix_sum[0] = in[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + in[i];
        prefix_sum[i] %= 9;
    }
    while(m--) {
        int l, r, k;
        cin >> l >> r >> k;
        int sum = 9 + prefix_sum[r - 1];
        if (l != 1) sum -= prefix_sum[l - 2];
        sum %= 9;
        pair<int, int> ans ({n+1, n+1});
        for (int rem1 = 0; rem1 < 9; ++rem1) {
            for (int rem2 = 0; rem2 < 9; ++rem2) {
                if ((rem1 * sum + rem2 - k + 9) % 9 == 0) {
                    if (rem1 != rem2 && index_of_rem[rem1].size() > 0  && index_of_rem[rem2].size() > 0) ans = min(ans, pair<int, int>(index_of_rem[rem1][0], index_of_rem[rem2][0]));
                    if (rem1 == rem2 && index_of_rem[rem1].size() > 1) ans = min(ans, pair<int, int>(index_of_rem[rem1][0], index_of_rem[rem1][1]));
                }
            }
        }
        if (ans.first == n + 1) {
            ans.first = -2;
            ans.second = -2;
        }
        cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }

}

signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
