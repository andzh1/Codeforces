#include <bits/stdc++.h>

using namespace std;
#define int64_t int;
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        if (n < m) {
            cout << "NO\n";
            continue;
        }
        bool ans = true;
        for (int i = 1; i < m; ++i) {
            if (a[n-i] != b[m-i]) {
                ans = false;
                break;
            }
        }
        bool ans2 = false;
        for (int i = 0; i <= n-m; ++i) {
            ans2 |= (a[i] == b[0]);
        }
        cout << ((ans2 & ans)? "Yes\n" : "No\n");
    }
}