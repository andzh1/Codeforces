#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define get(a) int a; cin >> a;
#define loop(j, n) for(int j = 0; j < n; ++j)
#define iloop(n) loop(i, n)
#define jloop(n) loop(j, n)
#define kloop(n) loop(j, n)
#define fast_and_furious std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

// Created by AndZhi 03.02.2023

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

template<typename T = int>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template<typename T = int>
void print(const vector<vector<T>>& v) {
    for (const auto& x : v) print(x);
}

struct Data {
    int value;

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

    void AddOnSegmentHelper(const int& start, const int& left_edge, const int& right_edge, const Data& add_value) {
        if (data_[start].left == left_edge && data_[start].right == right_edge) {
            data_[start].this_data += add_value;
            return;
        }

        if (data_[2 * start].right >= right_edge) {
            AddOnSegmentHelper(2 * start, left_edge, right_edge, add_value);
            // data_[start].this_data = data_[2 * start].this_data + data_[2 * start + 1].this_data;
            return;
        }

        if (data_[2 * start + 1].left <= left_edge) {
            AddOnSegmentHelper(2 * start + 1, left_edge, right_edge, add_value);
            // data_[start].this_data = data_[2 * start].this_data + data_[2 * start + 1].this_data;
            return;
        }
        AddOnSegmentHelper(2 * start, left_edge, std::min(right_edge, data_[2 * start].right), add_value);
        AddOnSegmentHelper(2 * start + 1, std::max(left_edge, data_[2 * start + 1].left), right_edge, add_value);
        // data_[start].this_data = data_[2 * start].this_data + data_[2 * start + 1].this_data;
    }

    Data GetSegmentHelper(const int& start, const int& left_edge, const int& right_edge) const {
        if (data_[start].need_to_push && data_[start].left <= left_edge && data_[start].right >= right_edge) {
            return data_[start].to_push * (right_edge - left_edge + 1);
        }
        
        if (data_[start].left == left_edge && data_[start].right == right_edge) {
            return data_[start].this_data;
        }

        return GetSegmentHelper(2 * start, left_edge, std::min(right_edge, data_[2 * start].right)) 
             + GetSegmentHelper(2 * start + 1, std::max(left_edge, data_[2 * start + 1].left), right_edge);
    }

    Data GetElementHelper(const int& start, const int& index) {        
        if (data_[start].left == index && data_[start].right == index) {
            return data_[start].this_data;
        }

        auto ans = data_[start].this_data;

        int mid = data_[start * 2].right;
        if (index <= mid) return ans + GetElementHelper(2 * start, index);
        return ans + GetElementHelper(2 * start + 1, index);
    }

public:
    void UpdateSegment(const int& left_edge, const int& right_edge, const Data& new_value) {
        UpdateSegmentHelper(1, left_edge, right_edge, new_value);
    }

    Data GetSegment(const int& left_edge, const int& right_edge) const {
        return GetSegmentHelper(1, left_edge, right_edge);
    }

    Data GetElement(const int& index) {
        return GetElementHelper(1, index);
    }

    void AddOnSegment(const int& left_edge, const int& right_edge, const Data& new_value) {
        AddOnSegmentHelper(1, left_edge, right_edge, new_value);
    }

    void SetElement(const int& index, const Data& new_value) {
        UpdateSegmentHelper(1, index, index, new_value);
    }

};


int digit_sum(const int& x) {
    int y = x;
    int ans = 0;
    while (y > 0) {
        ans += y % 10;
        y /= 10;
    }
    return ans;
}

void solve_test_case() {
    get(n)
    get(q)
    auto a = read(n);
    int pp = 1;
    while (pp < n) pp *= 2;
    n = pp;
    a.resize(pp);
    vector<vector<int>> sums (n);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        sums[i].push_back(x);
        while (x > 9) {
            x = digit_sum(x);
            sums[i].push_back(x);
        }
        // reverse(sums[i].begin(), sums[i].end());
    }
    auto vvv = vector<Data>(n, {0});
    SegmentTree tree(vvv);
    while (q --> 0) {
        get(cur)
        if (cur == 1) {
            get(left)
            get(right)
            tree.AddOnSegment(left - 1, right - 1, {1});
        } else {
            get(index)
            auto val = tree.GetElement(index - 1).value;
            val = min(val, (int)sums[index - 1].size() - 1);
            cout << sums[index - 1][val] << '\n';
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
