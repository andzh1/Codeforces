#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int ans = 0;
        int a; cin >> a;
        for(int i = 1; i < n; i++) {
            int b;
            cin >> b;
            int mi = 2*min(a, b);
            int ma = max(a, b);
            while(mi < ma) {
                mi *= 2;
                ans ++;
            }
            a = b;
        }
        cout << ans << '\n';
    }
}