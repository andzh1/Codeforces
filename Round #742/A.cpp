#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = s;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'U') ans[i] = 'D';
            if(s[i] == 'D') ans[i] = 'U';
        }
        cout << ans << endl;
    }
}