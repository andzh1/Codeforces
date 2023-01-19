#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp (n + 1, vector<int>(n + 1));
    // win = 2, draw = 1, lose = 0
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][2] = 1;
        } else dp[i][2] = 2;
    }
    for (int len = 4; len <= n; len += 2) {
        for (int i = 0; i <= n - len; ++i) {
            int first_opt = dp[i][len - 2];
            if (s[i + len - 2] != s[i + len - 1]) first_opt *= 2;
            int sec_opt = dp[i + 1][len - 2];
            if (s[i] != s[i + len - 1]) sec_opt *= 2;
            int third_opt = dp[i + 2][len - 2];
            if (s[i] != s[i + 1]) third_opt *= 2;
            first_opt = min(first_opt, 2ll);
            sec_opt = min(sec_opt, 2ll);
            third_opt = min(third_opt, 2ll);
            dp[i][len] = max(min(sec_opt, first_opt), min(sec_opt, third_opt));
        }
    }
    if (dp[0][n] == 2) cout << "Alice\n";
    if (dp[0][n] == 1) cout << "Draw\n";
    // if (dp[0][n] == 0) cout << "Bob\n";
    // cout << dp[0][n] << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve();
}
