#include <bits/stdc++.h>

using namespace std;
// #define int64_t int64_t;

struct Segment
{
    int64_t left;
    int64_t right;
    bool operator<(const Segment& other) const {
        return right < other.left;
    }
    bool operator>(const Segment& other) const {
        return other < *this;
    }

    bool crosses(const Segment& other) const {
        return !(other < *this || *this < other);
    }
};


signed main() {
    int64_t T;
    cin >> T;
    while (T--) {
        int64_t n, x;
        cin >> n >> x;
        vector<int64_t> food (n);
        for (int64_t& f : food) cin >> f;
        Segment current_segment = {food[0] - x, food[0] + x};
        int64_t ans = 0;
        for (int64_t i = 1; i < n; ++i) {
            Segment new_seg = {food[i] - x, food[i] + x};
            if (current_segment.crosses(new_seg)) {
                current_segment.left = max(current_segment.left, new_seg.left);
                current_segment.right = min(current_segment.right, new_seg.right);
            } else {
                current_segment = new_seg;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}