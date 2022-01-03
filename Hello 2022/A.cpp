#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        if (n < 2*k - 1) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < n; ++i) {
                string ans;
                for (int j = 0; j < n; ++j) {
                    ans.push_back('.');
                }
                if (i % 2 == 0 && k > 0) {
                    ans[i] = 'R';
                    --k;
                }
                cout << ans << '\n';
            }
        }
    }
}