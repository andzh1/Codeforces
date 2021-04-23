#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long n;
        cin >> n;
        if(n % 2050 == 0) {
            n /= 2050;
            int ans = 0;
            while(n > 0) {
                ans += n % 10; 
                n /= 10;
            }
            cout << ans << '\n';
        }
        else cout << "-1\n";
    }
}