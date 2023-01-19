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


void solve_test_case() {
    get(n)
    auto a = read(n);
    int cursum = 0;
    int prefix_ans = 0;
    int ip = 0;
    for (; ip < n; ++ip) {
        if (a[ip] == 0) break;
        cursum += a[ip];
        prefix_ans += cursum == 0;
    }  
    for (int i = ip; i < n; ++i) {
        map<int, int> prefix_sum_to_number;
        cursum = 0;
        bool found = false;
        for (int j = i; j < n; ++j) {
            if (a[j] == 0 && j > i) {
                i = j - 1;
                found = true;
                break;
            }
            cursum += a[j];
            prefix_sum_to_number[cursum]++;
            
        }
        pair<int, int> ans;
        for (const auto& x: prefix_sum_to_number) {
            if (ans.second < x.second) ans = x;
        }
        prefix_ans += ans.second;
        if (!found) break;
    }  
    
    cout << prefix_ans << '\n'; 
}


signed main() {
    i_am_speed
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
