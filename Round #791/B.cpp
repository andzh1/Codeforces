#include <bits/stdc++.h>

signed main() {
    int64_t n, q;
    std::cin >> n >> q;
    std::vector<int64_t> input (n);
    std::vector<int64_t> times_updated (n, 0);
    for (auto& x: input) std::cin >> x;
    int64_t all_eq = -1;
    int64_t number_of_alls = 0;
    int64_t sum = 0;
    for (auto x: input) sum += x;
    for (int64_t i = 0; i < q; ++i) {
        int64_t type;
        std::cin >> type;
        if (type == 1) {
            int64_t index, val;
            std::cin >> index >> val;
            --index;
            if (times_updated[index] != number_of_alls) {
                times_updated[index] = number_of_alls;
                input[index] = all_eq;
            }
            sum += val - input[index];
            input[index] = val;
        } else {
            int64_t val;
            std::cin >> val;
            ++number_of_alls;
            all_eq = val;
            sum = val * n;
        }
        std::cout << sum << '\n';   
    }
}