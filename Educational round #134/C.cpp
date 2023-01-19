#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

template<typename T = int>
vector<T> read_v(int n) {
    vector<T> v_to_read_v_in (n);
    for (int i = 0; i < n; ++i) cin >> v_to_read_v_in[i];
    return v_to_read_v_in;
}

template<typename T = int>
vector<vector<T>> read_v2(int n, int m) {
    vector<vector<T>> v_to_read_v_in(n, vector<T>(m));
    for (auto& v : v_to_read_v_in) {
        for (T& el : v) {
            cin >> v;
        }
    }
}

void solve_test_case() {
    int n;
    cin >> n;
    auto a = read_v<int>(n);
    auto b = read_v<int>(n);
    vector<int> max_ans(n), min_ans(n);
    int ip = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (ip >= 0 && b[ip] >= a[i]) --ip;
        ++ip;
        min_ans[i] = b[ip] - a[i];
    }
    ip = 0;
    for (int i = 0; i < n; ++i) {
        ip = max(ip, i);
        while (ip < n - 1 && a[ip + 1] <= b[ip]) ++ip;

        max_ans[i] = b[ip] - a[i];
    }
    for (auto v : min_ans) cout << v << ' ';
    cout << '\n';
    for (auto v : max_ans) cout << v << ' ';
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
