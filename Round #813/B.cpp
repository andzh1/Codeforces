#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

template<typename T = int>
vector<T> read(int n) {
    vector<T> v_to_read_in (n);
    for (int i = 0; i < n; ++i) cin >> v_to_read_in[i];
    return v_to_read_in;
}

void solve_test_case() {
    int n;
    cin >> n;
    vector<int> ans (n, 1);
    for (int i = n - 1; i > 0; i -= 2) {
        ans[i] = i;
        ans[i - 1] = i + 1;
    }
    for (auto a : ans) cout << a << ' ';
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