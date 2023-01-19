#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
    int T = INT64_MAX;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << "2\n";
        for (int i = 1; i <= n; i += 2) {
            int ip = i;
            while (ip <= n) {
                cout << ip << ' ';
                ip *= 2;
            }
        }
        cout << '\n';

    }
}