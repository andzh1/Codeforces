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
        vector<pair<int, int>> boxes(n);
        for (auto& box : boxes) cin >> box.first >> box.second;
        map<pair<int, int>, bool> visited;
        pair<int, int> start = {0, 0};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int min_dist = INT32_MAX;
            pair<int, int> next;
            for (auto nxt : boxes) {
                if (visited[nxt]) continue;
                if (abs(nxt.second - start.second) + abs(nxt.first - start.first) < min_dist) {
                    min_dist = abs(nxt.second - start.second) + abs(nxt.first - start.first);
                    next = nxt;
                }
            }
            visited[next] = true;
            ans += min_dist;
            next = next;
        }
        ans += abs(start.second) + abs(start.first);
        cout << ans << '\n';
    }
}