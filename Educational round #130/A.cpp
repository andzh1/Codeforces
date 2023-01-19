#include <bits/stdc++.h>

using namespace std;


signed main() {
    int64_t T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        vector<int> distances (n);
        for (auto& x : distances) cin >> x;
        int64_t answer = 0, current_power = m;
        for (int i = 0; i < n; ++i) {
            current_power -= distances[i];
            if (current_power < 0) {
                answer -= current_power;
                current_power = 0;
            }
        }
        cout << answer << '\n';
    }
}