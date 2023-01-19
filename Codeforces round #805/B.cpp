#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
    int T = INT64_MAX;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int ip = 0, cnt = 0, ans = 1;
        set<char> current_in;
        while (ip < s.size()) {
            if (cnt == 3 && current_in.find(s[ip]) == current_in.end()) {
                ++ans;
                current_in.clear();
                current_in.insert(s[ip]);
                cnt = 1;
                ++ip;
                continue;
            }
            if (current_in.find(s[ip]) == current_in.end()) {
                current_in.insert(s[ip]);
                ++cnt;
            } 
            ++ip;

        }
        cout << ans << '\n';
    }
}