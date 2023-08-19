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

int time_of_segment(int l, int r) {
    if ((r - l) % 2 == 0) {
        return (r - l) / 2;
    }
    return (r - l) / 2 + 1;
}

int time_of_dist(int dist) {
    return (dist + 1) / 2;
}


void solve_test_case() {
    get(n)
    auto v = read(n);
    std::sort(all(v));
    set<int> ll;
    foreach(v) {
        ll.insert(x);
    }
    v.clear();
    foreach(ll) {
        v.push_back(x);
    }
    n = v.size();
    if (n <= 3) {
        cout << "0\n";
        return;
    }
    
    for(int i = 1; i < n; ++i) {
        v[i] -= v[0];
    }
    v[0] = 0;
    vector<int> distances(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        distances[i] = v[i + 1] - v[i];
    }
    vector<int> dp(n, v.back());
    int index = 0, left_dist = 0, right_dist = 0;
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < n; ++i) {
        right_dist += distances[i - 1];
        if (right_dist < left_dist || index == distances.size() - 1) {
            dp[i] = dp[i - 1];
            continue;
        }
        int min_dist = v.back();
        int min_index = -1;
        while (true) {
            int a1 = max(left_dist, right_dist);
            int a2 = max(left_dist + distances[index], right_dist - distances[index + 1]);
            int cur = min(a1, a2);
            if (cur < min_dist) {
                min_dist = cur;
                min_index = index;
                if (a2 < a1) {
                    left_dist += distances[index];
                    right_dist -= distances[index + 1];
                    ++index;
                }
                continue;
            } else break;
        }
        dp[i] = min_dist;
    }

    int ans = v.back();
    for (int i = 2; i < n - 1; ++i) {
        int left = dp[i];
        int right = v[n - 1] - v[i + 1];
        ans = min(ans, max(left, right));
    }
    cout << time_of_dist(ans) << '\n';

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}
