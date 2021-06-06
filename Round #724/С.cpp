#include <bits/stdc++.h>
using namespace std;

#define  D first;
#define  K second;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        pair <int, int> prefix[n];
        prefix[0].first = 0;
        prefix[0].second = 0;
        if(s[0] == 'K') prefix[0].second = 1;
        if(s[0] == 'D') prefix[0].first = 1;
        for(int i = 1; i < n; i++) {
            prefix[i].first = prefix[i-1].first;
            prefix[i].second = prefix[i-1].second;
            if(s[i] == 'K') prefix[i].second ++;
            if(s[i] == 'D') prefix[i].first ++;
        }
        for(int i = 0; i < n; i++) {
            if(prefix[i].second == 0) prefix[i].first = 1;
            else if(prefix[i].first == 0) prefix[i].second = 1;
            else
            {
                int g = __gcd(prefix[i].second, prefix[i].first);
                prefix[i].second /= g;
                prefix[i].first /= g;
            } 
        }
        map <pair <int, int>, int> last;
        set <pair <int, int>> all;
        int ans[n];
        ans[0] = 1;
        last[prefix[0]] = 1;
        all.insert(prefix[0]);
        for(int i = 1; i < n; i++) {
            if(all.count(prefix[i]) == 0) {
                all.insert(prefix[i]);
                last[prefix[i]] = 1;
                ans[i] = 1;
            }
            else {
                last[prefix[i]]++;
                ans[i] = last[prefix[i]];
            }
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
}