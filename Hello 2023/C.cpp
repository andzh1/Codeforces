#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(n) for(int i = 0; i < n; ++i)
#define i_am_speed std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

int modpow(const int& x, const int& power, const int& mod) {
    if (power == 0) return 1;
    if (power == 1) return x;
    int sqrt = modpow(x, power / 2, mod);
    sqrt *= sqrt;
    sqrt %= mod;
    if (power % 2) sqrt *= x;
    sqrt %= mod;
    return sqrt;
}

template<typename T = int>
vector<T> read(int n) {
    vector<T> v (n);
    for (T& x : v) cin >> x;
    return v;
}

template<typename T = int>
vector<vector<T>> read(int n, int m) {
    vector<vector<T>> v (n, vector<T> (m));
    for (auto& x : v) x = read<T>(n);
    return v;
}

template<typename T = int>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template<typename T = int>
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}
// Created by AndZhi on 03/01/23.

void solve_test_case() {
    get(n)
    get(m)
    --m;
    auto v = read(n);
    vector<int> prefix_sums = v;
    for (int i = 1; i < n; ++i) {
        prefix_sums[i] += prefix_sums[i - 1];
    }
    int cur_sum = prefix_sums[m];
    map<int, int> number_of_numbers;
    int ans = 0;
    number_of_numbers[v[m]] = 1;
    for (int i = m - 1; i >= 0; --i) {
        while (prefix_sums[i] < cur_sum) {
            int maximum = (--number_of_numbers.end())->first;
            int& number = (--number_of_numbers.end())->second;
            --number;
            ++ans;
            cur_sum -= 2 * maximum;
            if (number == 0) {
                number_of_numbers.erase(maximum);
            }
        }
        number_of_numbers[v[i]]++;
    }
    prefix_sums[m] = 0;
    number_of_numbers.clear();
    for (int i = m + 1; i < n; ++i) {
        prefix_sums[i] = prefix_sums[i - 1] + v[i];
        number_of_numbers[v[i]]++;
        while (prefix_sums[i] < 0) {
            int minimum = (number_of_numbers.begin())->first;
            int& number = (number_of_numbers.begin())->second;
            --number;
            ++ans;
            prefix_sums[i] += 2 * abs(minimum);
            if (number == 0) {
                number_of_numbers.erase(minimum);
            }
        }
    }
    cout << ans << '\n';
    
}


signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
