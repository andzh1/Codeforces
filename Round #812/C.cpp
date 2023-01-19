#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

bool is_square(int x) {
    int y = sqrt(x);
    return x == y*y;
}

int closest_square(int x) {
    if (is_square(x)) return x;
    int y = sqrt(x);
    return (y + 1) * (y + 1);
}

std::vector<int> answer;

void solve(int n) {
    if (n == 0) return;
    if (n == 1) {
        answer.push_back(0);
        return;
    }
    if (n == 2) {
        answer.push_back(1);
        answer.push_back(0);
        return;
    }
    // if (n == 3) return std::vector<int>({1, 0, 2});
    int x = closest_square(n - 1);
    if (x >= 2*n - 1) {
        answer.push_back(-1);
        return;
    }
    solve(x - n + 1);
    if (answer.size() == 1 && answer[0] == -1) return;
    for (int i = n - 1; i >= x - n + 1; --i) answer.push_back(i);
    // return suffix;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    // int T;
    // cin >> T;
    // while (T--) {
    //     int n;
    //     cin >> n;
    //     answer.clear();
    //     solve(n);
    //     for (auto a : answer) cout << a << ' ';
    //     cout << '\n';
    // }
    vector<bool> x (1 << 17);
}