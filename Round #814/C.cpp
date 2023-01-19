#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

template<typename T = int>
vector<T> read(int n) {
    vector<T> v_to_read_in (n);
    for (int i = 0; i < n; ++i) cin >> v_to_read_in[i];
    return v_to_read_in;
}

template<typename T = int>
vector<vector<T>> read2(int n, int m) {
    vector<vector<T>> v_to_read_in(n, vector<T>(m));
    for (auto& v : v_to_read_in) {
        for (T& el : v) {
            cin >> v;
        }
    }
}

void solve_test_case() {
    int n, q;
    cin >> n >> q;
    auto power = read(n);
    deque<int> que;
    for (int i = 0; i < n; ++i) que.push_back(i);
    vector<vector<int>> wins(n);
    int cnt = 0;
    while(true) {
        ++cnt;
        int first = que.front(); que.pop_front();
        int second = que.front(); que.pop_front();
        if (power[first] == n) {--cnt; break;}
        if (power[first] > power[second]) {
            que.push_front(first);
            que.push_back(second);
            wins[first].push_back(cnt);
        } else {
            que.push_front(second);
            que.push_back(first);
            wins[second].push_back(cnt);
        }
    }
    for (int i = 0; i < q; ++i) {
        int player, n_of_moves;
        cin >> player >> n_of_moves;
        --player;
        if (n_of_moves >= cnt) {
            int ans = wins[player].size();
            if (power[player] == n) ans += max(0, n_of_moves - cnt);
            cout << ans << '\n';
            continue;
        }
        int ans = 0;
        for (; ans < wins[player].size(); ++ans) {
            if (wins[player][ans] > n_of_moves) break;
        }
        cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int number_of_tests = 1;
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> number_of_tests;
    while (number_of_tests--) solve_test_case();
}
