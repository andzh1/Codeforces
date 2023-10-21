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

int last_move(vector<int>& a, vector<int>& b) {
    int min_a = a.back(), max_a = a[0], min_b = b.back(), max_b = b[0];
    if (min_a >= max_b) {
        return sum(a);
    }
    return sum(a) + max_b - min_a; // ok
}

void solve_test_case() {
    get(n)
    get(m)
    get(k)
    auto a = read(n);
    auto b = read(m);
    sort(rall(a));
    sort(rall(b));

    if (k % 2 == 1) {
        cout << last_move(a, b) << '\n';
    } else {
        if (a[n - 1] < b[0]) swap(a[n - 1], b[0]);
        sort(rall(a));
        sort(rall(b));
        cout << sum(a) + sum(b) - last_move(b, a) << '\n';
    }   
}

int solution(const vector<int>& input_a, const vector<int>& input_b, int k) {
    vector<int> a = input_a;
    vector<int> b = input_b;
    sort(rall(a));
    sort(rall(b));

    int n = a.size();
    if (k % 2 == 1) {
        return last_move(a, b);
    } else {
        if (a[n - 1] < b[0]) swap(a[n - 1], b[0]);
        sort(rall(a));
        sort(rall(b));
        return sum(a) + sum(b) - last_move(b, a);
    }   
}

int test_res(const vector<int>& input_a, const vector<int>& input_b, int k) {
    map<int, int> a, b;
    foreach(x, input_a) a[x]++;
    foreach(x, input_b) b[x]++;

    bool swap_after = (k % 2 == 1);
    while (k --> 0) {
        int min_a = a.rbegin()->first, max_a = a.begin()->first, min_b = b.rbegin()->first, max_b = b.begin()->first;
        if (min_a < max_b) {
            a[min_a]--;
            b[max_b]++;
        }
        swap(a, b);
    }

    if (swap_after) swap(a, b);
    int sum = 0;
    for (auto& [val, number]: a) {
        sum += val * number;
    }

    return sum;
}

bool single_test() {
    int n = 1 + rand() % 5;
    int m = 1 + rand() % 7;

    int k = 1 + rand() % 50;

    vector<int> a(n), b(m);

    int max_val = 10;
    for (auto& x : a) {
        x = rand() % max_val;
    }

    for (auto& x : b) {
        x = rand() % max_val;
    }
    int test = test_res(a, b, k);
    int sol = solution(a, b, k);
    if (test != sol) {
        cout << "Error!!!\na is: ";
        foreach(x, a) cout << x << ' ';
        cout << "\nb is: ";
        foreach(x, b) cout << x << ' ';
        cout << "\nk is " << k <<", test result is " << test << ", solution is " << sol << '\n';
        return false;
    }
    return true;
}

void test() {
    while (single_test()) {}
}

signed main() {
    fast_and_furious
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
    // test();
}

