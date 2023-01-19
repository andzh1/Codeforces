#include <bits/stdc++.h>

using namespace std;

// #define int64_t int64_t
#define get(a) int64_t a; cin >> a;
#define loop(n) for(int64_t i = 0; i < n; ++i)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

int64_t modpow(const int64_t& x, const int64_t& power, const int64_t& mod) {
    if (power == 0) return 1;
    if (power == 1) return x;
    int64_t sqrt = modpow(x, power / 2, mod);
    sqrt *= sqrt;
    sqrt %= mod;
    if (power % 2) sqrt *= x;
    sqrt %= mod;
    return sqrt;
}

template<typename T = int64_t>
vector<T> read(int64_t n) {
    vector<T> v (n);
    for (T& x : v) cin >> x;
    return v;
}

template<typename T = int64_t>
vector<vector<T>> read(int64_t n, int64_t m) {
    vector<vector<T>> v (n, vector<T> (m));
    for (auto& x : v) x = read<T>(n);
    return v;
}

template<typename T = int64_t>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template<typename T = int64_t>
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}

const int64_t MODULO = 998244353;

int64_t phi (int64_t n) {
	int64_t result = n;
	for (int64_t i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

vector<int64_t> dividers (int64_t n) {
    vector<int64_t> ans;
	for (int64_t i = 2; i * i <= n; ++i)
    if (n % i == 0) {
        while (n % i == 0)
            n /= i;
        ans.push_back(i);
    }
    if (n > 1 && (ans.empty() || ans.back() != n)) ans.push_back(n);
    return ans;
}

int64_t count_gcd1(int64_t x, int64_t m) {
    if (x == 1) return m;
    // if (x == 2) return m - m / 2;
    // if (x == 3) return m - m / 3;
    // if (x == 5) return m - m / 5;
    vector<int64_t> numbers = dividers(x);
    int64_t n = numbers.size();
    int64_t answer = 0;
    for (int64_t mask = 1; mask < (1 << n); ++mask) {
        int64_t mult = 1, sign = -1;
        for (int64_t i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                mult *= numbers[i];
                sign = -sign;
            }
        }
        answer += MODULO + (m / mult) * sign;
        answer %= MODULO;
    }
    return (m - answer);
}

void solve_test_case() {
    get(n)
    get(m)
    auto a = read(n);
    int64_t ans = 1;
    ans %= MODULO;
    int64_t mul = 1;
    for (int64_t i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            cout << "0\n";
            return;
        }
        if (a[i - 1] % a[i] != 0) {
            cout << "0\n";
            return;
        }
        int64_t div = a[i - 1] / a[i];
        mul = a[i];
        ans *= count_gcd1(div, m / a[i]);
        ans %= MODULO;
    }
    cout << ans << '\n';
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int64_t tests = 1;
    cin >> tests;
    while(tests--) solve_test_case();
}
