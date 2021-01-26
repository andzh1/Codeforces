#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, k;
        cin >> a >> b >> k;
        pair <int, int> possible[k];
        int m[a], d[b];
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            possible[i].first = x;
        }
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            possible[i].second = x;
        }
        
        sort(possible, possible + k);
        for(int i = 0; i  < a; i++) m[i] = 0;
        for(int i = 0; i  < b; i++) d[i] = 0;
        for(int i = 0; i < k; i++){
            m[possible[i].first - 1] ++;
            d[possible[i].second - 1] ++;
        }
        long long ans = 0;

        for(int i = 0; i < k; i++){
            ans += (k - m[possible[i].first - 1] - d[possible[i].second - 1] + 1);
        }
        cout << ans/2 << '\n';
    }
}