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
  for (auto& x : v) x = read<T>(m);
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

template <typename T = int>
T sum(const vector<T>& v) {
  T ans = 0;
  for (const auto& x : v) ans += x;
  return ans;
}

struct Data {
  int value;
  int index;
  int cur_sum;

  bool operator<(const Data& other) const {
    if (cur_sum != other.cur_sum) return cur_sum < other.cur_sum;
    if (value != other.value) return value < other.value;
    return index < other.index;
  }
};

void solve_test_case() {
  get(n);
  get(m);
  auto arrays = read(n, m);
  int total_sum = 0;
  for (int i = 0; i < n; ++i) {
    total_sum += sum(arrays[i]);
  }
  if (total_sum % n) {
    cout << "-1\n";
    return;
  }
  int required_sum = total_sum / n;
  vector<set<int>> ones(m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arrays[j][i]) ones[i].insert(j);
    }
  }
  vector<int> required_for_array(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    required_for_array[i] = sum(arrays[i]) - required_sum;
    ans += abs(required_for_array[i]);
  }
  cout << ans / 2 << '\n';
  for (int i = 0; i < m; ++i) {
    vector<Data> current_numbers(n);
    for (int j = 0; j < n; ++j) {
      current_numbers[j] = {
          .value = arrays[j][i], .index = j, .cur_sum = required_for_array[j]};
    }
    sort(current_numbers.begin(), current_numbers.end());
    int first = 0, second = n - 1;
    while (first < second) {
      if (current_numbers[first].cur_sum >= 0) break;
      if (current_numbers[second].cur_sum <= 0) break;
      if (current_numbers[first].value == 1) {
        ++first;
        continue;
      }
      if (current_numbers[second].value == 0) {
        --second;
        continue;
      }
      cout << current_numbers[first].index + 1 << ' '
           << current_numbers[second].index + 1 << ' ' << i + 1 << '\n';
      required_for_array[current_numbers[first].index]++;
      required_for_array[current_numbers[second].index]--;
      ++first;
      --second;
    }
  }
}

signed main() {
  i_am_speed
      // freopen("tests.txt", "r", stdin);
      // freopen("output.txt", "w", stdout);
      int tests = 1;
  cin >> tests;
  while (tests--) solve_test_case();
}
