#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
    int T = INT64_MAX;
    cin >> T;
    while(T--) {
        vector<vector<int>> in (2, vector<int>(2));
        bool all1 = true;
        bool all0 = true;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> in[i][j];
                all1 &= in[i][j];
                all0 &= !in[i][j];
            }
        }
        if (all0) {
            cout << "0\n";
            continue;
        }
        if (all1) {
            cout << "2\n";
            continue;
        }
        cout << "1\n";

    }
}