#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

template<typename T = int>
vector<T> read(int n) {
    vector<T> v_to_read_in (n);
    for (int i = 0; i < n; ++i) cin >> v_to_read_in[i];
    return v_to_read_in;
}

// template<typename T = int>
// vector<vector<T>> read2(int n, int m) {
//     vector<vector<T>> v_to_read_in(n, vector<T>(m));
//     for (auto& v : v_to_read_in) {
//         for (T& el : v) {
//             cin >> v;
//         }
//     }
// }

void solve_test_case() {
    int n;
    cin >> n;
    vector<int> blocks = read(n);
    vector<vector<int>> indexes_of_colors (n);
    for (int i = 0; i < n; ++i) {
        if (indexes_of_colors[blocks[i] - 1].size() > 0 && indexes_of_colors[blocks[i] - 1].back() == i % 2) continue;
        indexes_of_colors[blocks[i] - 1].push_back(i % 2);
    }
    for (int i = 0; i < n; ++i) {
        cout << indexes_of_colors[i].size() << ' ';
    }
    cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int number_of_tests = 1;
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> number_of_tests;
    while (number_of_tests--) solve_test_case();
}