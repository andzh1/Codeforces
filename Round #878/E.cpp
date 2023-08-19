#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define repeat(n) for(int i = 0; i < n; ++i)
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define foreach(v) for (const auto& x : v)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

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


template<typename T>
void print(const T& v) {
    cout << v << ' ';
    cout << '\n';
}

template<typename T = int>
void print(const vector<T>& v) {
    for (const auto& x : v) print(x);
    cout << '\n';
}

template<typename T = int>
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}


template <typename T>
void sort_v(vector<T>& v) {
  sort(all(v));
}

template <typename T>
void rsort_v(vector<T>& v) {
  sort(rall(v));
}

template <typename AxisType = int>
struct Point {
  AxisType x = 0;
  AxisType y = 0;
  int index = 0;
  bool first_compare_by_x_ = true;

  explicit Point(AxisType x, AxisType y) : x(x), y(y) {}
  explicit Point(AxisType x, AxisType y, bool cmp)
      : x(x), y(y), first_compare_by_x_(cmp) {}
  explicit Point(AxisType x, AxisType y, int index)
      : x(x), y(y), index(index) {}
  explicit Point(AxisType x, AxisType y, int index, bool cmp)
      : x(x), y(y), index(index), first_compare_by_x_(cmp) {}

  bool operator<(const Point& other) const {
    if (first_compare_by_x_) {
      return (x < other.x) || (x == other.x && y < other.y) ||
             (x == other.x && y == other.y && index < other.index);
    } else {
      return (y < other.y) || (y == other.y && x < other.x) ||
             (x == other.x && y == other.y && index < other.index);
    }
  }
};

template<typename first_t = int64_t, typename second_t = int64_t>
struct CustomComparablePair {
    first_t first;
    second_t second;
    int index = 0;

    explicit CustomComparablePair(first_t x, second_t y) : first(x), second(y) {}
    explicit CustomComparablePair(first_t x, second_t y, int index)
        : first(x), second(y), index(index) {}

    CustomComparablePair() = default;

    virtual bool operator<(const CustomComparablePair& other) const = 0;
};

template<typename first_t = int, typename second_t = int>
struct MyPoint: public CustomComparablePair<first_t, second_t> {
    using CustomComparablePair<first_t, second_t>::CustomComparablePair;


    bool operator<(const CustomComparablePair<first_t, second_t>& other) const override {
        const MyPoint& otherPoint = static_cast<const MyPoint&>(other);
        return (this->first < otherPoint.first) || 
               (this->first == otherPoint.first && this->second < otherPoint.second) ||
               (this->second == otherPoint.second && this->first == otherPoint.first && this->index < otherPoint.index);
    }
};

using two_int_t = MyPoint<int, int>;

struct Cooldown {
    bool is_start;
    int position;
    int time;

    bool operator<(const Cooldown& other) {
        if (time != other.time) return time < other.time;
        if (position != other.position) return position < other.position;
        if (is_start != other.is_start) return is_start < other.is_start;
        return false;
    }
};

int revert(int x) {
    if (x == 1) return 2;
    return 1;
}

void solve_test_case() {
    vector<string> s(3);
    cin >> s[1] >> s[2];
    get(t)
    get(q)
    int n = s[1].length();
    int unequal_positions = 0;
    repeat(n) {
        if (s[1][i] != s[2][i]) {
            unequal_positions++;
        }
    }

    vector<vector<int>> unblocking(q + 1 + t);

    for (int time = 1; time <= q; ++time) {
        get(type)
        for (int i = 0; i < unblocking[time].size(); ++i) {
            if (s[1][i] != s[2][i]) {
                unequal_positions++;
            }
        }
        if (type == 1) {
            get(pos)
            if (s[1][pos - 1] != s[2][pos - 1]) {
                unequal_positions--;
            }
            unblocking[time + t].push_back(pos - 1);
            continue;
        }
        if (type == 2) {
            get(str1)
            get(pos1)
            get(str2)
            get(pos2)
            if (s[str1][pos1 - 1] != s[revert(str1)][pos1 - 1] && s[str1][pos1 - 1] == s[str2][pos2 - 1]) unequal_positions--;
            if (s[str1][pos1 - 1] == s[revert(str1)][pos1 - 1] && s[str1][pos1 - 1] != s[str2][pos2 - 1]) unequal_positions++;
            if (s[str2][pos2 - 1] != s[revert(str2)][pos2 - 1] && s[str1][pos1 - 1] == s[str2][pos2 - 1]) unequal_positions--;
            if (s[str2][pos2 - 1] == s[revert(str2)][pos2 - 1] && s[str1][pos1 - 1] != s[str2][pos2 - 1]) unequal_positions++;
            swap(s[str1][pos1 - 1], s[str2][pos2 - 1]);
            continue;
        }
        if (type == 3) {
            if (unequal_positions == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }


}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}
