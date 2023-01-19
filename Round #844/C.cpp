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

void solve_test_case() {
    get(n)
    string s;
    cin >> s;
    map<char, int> number_of_symbols;
    vector<vector<int>> pos_of_symbol (26);
    for (char ch : s) number_of_symbols[ch]++;
    loop(n) {
        pos_of_symbol[s[i] - 'a'].push_back(i);
    }
    vector<int> num_answer (26, 0);
    vector<string> str_answer (26);
    for (int sz = 1; sz <= 26; ++sz) {
        if (n % sz != 0) {
            num_answer[sz - 1] = INT64_MAX;
            continue;
        }
        vector<pair<int, char>> all_chars;
        for (const auto& [ch, number] : number_of_symbols) {
            all_chars.push_back({number, ch});
        }
        sort(all_chars.begin(), all_chars.end());
        // auto mapcopy = number_of_symbols;
        set<char> to_use;
        while (!all_chars.empty() && to_use.size() < sz) {
            to_use.insert(all_chars.back().second);
            all_chars.pop_back();
        }
        vector<int> left_positions;
        while (!all_chars.empty()) {
            for (auto& pos : pos_of_symbol[all_chars.back().second - 'a']) {
                left_positions.push_back(pos);
            }
            all_chars.pop_back();
        }
        for (int i = 0; i < 26 && to_use.size() < sz; ++i) {
            if (to_use.count('a' + i)) continue;
            to_use.insert('a' + i);
        }
        str_answer[sz - 1] = s;
        vector<pair<int, char>> cur_numbers;
        for (auto& ch : to_use) {
            cur_numbers.push_back({number_of_symbols[ch], ch});
        }
        sort(cur_numbers.begin(), cur_numbers.end());
        int left = 0, right = cur_numbers.size() - 1;
        int required_sz = n / sz;
        auto new_positions = pos_of_symbol;
        for (int i = 0; i < 26; ++i) {
            if (!to_use.count('a' + i)) {
                new_positions[i].clear();
            }
        }
        while (right > left) {
            if (new_positions[cur_numbers[right].second - 'a'].size() <= required_sz) break;
            if (new_positions[cur_numbers[left].second - 'a'].size() >= required_sz) break;
            while (new_positions[cur_numbers[left].second - 'a'].size() < required_sz && new_positions[cur_numbers[right].second - 'a'].size() > required_sz) {
                new_positions[cur_numbers[left].second - 'a'].push_back(new_positions[cur_numbers[right].second - 'a'].back());
                new_positions[cur_numbers[right].second - 'a'].pop_back();
                num_answer[sz - 1]++;
            }
            if (new_positions[cur_numbers[left].second - 'a'].size() == required_sz) ++left;
            if (new_positions[cur_numbers[right].second - 'a'].size() == required_sz) --right;
        }
        for (int i = 0; i < cur_numbers.size(); ++i) {
            while (new_positions[cur_numbers[i].second - 'a'].size() < required_sz) {
                new_positions[cur_numbers[i].second - 'a'].push_back(left_positions.back());
                num_answer[sz - 1]++;
                left_positions.pop_back();
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (auto& pos : new_positions[i]) {
                str_answer[sz - 1][pos] = 'a' + i;
            }
        }
        sz = sz;
    }
    int min_index = 0;
    loop(26) {
        if (num_answer[i] < num_answer[min_index]) {
            min_index = i;
        }
    }
    cout << num_answer[min_index] << '\n' << str_answer[min_index] << '\n';
}

signed main() {
  fast_and_furious
      // freopen("tests.txt", "r", stdin);
      // freopen("output.txt", "w", stdout);
      int tests = 1;
  cin >> tests;
  while (tests--) solve_test_case();
}
