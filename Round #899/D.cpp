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

struct Edge {
    int start;
    int finish;

    bool operator<(const Edge& other) const {
        if (start != other.start) return start < other.start;
        return finish < other.finish;
    }
};

struct ResultOfDfs {
    int cost = -1;
    int size_of_subtree = 0;
};

ResultOfDfs dfs(const Edge& current_edge, vector<vector<int>>& graph, vector<map<int, ResultOfDfs>>& cashed_result, vector<int>& cost_of_vertice) {
    auto cashed = cashed_result[current_edge.start][current_edge.finish];
    if (cashed.cost != -1) return cashed;

    if (graph[current_edge.finish].size() == 1) {
        // finish is a list
        ResultOfDfs res;
        res.cost = cost_of_vertice[current_edge.start] ^ cost_of_vertice[current_edge.finish];
        res.size_of_subtree = 1;
        cashed_result[current_edge.start][current_edge.finish] = res;
        return res;
    }

    ResultOfDfs result;
    result.cost = 0;
    for (int next: graph[current_edge.finish]) {
        if (next == current_edge.start) continue;
        auto res = dfs({current_edge.finish, next}, graph, cashed_result, cost_of_vertice);
        result.size_of_subtree += res.size_of_subtree;
        result.cost += res.cost;
    }
    result.size_of_subtree += 1;
    result.cost += result.size_of_subtree * (cost_of_vertice[current_edge.start] ^ cost_of_vertice[current_edge.finish]);

    cashed_result[current_edge.start][current_edge.finish] = result;
    return result;
}

void solve_test_case() {
    get(n)
    auto cost_of_vertice = read(n);
    
    vector<vector<int>> graph(n);
    vector<map<int, ResultOfDfs>> cashed_result (n + 1); // cashed_result[s][f] = cost of equalizing subtree of s with vertice f

    vector<Edge> edges;
    iloop(n - 1) {
        get(s)
        get(f)
        --s;
        --f;
        graph[s].push_back(f);
        graph[f].push_back(s);
        edges.push_back({s, f});
        edges.push_back({f, s});
        cashed_result[s][f].cost = -1;
        cashed_result[f][s].cost = -1;
    }

    foreach(edge, edges) {
        dfs(edge, graph, cashed_result, cost_of_vertice);
    }
    
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (auto& next : graph[i]) {
            ans += cashed_result[i][next].cost;
        }

        cout << ans << ' ';
    }
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

