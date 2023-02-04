#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;

signed main() {
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vector<ll> a (n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll index = 0;
        while (index < n && a[index] != 0) ++index;
        if (index == n) {
            cout << "1\n";
            continue;
        }
        ll ans = (index > 0);
        for (ll i = index; i < n; ++i) {
            // if (a[i] != 0) continue;
            ll ip = i + 1;
            while (ip < n && a[ip] != 0) ++ip;
            if (ip > i + 1) ++ans;
            i = ip - 1;
        }
        cout << min((ll)2, ans) << '\n';

    }
}