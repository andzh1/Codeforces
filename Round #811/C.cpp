#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

int f(int sum, int max) {
    if (sum <= max) {
        return sum;
    }
    int preans = f(sum - max, max - 1);
    return preans * 10 + max;
} 

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int sum;
        cin >> sum;
        // if (sum < 10) {
        //     cout << sum << '\n';
        //     continue;
        // }
        cout << f(sum, 9) << '\n';

    }
}