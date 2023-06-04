#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(n) for(int i = 0; i < n; ++i)
// #define iloop(n) loop(i, n)
// #define jloop(n) loop(j, n)
// #define kloop(n) loop(j, n)
#define all(v) v.begin(), v.end()
#define rall(v) (v.end(), v.begin())
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
  std::sort(all(v));
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
  Point() = default;

  explicit Point(AxisType x, AxisType y) : x(x), y(y) {}
  explicit Point(AxisType x, AxisType y, bool cmp)
      : x(x), y(y), first_compare_by_x_(cmp) {}
  explicit Point(AxisType x, AxisType y, int index)
      : x(x), y(y), index(index) {}
  explicit Point(AxisType x, AxisType y, int index, bool cmp)
      : x(x), y(y), index(index), first_compare_by_x_(cmp) {}

//   bool operator<(const Point& other) const {
//     if (first_compare_by_x_) {
//       return (x < other.x) || (x == other.x && y < other.y) ||
//              (x == other.x && y == other.y && index < other.index);
//     } else {
//       return (y < other.y) || (y == other.y && x < other.x) ||
//              (x == other.x && y == other.y && index < other.index);
//     }
//   }
    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y > other.y);
    };
};


void solve_test_case() {
    get(n)
    vector<int> a(n), b(n);
    vector<Point<int>> points(n);
    loop(n) {
        cin >> a[i] >> b[i];
        points[i].x = a[i];
        points[i].y = b[i];
    }
    sort_v<Point<int>>(points);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int total = 0;
        int ip = i;
        while (ip < n && total < points[ip].x && points[ip].x == points[i].x) {
            ans += points[ip++].y;
            ++total;
        }
        while (ip < n && points[ip].x == points[i].x) {
            ip++;
        }
        i = ip - 1;
        // if (total == points[i].x) total = 0;
    }
    cout << ans << '\n';
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}
