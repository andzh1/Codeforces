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

const int64_t MOD = 998244353;

struct Data {
    int value = 0;

    // TODO: override for concrete case
    Data& operator+=(const Data& other) {
        value += other.value;
        return *this;
    }

    Data operator+(const Data& other) const {
        auto copy = *this;
        copy += other;
        return copy;
    }

    // TODO: override for concrete case
    Data operator*(const int& size) const {
        auto copy = *this;
        copy.value *= size;
        return copy;
    }
};

struct Node {
    int left;
    int right;
    bool need_to_push = false;
    Data to_push;
    Data this_data;
};

struct SegmentTree {
    std::vector<Node> data_;

    SegmentTree(const std::vector<Data>& new_data) {
        int n = new_data.size();
        data_.resize(2 * n);
        for (int i = n; i < 2 * n; ++i) {
            data_[i].this_data = new_data[i - n];
            data_[i].left = i - n;
            data_[i].right = i - n;
        }
        for (int i = n - 1; i > 0; --i) {
            data_[i].this_data = data_[2 * i].this_data + data_[2 * i + 1].this_data;
            data_[i].left = std::min(data_[2 * i].left, data_[2 * i + 1].left);
            data_[i].right = std::max(data_[2 * i].right, data_[2 * i + 1].right);
        }
    }

    size_t Size() const {
        return data_.size() / 2;
    }

private:
    void UpdateSegmentHelper(const int& start, const int& left_edge, const int& right_edge, const Data& new_value) {
        if (data_[start].left == left_edge && data_[start].right == right_edge) {
            data_[start].need_to_push = left_edge != right_edge;
            data_[start].to_push = new_value;
            data_[start].this_data = new_value * (right_edge - left_edge + 1);
            return;
        }

        if (data_[start].need_to_push) {
            data_[2 * start].need_to_push = true;
            data_[2 * start + 1].need_to_push = true;
            data_[2 * start].to_push = data_[start].to_push;
            data_[2 * start + 1].to_push = data_[start].to_push;
            data_[start].need_to_push = false;
        }

        if (data_[2 * start].right >= right_edge) {
            UpdateSegmentHelper(2 * start, left_edge, right_edge, new_value);
            data_[start].this_data = data_[2 * start].this_data + data_[2 * start + 1].this_data;
            return;
        }

        if (data_[2 * start + 1].left <= left_edge) {
            UpdateSegmentHelper(2 * start + 1, left_edge, right_edge, new_value);
            data_[start].this_data = data_[2 * start].this_data + data_[2 * start + 1].this_data;
            return;
        }
        UpdateSegmentHelper(2 * start, left_edge, std::min(right_edge, data_[2 * start].right), new_value);
        UpdateSegmentHelper(2 * start + 1, std::max(left_edge, data_[2 * start + 1].left), right_edge, new_value);
        data_[start].this_data = data_[2 * start].this_data + data_[2 * start + 1].this_data;
    }

    Data GetSegmentHelper(const int& start, const int& left_edge, const int& right_edge) const {
        if (data_[start].need_to_push && data_[start].left <= left_edge && data_[start].right >= right_edge) {
            return data_[start].to_push * (right_edge - left_edge + 1);
        }
        
        if (data_[start].left == left_edge && data_[start].right == right_edge) {
            return data_[start].this_data;
        }

        if (right_edge < data_[2 * start + 1].left) {
            return GetSegmentHelper(2 * start, left_edge, right_edge);
        }

        if (left_edge > data_[2 * start].right) {
            return GetSegmentHelper(2 * start + 1, left_edge, right_edge);
        }

        return GetSegmentHelper(2 * start, left_edge, std::min(right_edge, data_[2 * start].right)) 
             + GetSegmentHelper(2 * start + 1, std::max(left_edge, data_[2 * start + 1].left), right_edge);
    }

public:
    void UpdateSegment(const int& left_edge, const int& right_edge, const Data& new_value) {
        UpdateSegmentHelper(1, left_edge, right_edge, new_value);
    }

    Data GetSegment(const int& left_edge, const int& right_edge) const {
        return GetSegmentHelper(1, left_edge, right_edge);
    }

    void SetElement(const int& index, const Data& new_value) {
        UpdateSegmentHelper(1, index, index, new_value);
    }

};


void solve_test_case() {
    get(n)
    get(m)

    vector<int> factorial (n + 1);
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= MOD;
    }

    string s;
    cin >> s;
    int l = 0, r = 0;
    foreach(x, s) {
        if (x == '<') ++l;
        if (x == '>') ++r;
    }
    set<int> pos_of_mins;
    set<int> pos_of_maxs;
    int pow2n = 1;
    while (pow2n < n) pow2n *= 2;
    std::vector<Data> qes(pow2n);
    iloop(n - 1) {
        if (s[i] == '<') pos_of_mins.insert(i);
        if (s[i] == '>') pos_of_maxs.insert(i);
        if (s[i] == '?') qes[i].value = 1;
    }

    SegmentTree qs(qes);
    iloop(n - 1) {
        if (s[i] == '<') pos_of_mins.insert(i);
        if (s[i] == '>') pos_of_maxs.insert(i);
    }

    ++m;
    bool first = true;
    while (m --> 0) {
        if (!first) {
            get(pos)
            --pos;
            char ch;
            cin >> ch;
            if (s[pos] == '>') {--r; pos_of_maxs.erase(pos);}
            if (s[pos] == '<') {--l; pos_of_mins.erase(pos);}
            if (s[pos] == '?') {qs.UpdateSegment(pos, pos, {0});}
            if (ch == '>') {++r; pos_of_maxs.insert(pos);}
            if (ch == '<') {++l; pos_of_mins.insert(pos);}
            if (ch == '?') {qs.UpdateSegment(pos, pos, {1});}
            s[pos] = ch;
            first = false;
        }
        
        if (s[0] == '?') {
            cout << "0\n";
            continue;
        }
        auto& set_of_opposite = pos_of_mins;
        if (s[0] == '<') set_of_opposite = pos_of_maxs;

        int pos_of_first = n - 2;
        if (!set_of_opposite.empty()) {
            pos_of_first = *(set_of_opposite.begin());
        }
        int number_of_qs = qs.GetSegment(0, pos_of_first).value; // '?' between s[0] and s[pos_of_first]

        int64_t res = n - l - r - number_of_qs;
        res *= factorial[n - 1 - l - r];
        res %= MOD;
        // res *= modpow(n - l - r, MOD - 2, MOD);
        // res %= MOD;
        cout << res << '\n';
    }
}



signed main() {
    fast_and_furious
    freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int64_t tests = 1;
    // cin >> tests;
    while(tests --> 0) solve_test_case();
}

