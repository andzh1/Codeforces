#include <bits/stdc++.h>

using namespace std;


signed main() {
    int64_t T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        string s, t;
        cin >> s >> t;   
        bool succeed = true;
        int last_b = -1, last_a = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;
            if (s[i] == 'b' && t[i] == 'c') {
                int ip = max(i, last_b);
                while (ip < n && s[ip] == 'b') ++ip;
                if (ip == n || s[ip] == 'a') {
                    succeed = false; break;
                }
                swap(s[ip], s[i]); 
                last_b = ip; 
                continue;
            }
            if (s[i] == 'a' && t[i] == 'b') {
                int ip = max(i, last_a);
                while (ip < n && s[ip] == 'a') ++ip;
                if (ip == n || s[ip] == 'c') {
                    succeed = false; break;
                }
                swap(s[ip], s[i]);
                last_a = ip; 
                continue;
            }
            succeed = false; break;
        }
        if (succeed) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }
    }
}