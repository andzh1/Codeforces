#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = n - 2; i >= 1; --i) {
            cout << i << ' ';
        }
        cout << n-1 << ' ' << n;
        cout << '\n';
        return;
    }
    if (n % 2 == 1) {
        for (int i = n - 1; i >= 2; --i) {
            if (i == n - 2) continue;
            cout << i << ' ';
        }
        cout << "1 " << n-2 << ' ' << n;
        cout << '\n';
        return;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve();
}
