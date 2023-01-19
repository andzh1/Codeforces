#include <bits/stdc++.h>
using namespace std;


signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) {
        string n;
        cin >> n;
        vector<char> n_as_ch;
        for (auto ch : n) n_as_ch.push_back(ch);
        sort(n_as_ch.begin(), n_as_ch.end());
        // cout << n;
        if (n_as_ch[0] == n_as_ch[1]) {
            cout << n_as_ch[0] << '\n';
            continue;
        }
        if (n.size() == 2) {
            cout << n[1] << '\n';
            continue;
        }
        cout << n_as_ch[0] << '\n';

    }
}
