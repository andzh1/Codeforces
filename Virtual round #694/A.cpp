#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, x;
        cin >> n >> x;
        long long ans = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
            ans += a/x;
            if(a%x != 0) ans ++;
        }
        (sum % x == 0)? cout << sum/x : cout << sum/x + 1;

        cout << " " << ans << '\n';
    }
}