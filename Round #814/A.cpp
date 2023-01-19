#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

template<typename T = int>
vector<T> read(int n) {
    vector<T> v_to_read_in (n);
    for (int i = 0; i < n; ++i) cin >> v_to_read_in[i];
    return v_to_read_in;
}

template<typename T = int>
vector<vector<T>> read2(int n, int m) {
    vector<vector<T>> v_to_read_in(n, vector<T>(m));
    for (auto& v : v_to_read_in) {
        for (T& el : v) {
            cin >> v;
        }
    }
}

void solve_test_case() {
    int n, m;
    cin >> n >> m;
    cout << ((n%2 xor m%2)? "Burenka\n" : "Tonya\n");
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int number_of_tests = 1;
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> number_of_tests;
    while (number_of_tests--) solve_test_case();
}
