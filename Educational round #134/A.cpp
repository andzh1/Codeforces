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
    // int n;
    // cin >> n;
    set<char> in;
    for (int i = 0; i < 4; ++i) {
        char ch;
        cin >> ch;
        in.insert(ch);
    }
    // if (in.size() == 1) {
    //     cout << "0\n";
    //     return;
    // }
    // if (in.size() == 2) {
    //     cout << "0\n";
    //     return;
    // }
    // if (in.size() == 3) {
    //     cout << "0\n";
    //     return;
    // }
    // if (in.size() == 3) {
    //     cout << "0\n";
    //     return;
    // }
    cout << in.size() - 1 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int number_of_tests = 1;
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> number_of_tests;
    while (number_of_tests--) solve_test_case();
}
