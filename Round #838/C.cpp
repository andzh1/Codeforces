#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) \
  int a;       \
  cin >> a;
#define loop(n) for (int i = 0; i < n; ++i)
#define i_am_speed                                         \
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr), \
      std::cout.tie(nullptr);

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

template <typename T = int>
vector<T> read(int n) {
  vector<T> v(n);
  for (T& x : v) cin >> x;
  return v;
}

template <typename T = int>
vector<vector<T>> read(int n, int m) {
  vector<vector<T>> v(n, vector<T>(m));
  for (auto& x : v) x = read<T>(n);
  return v;
}

template <typename T = int>
void print(const vector<T>& v) {
  for (const auto& x : v) cout << x << ' ';
  cout << '\n';
}

template <typename T = int>
void print(const vector<vector<T>>& v) {
  for (const auto& x : v) print(x);
}

int sum(const vector<int>& v) {
  int ans = 0;
  for (const int& x : v) ans += x;
  return ans;
}

const int kModulo = 998244353;

vector<int> cashed_fact(2 * 1e5 + 1, -1);

int fact(int n) {
  if (cashed_fact[n] != -1) {
    return cashed_fact[n];
  }
  if (n <= 1) {
    cashed_fact[n] = 1;
    return 1;
  }
  cashed_fact[n] = n * fact(n - 1);
  cashed_fact[n] %= kModulo;
  return cashed_fact[n];
}

int polynomial(int n, int k) {
  int ans = fact(n);
  int div = fact(k) * fact(n - k);
  div %= kModulo;
  ans *= modpow(div, kModulo - 2, kModulo);
  ans %= kModulo;
  return ans;
}

void solve_test_case() {
  get(n) string s;
  cin >> s;
  vector<int> ans(n);
  map<int, int> number_of_i;
  //   vector<int> number_of_1(n);
  ans[0] = 1;  // mb 0
  number_of_i[2 * (s[0] - '0') - 1] = 1;
  for (int i = 1; i < n; ++i) {
    // number_of_i = number_of_i[i - 1];
    if (s[i] != s[i - 1]) {
      map<int, int> new_map;
      if (s[i] == '1') {
        new_map[1] = number_of_i[-1];
        ans[i] = new_map[1];
      } else {
        new_map[-1] = number_of_i[1];
        ans[i] = new_map[-1];
      }
      number_of_i = new_map;
      continue;
    }
    int ip = i;
    while (ip < n && s[i] == s[ip]) {
        ans[ip] = 2 * ans[ip - 1];
        ans[ip] %= kModulo;
        ++ip;
    }
    if (ip == n) break;
    // ip--;
    i = ip - 1;
  }
  int answ = 0;
  for (int i = 0; i < n; ++i) {
    answ += ans[i];
    answ %= kModulo;
  }
  cout << answ << '\n';
}

signed main() {
  i_am_speed 
//   freopen("tests.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int tests = 1;
  cin >> tests;
  while (tests--) solve_test_case();
}
