#include <bits/stdc++.h>

using namespace std;

signed main() {
    int64_t T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        int64_t k;
        cin >> k;
        vector<int64_t> colors (k);
        for (int64_t& c : colors) cin >> c;
        vector<int64_t> rows(k);
        bool exists = false;
        int64_t amount = 0, decrease = 1;
        bool has_even = false, current_exists = false;
        for (int64_t i = 0; i < k; ++i) {
            int64_t current_amount = colors[i] / n;
            if (current_amount < 2) current_amount = 0;
            if (current_amount >= 3) {
                has_even = true;
                decrease = min(decrease, int64_t(current_amount % 2 == 0));
            }
            amount += current_amount;
        }
        current_exists = amount >= m;
        if (m % 2 && (!has_even || amount - decrease < m)) current_exists = false;
        exists |= current_exists;
        amount = 0, decrease = 1;
        has_even = false, current_exists = false;
        for (int64_t i = 0; i < k; ++i) {
            int64_t current_amount = colors[i] / m;
            if (current_amount < 2) current_amount = 0;
            if (current_amount >= 3) {
                has_even = true;
                decrease = min(decrease, int64_t(current_amount % 2 == 0));
            }
            amount += current_amount;
        }
        current_exists = amount >= n;
        if (n % 2 && (!has_even || amount - decrease < n)) current_exists = false;
        exists |= current_exists;        
        cout << (exists? "Yes\n" : "No\n");
    }
}