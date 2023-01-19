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
    vector<int> input = read(n);
    int index = n - 1;
    while (index > 0 && input[index - 1] <= input[index]) --index;
    if (index == 0) {
        cout << "0\n";
        return;
    }
    set<int> to_zero;
    for (int i = 0; i < index; ++i) to_zero.insert(input[i]);
    for (int i = n - 1; i >= index; --i) {
        if (to_zero.find(input[i]) != to_zero.end()) {
            index = i+1;
            break;
        }
    }
    set<int> ans;
    for (int i = 0; i < index; ++i) {
        ans.insert(input[i]);
    }
    cout << ans.size() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int number_of_tests = 1;
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> number_of_tests;
    while (number_of_tests--) solve_test_case();
}