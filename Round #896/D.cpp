#include <bits/stdc++.h>

using namespace std;

#define vi vector<int64_t>
#define get(a) int64_t a; cin >> a;
#define repeat(n) for(int64_t i = 0; i < n; ++i)
#define loop(j, n) for(int64_t j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define foreach(val, container) for (const auto& val : container)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

int64_t modpow(const int64_t& x, const int64_t& power, const int64_t& mod) {
    if (power == 0) return 1;
    if (power == 1) return x;
    int64_t sqrt = modpow(x, power / 2, mod);
    sqrt *= sqrt;
    sqrt %= mod;
    if (power % 2) sqrt *= x;
    sqrt %= mod;
    return sqrt;
}


template<typename T = int64_t>
vector<T> read(int64_t n) {
    vector<T> v (n);
    for (T& x : v) cin >> x;
    return v;
}

template<typename T = int64_t>
vector<vector<T>> read(int64_t n, int64_t m) {
    vector<vector<T>> v (n, vector<T> (m));
    for (auto& x : v) x = read<T>(n);
    return v;
}


template<typename T>
void print(const T& v) {
    cout << v << ' ';
    cout << '\n';
}

template<typename T = int64_t>
void print(const vector<T>& v) {
    for (const auto& x : v) print(x);
    cout << '\n';
}

template<typename T = int64_t>
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

template <typename AxisType = int64_t>
struct Point {
  AxisType x = 0;
  AxisType y = 0;
  int64_t index = 0;
  bool first_compare_by_x_ = true;

  explicit Point(AxisType x, AxisType y) : x(x), y(y) {}
  explicit Point(AxisType x, AxisType y, bool cmp)
      : x(x), y(y), first_compare_by_x_(cmp) {}
  explicit Point(AxisType x, AxisType y, int64_t index)
      : x(x), y(y), index(index) {}
  explicit Point(AxisType x, AxisType y, int64_t index, bool cmp)
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
    int64_t index = 0;

    explicit CustomComparablePair(first_t x, second_t y) : first(x), second(y) {}
    explicit CustomComparablePair(first_t x, second_t y, int64_t index)
        : first(x), second(y), index(index) {}

    CustomComparablePair() = default;

    virtual bool operator<(const CustomComparablePair& other) const = 0;
};

template<typename first_t = int64_t, typename second_t = int64_t>
struct MyPoint: public CustomComparablePair<first_t, second_t> {
    using CustomComparablePair<first_t, second_t>::CustomComparablePair;


    bool operator<(const CustomComparablePair<first_t, second_t>& other) const override {
        const MyPoint& otherPoint = static_cast<const MyPoint&>(other);
        return (this->first < otherPoint.first) || 
               (this->first == otherPoint.first && this->second < otherPoint.second) ||
               (this->second == otherPoint.second && this->first == otherPoint.first && this->index < otherPoint.index);
    }
};

using two_int_t = MyPoint<int64_t, int64_t>;

const int IMPOSSIBLE = -22;

struct Powers {
    int plus;
    int minus;

    Powers(int m, int p): minus(m), plus(p) {

    }
};

Powers getRequiredPowers(int64_t current, int64_t target) {
    int64_t maxpow = log2(max(current, target)) + 1;
    for (int64_t plus = 0; plus <= maxpow; ++plus) {
        if (current + (1ull << plus) == target) {
            return (Powers(-1, plus));
        }
    }
    for (int64_t minus = 0; minus <= maxpow; ++minus) {
        if (current == (1ull << minus) + target) {
            return (Powers(minus, -1));
        }
    }
    if (current == target) {
        return (Powers(-1, -1));
    }

    for (int64_t minus = 0; minus <= maxpow; ++minus) {
        for (int64_t plus = 0; plus <= maxpow; ++plus) {
            if (plus == minus) continue;
            if (current + (1ull << plus) == target + (1ull << minus)) {
                return (Powers(minus, plus));
            }
        }   
    }
    return Powers(IMPOSSIBLE, IMPOSSIBLE);
}

struct Vertice {
    int value;
    int index;

    Vertice(int a, int b): value(a), index(b) {}
    bool operator<(const Vertice& other) const {
        if (value != other.value) return value < other.value;
        return index < other.index;
    }
};

void solve_test_case() {
    get(n)
    auto v = read(n);

    int64_t target = 0;
    foreach(x, v) target += x;
    if (target % n != 0) {
        cout << "No\n";
        return;
    }
    target /= n;
    vector<int> toAdd (100), toRemove (100);
    vector<int> can_be_replaced_add (100); // if we have {-1, 3}, we can also do {3, 4}
    vector<int> can_be_replaced_remove (100); // if we have {-1, 3}, we can also do {3, 4}
    iloop(n) {
        auto cur = getRequiredPowers(v[i], target);
        if (cur.minus == IMPOSSIBLE) {
            cout << "No\n";
            return;
        }

        if (cur.minus == -1 && cur.plus == -1) continue;
        if (cur.minus != -1) {
            toRemove[cur.minus]++;
        } else {
            toAdd[cur.plus]++;
            can_be_replaced_add[cur.plus]++;
            continue;
        }
        if (cur.plus != -1) {
            toAdd[cur.plus]++;
        } else {
            toRemove[cur.minus]++;
            can_be_replaced_remove[cur.minus]++;
            continue;
        }
    }

    int index = 0; 
    while (index < 70) {

        if ((toAdd[index] + toRemove[index]) % 2) {
            cout << "No\n";
            return;
        }
        int diff = abs(toAdd[index] - toRemove[index]) / 2;

        if (toAdd[index] > toRemove[index]) {
            can_be_replaced_remove[index] -= diff;
            if (can_be_replaced_remove[index] < 0) {
                cout << "No\n";
                return;
            }
            toAdd[index + 1] += diff;
        } else if (toAdd[index] < toRemove[index]) {
            can_be_replaced_add[index] -= diff;
            if (can_be_replaced_add[index] < 0) {
                cout << "No\n";
                return;
            }

            toRemove[index + 1] += diff;
        }
        ++index;
    }
    cout << "Yes\n";
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int64_t tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}

