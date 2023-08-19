#include<bits/stdc++.h>

// using namespace std;

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

signed main() {
    int n;
    std::cin >> n;
    std::vector<Data> data (n);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i].value;
    }
    SegmentTree segtree(data);

    int q;
    std::cin >> q;
    while (q --> 0) {
        int left, right;
        std::cin >> left >> right;
        Data new_data;
        std::cin >> new_data.value;
        segtree.UpdateSegment(left, right, new_data);
    }
}
