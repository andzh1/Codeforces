#include <bits/stdc++.h>

using namespace std;

#define vi vector<int64_t>
#define get(a) int64_t a; cin >> a;
#define repeat(n) for(int64_t wertyu = 0; wertyu < n; ++wertyu)
#define loop(j, n) for(int64_t j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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

void print_2_3(int p, int q) {
    // p/q <= 2/3
    p *= 2;
    q *= 2;
    cout << 1 << ' ' << q << '\n';
    repeat(p/2) {
        cout << "##.";            
    }
    for (int i = 0; i < q - 3 * p / 2; ++i) {
        cout << ".";
    }
    cout << '\n';
    return;
}

void test_iteration() {

}

template<typename T>
struct Optional {
public:
    Optional(T&& x): value(std::move(x)), is_set(true) {}
    Optional(const T& x): value(x), is_set(true) {}
    Optional() = default;
    static Optional nullopt() {
        return Optional();
    }
private:
    T value;
    bool is_set = false;
};

Optional<vector<string>> solve(int p, int q) {
    if (p == q) {
        return Optional<vector<string>>::nullopt();
    }
    if (p == 0) {
        return Optional<vector<string>>(vector<string>({"."}));
    }
    
    if (p == 1) {
        return Optional<vector<string>>::nullopt();
    }

    if (3 * p <= 2 * q) {
        p *= 2;
        q *= 2;
        cout << 1 << ' ' << q << '\n';
        string ans;
        repeat(p/2) {
            ans += "##.";            
        }
        for (int i = 0; i < q - 3 * p / 2; ++i) {
            ans += ".";
        }
        return Optional<vector<string>>({ans});
    }

    if (10 * p == 7 * q) {
        vector<string> ans;
        ans.push_back(".###.");
        ans.push_back(".###.");
        ans.push_back("##.##");
        ans.push_back("##.##");
        return Optional<vector<string>>(ans);
    }

    return Optional<vector<string>>::nullopt();
    // 3/4, 4/5, 5/6, 6/7, 7/8, 8/9, 9/10
    //           5/7, 6/7, 7/8, 7/9, 7/10, 8/9, 9/10
}

void solve_test_case() {
    get(p)
    get(q)
    
    if (p == q) {
        cout << "-1 -1\n";
        return;
    }
    if (p == 0) {
        cout << "1 1\n";
        cout << ".\n";
        return;
    }
    
    if (p == 1) {
        cout << "-1 -1\n";
        return;
    }

    if (3 * p <= 2 * q) {
        print_2_3(p, q);
        return;
    }

    if (10 * p == 7 * q) {
        cout << "4 5\n";
        cout << ".###.\n";
        cout << ".###.\n";
        cout << "##.##\n";
        cout << "##.##\n";
        return;
    }

    cout << "-1 -1\n";
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int64_t tests = 1;
    // cin >> tests;
    while(tests --> 0) solve_test_case();
}

