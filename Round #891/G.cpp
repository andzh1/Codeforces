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

vector<int> getPrefixSums(const vector<int>& ar) {
    if (ar.size() == 0) return vector<int>();
    vector<int> ans (ar.size(), ar[0]);
    for (int i = 1; i < ar.size(); ++i) {
        ans[i] = ans[i - 1] + ar[i];
    }
    return ans;
}

vector<int> getSuffixSums(const vector<int>& ar) {
    auto copy = ar;
    reverse(all(copy));
    auto ans = getPrefixSums(copy);
    reverse(all(ans));
    return ans;
}

struct Number {
    int index;
    int value;

    Number() = default;

    bool operator<(const Number& other) const {
        if (value != other.value) return value < other.value;
        return index < other.index;
    }
};


struct Edge {
    int start;
    int end;
    int weight;
};

struct Component {
    // vector<
};

const int MODULO = 998244353;

void dfs(int start, vector<set<Edge>>& graph, vector<bool>& visited, int maxAcceptableWeight, int& ans) {
    if (visited[start]) return;
    visited[start] = true;
    vector<Edge> toErase;
    for (auto& e: graph[start]) {
        if (e.weight > maxAcceptableWeight) {
            toErase.push_back(e);
        } 
    }
    for (auto& e: toErase) {
        graph[start].erase(e);
    }
    for (auto& e: graph[start]) {
        if (!visited[e.end]) {
            ans = max(ans, e.weight);
            dfs(e.end, graph, visited, maxAcceptableWeight, ans);
        } 
    }
}

void solve_test_case() {
    get(n)
    get(maxWeight)

    map<int, vector<Edge>> edges; // weight -> edge of such a weight
    map<int, map<int, int>> graph; // weight -> edge of such a weight
    set<int> weights;
    repeat(n - 1) {
        Edge e;
        cin >> e.start >> e.end >> e.weight;
        weights.insert(e.weight);
        edges[e.weight].push_back(e);
    }

    int freeEdges = (n - 2) * (n-1) / 2;
    int prevMax = maxWeight;
    int ans = 0;
    while (!weights.empty()) {
        int curmax = *(--weights.end());
        weights.erase(curmax);

        ans += (prevMax - maxWeight) * modpow(2, freeEdges, MODULO);
        ans %= MODULO;

        const vector<Edge>& curEdges = edges[curmax];
        set<int> nonAvaliableVertices;
        for (const Edge& e : curEdges) {
            nonAvaliableVertices.insert(e.start);
            nonAvaliableVertices.insert(e.end);
        }

        int k = nonAvaliableVertices.size();
        // int removedEdgesCount = k * (n - k)
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

