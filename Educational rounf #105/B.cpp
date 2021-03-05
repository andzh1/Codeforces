#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    int edge[4];
    cin >> edge[0] >> edge[1] >> edge[2] >> edge[3];
    for(int a = 0; a < 2; a++) {
        for(int b = 0; b < 2; b++) {
            for(int c = 0; c < 2; c++) {
                for(int d = 0; d < 2; d++) {
                    int corner[4];
                    corner[0] = a;
                    corner[1] = b;
                    corner[2] = c;
                    corner[3] = d;
                    bool ans = true;
                    if(corner[0] + corner[1] > edge[0]) ans = false;
                    if(corner[1] + corner[2] > edge[1]) ans = false;
                    if(corner[2] + corner[3] > edge[2]) ans = false;
                    if(corner[3] + corner[0] > edge[3]) ans = false;
                    if(corner[0] + corner[1] < edge[0] - n + 2) ans = false;
                    if(corner[1] + corner[2] < edge[1] - n + 2) ans = false;
                    if(corner[2] + corner[3] < edge[2] - n + 2) ans = false;
                    if(corner[3] + corner[0] < edge[3] - n + 2) ans = false;
                    if(ans) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        bool ans = solve();
        ans? cout << "yes\n" : cout << "no\n";
    }
}