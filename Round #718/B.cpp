#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector <int> roads [n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int a;
                cin >> a;
                roads[i].push_back(a);
            }
            sort(roads[i].begin(), roads[i].end());
        }
        int answer [m][n];
        for(int i = 0; i < m; i++) {
            int ipmin, minim = INT32_MAX;
            for(int j = 0; j < n; j++) {
                if(roads[j][0] < minim) {
                    ipmin = j;
                    minim = roads[j][0];
                }
            }
            for(int j = 0; j < n; j++) {
                if(j == ipmin) {
                    // cout << roads[j][0] << " ";
                    answer[i][j] = roads[j][0];
                    sort(roads[j].rbegin(), roads[j].rend());
                    roads[j].pop_back();
                    sort(roads[j].begin(), roads[j].end());
                }
                else {
                    answer[i][j] = roads[j][roads[j].size() - 1];
                    roads[j].pop_back();
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << answer[j][i] << " ";
            }
            cout << '\n';
        }
    }
}