#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
    int T = INT64_MAX;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if (n % 2) {
            cout << "-1\n";
            continue;
        }
        if (n % 2 == 0) {
            cout << n/2 << ' ' << n/2 << " 0\n";
            continue;
        }
        // int cnt = 0, power = 1, n2 = n;
        // while (n > 0 && cnt < 3) {
        //     if (n % 2 == 1) {
        //         cout << power << ' ';
        //         n2 -= power;
        //         ++cnt;
        //     }
        //     n /= 2;
        // }
        // cout << n2 << '\n';
        // cout << n;
    }
}