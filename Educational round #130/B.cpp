#include <bits/stdc++.h>

using namespace std;

signed main() {
    int64_t n, q;
    cin >> n >> q;
    vector<int> costs (n);;
    for (auto& c : costs) cin >> c;
    
    sort(costs.begin(), costs.end());
    vector<int64_t> prefixes (n);
    prefixes[0] = costs[0];
    for (int i = 1; i < n; ++i) {
        prefixes[i] = costs[i] + prefixes[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        int64_t ans = 0;
        int x, y;
        cin >> y >> x;
        if (n - y - 1 < 0) cout << prefixes[n - y + x - 1] << '\n';
        else cout << prefixes[n - y + x - 1] - prefixes[n - y - 1] << '\n';
    }
}