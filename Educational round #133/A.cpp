#include <bits/stdc++.h>

using namespace std;
#define int64_t int;
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) cout << "2\n";
        else if (n == 2 || n == 3) cout << "1\n";
        else {
            int ans = n/3;
            if (n % 3) ++ans;
            cout << ans << '\n';
        }
    }
}