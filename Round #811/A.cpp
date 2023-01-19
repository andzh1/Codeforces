#include <bits/stdc++.h>

using namespace std;
#define int64_t int;
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int H, M;
        cin >> H >> M;
        auto start = pair<int, int>({H, M});
        vector<pair<int, int>> alarms (n);
        int ans = 60*24;
        for (auto& a : alarms) {
            cin >> a.first >> a.second;
            // if (a >= start) {
            int curans = -(H - a.first) * 60 - (M - a.second);
            if (curans < 0) curans += 60*24;
            ans = min(ans, curans);
            // }
        }
        // sort(alarms.begin(), alarms.end());
        cout << ans / 60 << ' ' << ans % 60 << '\n';
    }
}