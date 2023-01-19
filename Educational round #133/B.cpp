#include <bits/stdc++.h>

using namespace std;
#define int64_t int;
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << n << '\n';
        for (int i = 0; i < n; ++i) cout << i+1 << ' ';
        cout << '\n';
        cout << "2 1 ";
        for (int i = 2; i < n; ++i) cout << i+1 << ' ';
        cout << '\n';
        int ip = 2;
        while (ip < n) {
            for (int i = 0; i < ip; ++i) cout << i+2 << ' ';
            cout << "1 ";
            for (int i = ip + 1; i < n; ++i) cout << i+1 << ' ';
            ++ip;
            cout << '\n';
        }

    }
}