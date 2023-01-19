#include <bits/stdc++.h>

using namespace std;
// #define int64_t long long;

template<typename T = long long>
vector<T> read(long long n) {
    vector<T> v_to_read_in (n);
    for (long long i = 0; i < n; ++i) cin >> v_to_read_in[i];
    return v_to_read_in;
}

// template<typename T = long long>
// vector<vector<T>> read2(long long n, long long m) {
//     vector<vector<T>> v_to_read_in(n, vector<T>(m));
//     for (auto& v : v_to_read_in) {
//         for (T& el : v) {
//             cin >> v;
//         }
//     }
// }

long long cost_of_house(long long i, const vector<long long>& houses) {
    return max(0ll, max(houses[i - 1], houses[i + 1]) - houses[i] + 1);
}

long long ans_for_start_index(const vector<long long>& houses, long long index) {
    long long ans = 0;
    for (long long i = index; i < houses.size() - 1; i += 2) {
        ans += cost_of_house(i, houses);
    }
    return ans;
}



void solve_test_case() {
    long long n;
    cin >> n;
    vector<long long> houses = read(n);
    long long start_index = 1;
    if (n % 2) {
        cout << ans_for_start_index(houses, 1) << '\n';
    } else {
        long long cur_ans = ans_for_start_index(houses, 1), min_ans = cur_ans;
        for (long long i = n - 3; i > 0; i -= 2) {
            cur_ans += cost_of_house(i + 1, houses);
            cur_ans -= cost_of_house(i, houses);
            min_ans = min(min_ans, cur_ans);
        }
        cout << min_ans << '\n';
        // cout << min(ans_for_start_index(houses, 1), ans_for_start_index(houses, 2)) << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    long long number_of_tests = 1;
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> number_of_tests;
    while (number_of_tests--) solve_test_case();
}