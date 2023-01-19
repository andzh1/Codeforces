#include <bits/stdc++.h>

using namespace std;
#define int64_t int;
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& in : a) cin >> in;
        bool ans = true;
        for (int i = 1; i < n-1; ++i) {
            if (a[i] >= a[i-1]) continue;
            int ip = i + 1;
            while (ip < n && a[ip] == a[i]) ++ip;
            if (ip == n) break;
            if (a[ip] > a[i]) {
                ans = false;
                break;
            }
        }
        cout << ((ans)? "YES\n" : "NO\n");
    }
}