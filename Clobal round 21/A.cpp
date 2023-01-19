#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

signed main() {
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll z;
        cin >> z;
        ll a[n];
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll maxim = a[0];
        for (ll i = 0; i < n; ++i) {
            maxim = max(a[i] | z, maxim);
            maxim = max(a[i], maxim);
        }
        cout << maxim << '\n';

    }
}