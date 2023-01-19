#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) \
  int a;       \
  cin >> a;
#define loop(n) for (int i = 0; i < n; ++i)
#define fast_and_furious                                   \
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

struct SparceTable {
  vector<vector<int>> data_;

  SparceTable(const vector<int>& v) {
    int n = v.size();
    int logn = log2(n) + 1;
    data_ = vector<vector<int>>(logn + 1, vector<int>(n));
    data_[0] = v;
    for (int i = 1; i <= logn; ++i) {
      int pow = (1 << (i - 1));
      for (int j = 0; j + pow < n; ++j) {
        data_[i][j] = std::min(data_[i - 1][j], data_[i - 1][j + pow]);
      }
    }
  }

  // [left, right]
  int GetMinOnSegment(int left, int right) const {
    int len = right - left + 1;
    if (len == 1) return data_[0][left];
    int pow = 0;
    while ((1 << (pow + 1)) < len) ++pow;
    int ans1 = data_[pow][left];
    int ans2 = data_[pow][right - (1 << pow) + 1];
    return std::min(ans1, ans2);
  }

  // True, if on (left, right) interval there are no value greater then on left
  // and right position
  bool NoMaxOnInterval(int left, int right) const {
    if (right - left == 1) {
      return true;
    }
    return GetMinOnSegment(left + 1, right - 1) <=
           data_[0][left];  // Assume that v[left] == v[right]
  }
};

// Created by AndZhi on 15/01/2023

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

bool is_sqrt(int x) {
  int root = sqrt(x);
  return x == root * root;
}

vector<int> all_suit_shifts(int a, int b) {
  vector<int> answer;
  // if (is_sqrt(a) && is_sqrt(b)) {
  //     answer.push_back(0);
  // }
  if (a > b) swap(a, b);
  int diff = b - a;
  if (diff == 1) {
    if (a == 0) {
        return {0};
    } else {
        return {};
    }
  }
  if (diff == 2) return {};
  if (diff == 3) {
    if (a == 1) {
        return {0};
    } else {
        return {};
    }
  }
  for (int i = 1; i * i <= diff; ++i) {
    if (diff % i != 0) continue;
    if ((i + diff / i) % 2) continue;
    int n = (i + diff / i) / 2;
    int m = n - i;
    if (n * n >= b) answer.push_back(n * n - b);
  }
  return answer;
}

void solve_test_case() {
  get(n) auto numbers = read(n);
  map<int, set<int>> ans_for_x;
  int ans = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto suitable = all_suit_shifts(numbers[i], numbers[j]);
      for (const auto& x : suitable) {
        ans_for_x[x].insert(i);
        ans_for_x[x].insert(j);
        ans = max(ans, (int)ans_for_x[x].size());
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  fast_and_furious
      // freopen("tests.txt", "r", stdin);
      // freopen("output.txt", "w", stdout);
      int tests = 1;
  cin >> tests;
//   while (tests--) {
//     get(a) get(b) print(all_suit_shifts(a, b));
//   }
  while (tests--) 
    solve_test_case();
}
