#include <bits/stdc++.h>

using namespace std;
#define int64_t int;
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i < n; ++i) cout << i + 1 << ' ';
        cout << "1\n";
    }
}