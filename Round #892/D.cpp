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


template <typename TContainer>
void sort(TContainer& v) {
  sort(all(v));
}

template <typename TContainer>
void rsort_v(TContainer& v) {
  sort(rall(v));
}

// template <typename AxisType = int>
// struct Point {
//   AxisType x = 0;
//   AxisType y = 0;
//   int index = 0;
//   bool first_compare_by_x_ = true;

//   explicit Point(AxisType x, AxisType y) : x(x), y(y) {}
//   explicit Point(AxisType x, AxisType y, bool cmp)
//       : x(x), y(y), first_compare_by_x_(cmp) {}
//   explicit Point(AxisType x, AxisType y, int index)
//       : x(x), y(y), index(index) {}
//   explicit Point(AxisType x, AxisType y, int index, bool cmp)
//       : x(x), y(y), index(index), first_compare_by_x_(cmp) {}

//   bool operator<(const Point& other) const {
//     if (first_compare_by_x_) {
//       return (x < other.x) || (x == other.x && y < other.y) ||
//              (x == other.x && y == other.y && index < other.index);
//     } else {
//       return (y < other.y) || (y == other.y && x < other.x) ||
//              (x == other.x && y == other.y && index < other.index);
//     }
//   }
// };

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

struct Portal {
    int left;
    int right;
    int a;
    int b;

    int index;
    bool operator<(const Portal& other) const {
        if (left != other.left) return left < other.left;
        if (right != other.right) return right < other.right;
        if (a != other.a) return a < other.a;
        if (b != other.b) return b < other.b;
        return index < other.index;
    }
};

struct Point {
    int index;
    int x;
    int type; // 100 - request, 1 - left edge of start, 2 - right edge of start, 3 - left edge of end, 4 - r edge of end

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        if (type != other.type) return type < other.type;
        return index < other.index;
    }

};

void getFarest(int start, vector<set<int>> &graph, vi &farest, vector<bool>& visited) {
    set<int> indexesOfLeafs;
    int n = graph.size();
    repeat(n) {

    }

}

void solve_test_case() {
    get(n)
    vector<Portal> portals (n);
    vector<Point> points;
    repeat(n) {
        get(left)
        get(right)
        get(a)
        get(b)

        portals[i] = {left, right, a, b};
        Point leftPoint, rightPoint;
        leftPoint.type = 1;
        leftPoint.x = left;
        leftPoint.index = i;

        rightPoint.type = 2;
        rightPoint.x = right;
        rightPoint.index = i;
        points.push_back(leftPoint);
        points.push_back(rightPoint);

        Point leftPoint2, rightPoint2;
        leftPoint2.type = 3;
        leftPoint2.x = a;
        leftPoint2.index = i;

        rightPoint2.type = 4;
        rightPoint2.x = b;
        rightPoint2.index = i;
        points.push_back(leftPoint2);
        points.push_back(rightPoint2);
    }

    get(q)

    repeat(q) {
        get(x)
        Point p;
        p.x = x;
        p.index = i;
        p.type = 100;
        points.push_back(p);
    }

    set<int> indexesOfOpenStarts;
    set<int> indexesOfOpenEnds;

    vector<vector<int>> graph (n, vi());
    vector<int> answer (q);

    vector<int> farest(n);
    repeat(n) {
        farest[i] = portals[i].b;
    }

    foreach(currentPoint, points) {
        int type = currentPoint.type;
        if (type == 1) {
            indexesOfOpenStarts.insert(currentPoint.index);
            foreach(index, indexesOfOpenEnds) {
                graph[index].push_back(currentPoint.index);
            }
            continue;
        }
        if (type == 2) {
            indexesOfOpenStarts.erase(currentPoint.index);
            continue;
        }

        if (type == 3) {
            indexesOfOpenEnds.insert(currentPoint.index);
            foreach(index, indexesOfOpenStarts) {
                graph[currentPoint.index].push_back(index);
            }
            continue;
        }
        if (type == 4) {
            indexesOfOpenEnds.erase(currentPoint.index);
            continue;
        }
    }


}


signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests --> 0) solve_test_case();
}

