#include <bits/stdc++.h>

using namespace std;
#define int64_t int;
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> in;
        vector<int> elements(n);
        for (int& el : elements) cin >> el;
        bool ans = false;
        for (int i = n - 1; i >= 0; --i) {
            if (in.find(elements[i]) != in.end()) {
                cout << i + 1 << '\n';
                ans = true;
                break;
            }
            in.insert(elements[i]);
        }
        if (!ans) {
            cout << "0\n";
        }
    }
}