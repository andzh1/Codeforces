#include <bits/stdc++.h>

using namespace std;
// #define int64_t int64_t64_t

void dfs(int start, int parent, vector<vector<int>>& graph, vector<int>& colors) {
    if (colors[start]) return;
    colors[start] = 3 - colors[parent];
    for (auto next : graph[start]) {
        dfs(next, start, graph, colors);
    }
}

signed main() {
    int64_t T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n, vector<int>());
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
            edges.push_back({a-1, b-1});
        }
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() > 2) {
                ans = false;
                break;
            }
        }
        if (!ans) {
            cout <<"NO\n";
            continue;
        }
        vector<int> colors(n+1, 0);
        colors[n] = 1;
        for (int i = 0; i < n; ++i) {
            dfs(i, n, graph, colors);
        }
        for (auto e : edges) {
            if(colors[e.first] == colors[e.second]) {
                ans = false;
                break;
            }
        }
        cout << (ans? "YES\n" : "NO\n");
    }
}