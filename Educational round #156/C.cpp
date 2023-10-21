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

// template <typename AxisType = int64_t>
// struct Point {
//   AxisType x = 0;
//   AxisType y = 0;
//   int64_t index = 0;
//   bool first_compare_by_x_ = true;

//   explicit Point(AxisType x, AxisType y) : x(x), y(y) {}
//   explicit Point(AxisType x, AxisType y, bool cmp)
//       : x(x), y(y), first_compare_by_x_(cmp) {}
//   explicit Point(AxisType x, AxisType y, int64_t index)
//       : x(x), y(y), index(index) {}
//   explicit Point(AxisType x, AxisType y, int64_t index, bool cmp)
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

char solve(string s, int64_t pos) {
    int64_t n = s.size();

    if (pos <= n) {
        return s[pos - 1];
    }

    vector<int64_t> str (n);
    for (int64_t i = 0; i < n; ++i) {
        str[i] = s[i] - 'a';
    }
    str.push_back(-1000);
    stack<int64_t> st;

    int64_t sz = n;
    for (int64_t ind = 0; ind <= n; ++ind) {
        if (st.empty()) {
            st.push(str[ind]);
            continue;
        }
        if (str[ind] >= st.top()) {
            st.push(str[ind]);
            continue;
        }
        while (!st.empty() && str[ind] < st.top()) {
            pos -= sz;
            st.pop();
            --sz;
            if (pos <= sz) {
                string res;
                while (!st.empty()) {
                    res.push_back((char)('a' + st.top()));
                    st.pop();
                }
                reverse(all(res));
                if (pos <= res.size()) {
                    return res[pos - 1];
                }
                pos -= res.size();
                return (char)('a' + str[ind + pos - 1]);
            }
        }
        st.push(str[ind]);
    }
    return '#';
}


void solve_test_case() {
    string s;
    cin >> s;
    get(pos)
    cout << solve(s, pos);
}

char dumb_solution(string s, int64_t pos) {
    if (pos <= s.size()) {
        return s[pos - 1];
    }
    int index = s.size() - 1;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] > s[i + 1]) {
            index = i;
            break;
        }
    }

    string new_s;
    for (int i = 0; i < index; ++i) new_s.push_back(s[i]);
    for (int i = index + 1; i < s.size(); ++i) new_s.push_back(s[i]);
    return dumb_solution(new_s, pos - s.size());

}

bool test_iter() {
    int sz = 4;
    string s;
    for (int i = 0; i < sz; ++i) {
        s.push_back('a' + rand() % 5);
    }
    int64_t n = s.size();
    for (int64_t pos = 1; pos <= n * (n + 1) / 2; ++pos) {
        auto dumb = dumb_solution(s, pos), mine = solve(s, pos);
        if (dumb != mine) {
            cout << "S = " << s << ", pos = " << pos << ", dumb = " << dumb << ", mine = " << mine << ".\n";
            return false;
        }
    }
    return true;
}

void test() {
    while(test_iter()) {}
}

signed main() {
    fast_and_furious
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int64_t tests = 1;
    cin >> tests;
    // test();
    while(tests --> 0) solve_test_case();
}

