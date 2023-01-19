#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;

struct Segment {
    ll number = 0;
    ll len = 1;

    bool operator==(const Segment& other) const {
        return len == other.len && number == other.number;
    }
};

signed main() {
    ll T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        vector<Segment> as(n);
        ll sum1 = 0, sum2 = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> as[i].number;
            sum1 += as[i].number;
            while (as[i].number % m == 0) {
                as[i].number /= m;
                as[i].len *= m;
            }
        }
        ll k;
        cin >> k;
        vector<Segment> bs(k);
        for (ll i = 0; i < k; ++i) {
            cin >> bs[i].number;
            sum2 += bs[i].number;
            while (bs[i].number % m == 0) {
                bs[i].number /= m;
                bs[i].len *= m;
            }
        }
        try
        {
            ll a = 0, b = 0, ip_a = 0, sum_a, last_dif = 0;
            while (a < n && b < k) {
                ip_a = a, sum_a = 0;
                while (ip_a < n && as[ip_a].number == as[a].number) {sum_a += as[ip_a].len; ++ip_a; }
                // ll ip_b = b, sum_b = 0;
                // while (ip_b < k && bs[ip_b].number == bs[b].number) {sum_b += bs[ip_b].len; ++ip_b; }

                if (bs[b].number != as[a].number || sum_a < bs[b].len) {
                    throw 1;
                }
                a = ip_a - 1; 
                as[a].len = sum_a - bs[b].len;
                last_dif = as[a].len;
                ++b;
                if (as[a].len == 0) ++a;
            }
            if ((a == n && b != k) || (a != n && b == k)/* || last_dif != 0 || sum2 != sum1*/) {
                throw 1;
            }
        } catch(...)
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}