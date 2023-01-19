#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
    int T = INT64_MAX;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> stations(n);
        map<int, int> first_pos;
        map<int, int> last_pos;
        for (int& s : stations) {
            cin >> s;
        }
        for (int i = 0; i < n; ++i) {
            last_pos[stations[i]] = i;
        }
        for (int i = n - 1; i >= 0; --i) {
            first_pos[stations[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            if (first_pos.find(a) == first_pos.end() || first_pos.find(b) == first_pos.end()) {
                cout << "NO\n";
            } else {
                cout << ((first_pos[a] < last_pos[b])? "YES\n" : "NO\n");
            }
        }
    }
}