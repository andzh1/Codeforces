#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        vector<long long> a;
        for(int i = 0; i < n; i++) if(s[i] == 'a') a.push_back(i);
        long long ans = INT32_MAX;
        if(a.size() <= 1) {
            cout << "-1\n";
            continue;
        }
        for(int i = 0; i < a.size() - 1; i++) {
            long long countB = 0, countC = 0;
            for(int x = a[i] + 1; x < a[i+1]; x++) {
                if(s[x] == 'b') countB++;
                if(s[x] == 'c') countC++;
            } 
            if(countB <= 1 && countC <= 1) ans = min(ans, a[i+1] - a[i] + 1);
        }  
        for(int i = 0; i < a.size() - 2; i++) {
            long long countB = 0, countC = 0;
            for(int x = a[i] + 1; x < a[i+2]; x++) {
                if(s[x] == 'b') countB++;
                if(s[x] == 'c') countC++;
            } 
            if(countB <= 2 && countC <= 2) ans = min(ans, a[i+2] - a[i] + 1);
        }    
        if(ans == INT32_MAX) cout << "-1\n";
        else cout << ans << '\n';
    }
}