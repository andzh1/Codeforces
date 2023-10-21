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

int xorVec(vector<int>& a, vector<int>& b) {
    int ans = 0, orrer = 0;
    foreach(x, b) {orrer |= x;}
    foreach(x, a) {ans ^= (x | orrer);}
    return ans;
}

int xorVec(vector<int>& a) {
    int ans = 0;
    foreach(x, a) {ans ^= x;}
    return ans;
}

struct Update {
    int cost;
    int index;

    bool operator<(const Update& other) const {
        if (cost != other.cost) return cost < other.cost;
        return index > other.index;
    }
};

struct UsedUpdate {
    int count;
    Update update;

    int totalCost(int newCost) const {
        return count * (newCost - update.cost);
    }

    bool operator<(const UsedUpdate& other) const {
        if (update.index != other.update.index) return update.index < other.update.index;
        return update.cost < other.update.cost; // all costs are different
    }

};


void solve_test_case() {
    get(n)
    auto a = read(n);
    get(k)

    vector<Update> updates;
    map<int, int> index_of_cost; // cost -> latest index in a
    iloop(n) {
        index_of_cost[a[i]] = i;
    }
    for (auto& [cost, index]: index_of_cost) {
        updates.push_back({cost, index});
    }

    sort(all(updates));
    vector<UsedUpdate> used (1);
    used.reserve(n);
    vector<int> answer (n);
    int base_number = k / updates[0].cost;
    int base_cost = updates[0].cost;
    for(int i = 0; i <= updates[0].index; ++i) {
        answer[i] = base_number;
    }
    int remains = k % updates[0].cost;
    int farest_index = updates[0].index;
    used[0].update = updates[0];
    used[0].count = base_number;


    for (int start = 1; start < updates.size(); ++start) {
        auto update = updates[start];
        if (update.index <= farest_index) continue;
        int cntOfNewUpdate = 0;
        while (remains && !used.empty()) {
            int diff = update.cost - used.back().update.cost;
            int number_of_changed = min(used.back().count, remains / diff);
            cntOfNewUpdate += number_of_changed;
            used.back().count -= number_of_changed;
            remains -= number_of_changed * diff;
            if (used.back().count == 0) {
                used.pop_back();
            } else {
                break;
            }
        }
        if (cntOfNewUpdate) {
            UsedUpdate cur;
            cur.update = update;
            cur.count = cntOfNewUpdate;
            used.push_back(cur);
            farest_index = update.index;
        }
    }

    int sum = 0;
    foreach(x, used) {
        sum += x.count;
    }
    int last_index = -1;
    for (int i = 0; i < used.size(); ++i) {
        for (int j = last_index + 1; j <= used[i].update.index; ++j) {
            answer[j] = sum;
        } 
        last_index = used[i].update.index;
        sum -= used[i].count;
    }

    foreach(x, answer) cout << x << ' ';
    cout << '\n';
}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}

