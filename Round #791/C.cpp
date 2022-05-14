#include <bits/stdc++.h>

struct SegTree
{
    struct Node
    {
        int number = 0;
        bool fully_covered = false;
        int64_t left_edge;
        int64_t right_edge;
    };
    
    std::vector<Node> data;
    int64_t size;

    SegTree(int64_t sz): size(sz) {
        data.resize(2 * size);
        for (int64_t i = size; i < 2 * size; ++i) {
            data[i].left_edge = i - size;
            data[i].right_edge = i - size;
        }
        for (int64_t i = size - 1; i > 0; --i) {
            data[i].left_edge = data[2 * i].left_edge;
            data[i].right_edge = data[2 * i + 1].right_edge;
        }
    }

    void update(int64_t index, int val) {
        if (val) {
            data[index + size].number++;
            data[index + size].fully_covered = true;
        } else {
            data[index + size].number--;
            if (data[index + size].number == 0) {
                data[index + size].fully_covered = false;
            }
        }
        index = (index + size) / 2;
        while (index > 0) {
            bool new_val = data[index * 2].fully_covered 
                                     && data[index * 2 + 1].fully_covered;
            if (new_val == data[index].fully_covered) break;
            data[index].fully_covered = new_val;
            index /= 2;
        }
    }

    bool get_ans(int64_t root, int64_t left, int64_t right) {
        if (data[root].left_edge == left && data[root].right_edge == right) return data[root].fully_covered;
        if (root > size) return data[root].fully_covered;
        if (right <= data[root * 2].right_edge) return get_ans(root * 2, left, right);
        if (left >= data[root * 2 + 1].left_edge) return get_ans(root * 2 + 1, left, right);
        return get_ans(root * 2, left, data[root * 2].right_edge) 
            && get_ans(root * 2 + 1, data[root * 2 + 1].left_edge, right);
    }
    
};

using std::cin; 
using std::cout;

int64_t min_pow_of_2(int64_t n) {
    int64_t ans = 1;
    while (ans < n) ans *= 2;
    return ans;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int64_t n, q;
    std::cin >> n >> q;
    n = min_pow_of_2(n);
    SegTree y_tree(n), x_tree(n);
    while (q--) {
        int64_t t;
        std::cin >> t;
        if (t == 3) {
            int64_t x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            bool ans = x_tree.get_ans(1, x1 - 1, x2 - 1);
            ans |= y_tree.get_ans(1, y1 - 1, y2 - 1);
            (ans)? std::cout << "Yes" : std::cout << "No";
            std::cout << std::endl;
        } else {
            int64_t x, y;
            std::cin >> x >> y;
            --x; --y;
            y_tree.update(y, 2 - t);
            x_tree.update(x, 2 - t);
        }
    }
    
}