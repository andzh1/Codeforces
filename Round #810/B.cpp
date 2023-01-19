#include <bits/stdc++.h>

using namespace std;
// #define int64_t int64_t;
signed main() {
    int64_t T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        vector<int64_t> sadness(n);
        for (int64_t& a : sadness) cin >> a;
        vector<pair<int64_t, int64_t>> friendships (m);
        vector<pair<int64_t, int64_t>> degree_and_index(n, {0, 0});
        for (int64_t i = 0; i < n; ++i) {
            degree_and_index[i].second = i;
        }
        for (auto& f: friendships) {
            cin >> f.first >> f.second;
            --f.first;
            --f.second;
            ++degree_and_index[f.first].first;
            ++degree_and_index[f.second].first;
        }
        if (m % 2 == 0) {
            cout << "0\n";
            continue;
        }
        vector<int64_t> smallest_friend(n, INT32_MAX);
        for (int64_t i = 0; i < m; ++i) {
            if (degree_and_index[friendships[i].first].first % 2 == 0 && degree_and_index[friendships[i].second].first % 2 == 0) {
                smallest_friend[friendships[i].first] = min(smallest_friend[friendships[i].first], sadness[friendships[i].second]);
                smallest_friend[friendships[i].second] = min(smallest_friend[friendships[i].second], sadness[friendships[i].first]);
            }
        }
        sort(degree_and_index.begin(), degree_and_index.end());
        pair<int64_t, int64_t> vertice_to_erase = {INT32_MAX, -1};
        for (int64_t i = 0; i < n; ++i) {
            auto din = degree_and_index[i];
            if (din.first % 2 && sadness[vertice_to_erase.second] > sadness[din.second]) {
                vertice_to_erase = din;
            }
        }        
        int64_t answer = (vertice_to_erase.second != -1)? sadness[vertice_to_erase.second] : INT32_MAX;
        for (auto din : degree_and_index) {
            if (din.first % 2) {
                continue;
            } 
            answer = min(answer, sadness[din.second] + smallest_friend[din.second]);
        }
        cout << answer << '\n';
    }
}