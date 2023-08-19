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

bool is_enough(int distance, vector<int>& v) {
    int n = v.size();
    int left_edge = -1, right_edge = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] <= distance * 2 && v[i + 1] > distance * 2) {
            left_edge = i + 1;
            break;
        }
    }
    int r = v.back() - distance * 2;
    for (int i = n - 1; i > 0; --i) {
        if (v[i] >= r && v[i - 1] < r) {
            right_edge = i - 1;
            break;
        }
    }
    if (left_edge == -1) return true;
    if (right_edge == -1) return true;
    if (left_edge >= right_edge) return true;
    int len = v[right_edge] - v[left_edge];
    return (len <= distance * 2);
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

    int left = 0, right = v.back();

    while(left < right - 1) {
        int dist = (right + left) / 2;
        if (is_enough(dist, v)) {
            right = dist;
        } else {
            left = dist;
        }
    }
    cout << right << '\n';

}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}
