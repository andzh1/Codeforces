#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for (int h = 0; h < n; ++h) {
            for (int l = 0; l < m; ++l) {
                if (h % 4 == 0 || h % 4 == 3) {
                    cout << (l % 4 == 0 || l % 4 == 3) << ' ';
                } else {
                    cout << (l % 4 == 1 || l % 4 == 2) << ' ';
                }
            }
            cout << '\n';
        }
    }
}