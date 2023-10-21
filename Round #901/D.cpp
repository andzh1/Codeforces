#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define vi vector<int>
#define get(a) int a; cin >> a;
#define repeat(n) for(int i = 0; i < n; ++i)
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define foreach(val, container) for (const auto& val : container)
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


template <typename TContainer>
void sort(TContainer& v) {
  sort(all(v));
}

template <typename TContainer>
void rsort_v(TContainer& v) {
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

int sum(vector<int>& v) {
    int ans = 0;
    foreach(x, v) ans += x;
    return ans;
}

bool is_power_of_2(int x) {
    int r = 0;
    while (true) {
        int val = (1 << r);
        if (val > x) return false;
        if (val == x) return true;
        ++r;
    }
    return false;
}

int split(int n, int m) {
    int pow = 1;
    while (pow <= n) pow *= 2;
    pow /= 2;
    int ans = 0;
    while (n > 0) {
        if (n >= pow) {
            ans += pow * (m / pow - 1);
            n -= pow;
        }
        pow /= 2;
    }
    return ans;
}

void solve_test_case() {
    get(n)
    auto a = read(n);
    sort(all(a));
    int mex = 0;
    if (a[0] > 0) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == mex) {
            ++mex;
            continue;
        }
        if (a[i] < mex) continue;
        if (a[i] > mex) break;
    }

    vector<int> cost_of_removal(mex);
    int num = 0;
    for (int i = 0; i < n && a[i] < mex; ++i) {
        cost_of_removal[a[i]]++;
    }

    // for(int i = 0; i < cost_of_removal.size(); ++i) {
    //     if (cost_of_removal[i] == 1) {
    //         mex = i;
    //         break;
    //     }
    // }

    vector<vector<int>> dp(mex + 1, vector<int>(mex)); // dp[current_mex][i] - ans for prefix [0:i] of cost_of_removal array when mex is 
    for (int i = 0; i < mex; ++i) {
        dp[0][i] = 0;
    }

    for (int current_mex = 1; current_mex <= mex; ++current_mex) {
        dp[current_mex][0] = current_mex * (cost_of_removal[0] - 1);
        for (int i = 1; i < current_mex; ++i) {
            dp[current_mex][i] = min(dp[i][i - 1] + current_mex * (cost_of_removal[i] - 1) + i, dp[current_mex][i - 1]);
        }
    }

    cout << dp[mex][mex - 1] << '\n';
}



signed main() {
    fast_and_furious
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}

