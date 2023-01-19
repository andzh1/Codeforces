#include <bits/stdc++.h>

using namespace std;
// #define int64_t int64_t;

struct Segment {
    int64_t left;
    int64_t len;
    bool operator<(const Segment& other) const {
        if (len != other.len) return len < other.len;
        return left < other.left;
    }
};

signed main() {
    int64_t T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        vector<int64_t> infected (m);
        for (int64_t& in : infected) {
            cin >> in;
            --in;
        }
        set<Segment> segments;
        sort(infected.begin(), infected.end());
        int64_t index = infected[0] + n - infected[m-1] - 1;
        segments.insert({infected[m-1], index});
        for (int64_t i = 1; i < m; ++i) {
            segments.insert({infected[i-1], infected[i] - infected[i-1] - 1});
        }
        int64_t free = 0, decrease = 0;
        auto it = segments.end();
        --it;
        while (true) {
            Segment current = *it;
            if (current.len - decrease == 1) {
                free += 1;
                break;
            }
            if (current.len <= decrease) break;
            free += current.len - 1 - decrease;
            decrease += 4;
            if (it == segments.begin()) break;
            --it;
        }
        cout << n - free << '\n';
    }
}