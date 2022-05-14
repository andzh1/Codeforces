#include <bits/stdc++.h>

signed main() {
    int T;
    std::cin >> T;
    while (T--) {
        int64_t n;
        std::cin >> n;
        if (n % 2 || n == 2) {
            std::cout << "-1\n";
            continue;
        }

        int64_t min_ans, max_ans;
        if (n % 4 == 0) {
            max_ans = n / 4;
        } else {
            max_ans = (n - 2) / 4;
        }
        if (n % 6 == 0) {
            min_ans = n/6;
        }
        if (n % 6 == 4) {
            min_ans = (n + 2) / 6;
        }
        if (n % 6 == 2) {
            min_ans = (n + 4) / 6;
        }
        std::cout << min_ans << ' ' << max_ans << '\n';


        // std::cout << n;
    }
}