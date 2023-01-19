#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
    int T = INT64_MAX;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int p = 1;
        if (n == 1) {
            cout << "0\n"; continue;
        }
        while (p <= n) p *= 10;
        p /= 10;
        cout << n - p << '\n';    
    }
}