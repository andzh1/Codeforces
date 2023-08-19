#include<bits/stdc++.h>

// using namespace std;

template<typename T>
struct SparceTable {
    std::vector<std::vector<T>> data_;

    SparceTable(const std::vector<T>& v) {
        int n = v.size();
        int logn = log2(n) + 1;
        data_ = std::vector<std::vector<int>>(logn + 1, std::vector<T>(n));
        data_[0] = v;
        for (int i = 1; i <= logn; ++i) {
            int pow = (1 << (i - 1));
            for (int j = 0; j + pow < n; ++j) {
                data_[i][j] = unique(data_[i - 1][j], data_[i - 1][j + pow]);
            }
        }
    }

    // [left, right]
    T GetAnswerOnSegment(int left, int right) const {
        int len = right - left + 1;
        if (len == 1) return data_[0][left];
        int pow = 0;
        while ((1 << (pow + 1)) < len) ++pow;
        T ans1 = data_[pow][left];
        T ans2 = data_[pow][right - (1 << pow) + 1];
        return unique(ans1, ans2);
    }    

    T unique(const T& first, const T& second) const {
        return std::min(first, second);
    }
};
