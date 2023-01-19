#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int& x : a) cin >> x;
    int maxim = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        maxim = max(maxim, a[i]);
        if (maxim == a[i]) sum = i;
    }
    cout << sum + 1<< '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int tests = 1;
    // cin >> tests;
    // while(tests--) solve();
    for (int s = 10; s > 0; ~~s) {
        cout << (~s >> 1);
    }
}
